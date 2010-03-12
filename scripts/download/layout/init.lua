-- ============================================================================
-- Download dialog layouts
--     This file contains utility functions for download layouts
--     The rest of this directory contains the actual layouts
-- ============================================================================

-- These functions can only be called after the download dialog has been
-- created.

require 'download.ctrl'
require 'date'

download.layout = {}

local P = download
local layout = P.layout

layout.layouts = {}

-- Return today with no time
function layout.today()
    local d = date()
    d.dayfrc = 0 -- clear the time
    return d
end

-- Register a layout with a name, and function, and arguments.
-- The function must take start_date as the first parameter.
-- Any other parameters are entirely up to the user
function layout.addLayout(name, func, ...)
    table.insert(layout.layouts, { name = name, func = func, args = arg })
    layout.layouts[name] = { name = name, func = func, args = arg }
end


-- Create a menu for switching layouts
function layout.createMenu()
    local dlg = assert(P.dlg)
    local menu = wx.wxMenu()
        for _, l in ipairs(layout.layouts) do
            local item = menu:AppendRadioItem(wx.wxID_ANY, l.name)
            dlg:Connect(item:GetId(), wx.wxEVT_COMMAND_MENU_SELECTED,
                function(evt)
                    layout.setLayout(l.func, nil, unpack(l.args))
                end)
        end
    return menu
end


-- Create a single download ctrl, adding it to the download dialog's
-- list of downloads if it does not already exist.
function layout.createDownloadCtrl(source, d)
    local dlg = assert(P.dlg)
    if not dlg.downloads[source.display] then
        dlg.downloads:addsource(source.display)
    end
    local dl = dlg.downloads[source.display][d]
    -- Download does not exist; create it.
    if not dl then
        dl = P.DownloadCtrl(dlg.panel, source, d)
        dlg.downloads[source.display][d] = dl
    end
    -- Add the download to the various downloads list.
    table.insert(dlg.downloadslist, dl)
    table.insert(dlg.pendingdownloads, dl)
end


--[[
Create and return a list of DownloadCtrls.

Parameters:
    createDownloadCtrls([sources], [start_date], [end_date])
        sources
            <a single source> OR <a table of download sources>
            Default: all sources.
        start_date (inclusive)
            <date>
            Default: last week
        end_date (inclusive)
            <date>
            Default: today
]]
function layout.createDownloadCtrls(...)
    local dlg = assert(P.dlg)

    local sources, start_date, end_date

    -- Figure out which parameters we got

    -- All args
    if #arg >= 3 then
        sources, start_date, end_date = unpack(arg)
    elseif #arg == 2 then
        -- start_date, end_date
        if arg[1].daynum then -- arg[1] is a date
            start_date, end_date = unpack(arg)
        -- sources, start_date
        else
            sources, start_date = unpack(arg)
        end
    elseif #arg == 1 then
        -- start_date
        if arg[1].daynum then -- arg[1] is a date
            start_date = unpack(arg)
        -- sources
        else
            sources = unpack(arg)
        end
    end

    -- Defaults
    sources = sources or P.sources
    if not start_date then
        start_date = layout.today()
        start_date:adddays(-7)
    end
    end_date = end_date or layout.today()

    -- Make sure sources is a table of sources
    if sources.display then  -- sources is a single source
        sources = { sources }
    end

    -- Create all the matching downloads
    for _, source in ipairs(sources) do
        local d = start_date:copy()
        while d <= end_date do
            layout.createDownloadCtrl(source, d)
            d:adddays(1) -- Next day
        end
    end
end


-- Destroy old download ctrls and remove them from dlg.downloads.
-- New ctrls are those that are present in both dlg.downloadslist and
-- dlg.downloads (i.e. they have been created since the last call to
--  layout.setLayout()
-- The layout function may call this function after creating all download ctrls.
function layout.cleanDownloadCtrls()
    -- Create a reverse download ctrl table { [dl] = idx }
    local ctrls = {}
    for k, v in pairs(P.dlg.downloadslist) do ctrls[v] = k end

    -- Find all the extra download ctrls
    for _, dls in pairs(P.dlg.downloads) do
        for dl_date, dl in pairs(dls) do
            if not ctrls[dl] then
                print("Destroying", dl.ctrl)
                dl.ctrl:Destroy()
                -- Lua reference manual says this is OK
                dls[dl_date] = nil
            end
        end
    end
end

-- Destroy all windows that are not attached to a sizer in the current layout.
-- This is called at the end of layout.setLayout()
function layout.cleanLayout()
    -- Clean download ctrls from dlg.downloads
    layout.cleanDownloadCtrls()
    --if true then return end

    -- Destroy any extra child windows
    local child = P.dlg.panel.Children.First
    while child do
        local window = child.Data:DynamicCast("wxWindow")
        -- Get the next node *before* we destroy the window
        child = child.Next
        if not window.ContainingSizer then window:Destroy() end
    end
end


-- Change the layout, providing either a function or a name.
-- Handle aborting current downloads, freezing and thawing the dialog,
-- resetting the download tables, destroying child windows, etc.
function layout.setLayout(func, start_date, ...)
    -- Find the function in the layouts table if we were given a string
    if type(func) == "string" then
        local desc = layout.layouts[func]
        if not desc then return end
        func = desc.func
        if #arg == 0 then arg = desc.args end
    end

    if not start_date then
        start_date = layout.today()
        start_date:adddays(-7)
    end

    local dlg = assert(P.dlg)

    -- If there are active downloads, make sure they are done.
    if #dlg.activedownloads > 0 then
        if xword.Prompt(
               string.format("There are %d active downloads.\nAbort?",
                             #dlg.activedownloads))
        then
            dlg.AbortDownloads()
            -- Call this function again when all downloads have ended.
            dlg.OnDownloadEnd(
                function()
                    layout.setLayout(func, start_date, unpack(arg))
                end)
        else
            -- Do nothing if the user answered "No"
            return
        end
    end

    -- Do the layout
    dlg:Freeze()
    -- Set a dummy sizer to destroy the previous one
    dlg.panel:SetSizer(wx.wxBoxSizer(wx.wxVERTICAL))
    --dlg.panel:DestroyChildren()

    -- downloads owned by the dialog:
    -- (hash)  downloads["displayName"][date]
    -- (array) downloadslist[] ...
    -- Don't touch dlg.downloads yet, in case we need to use existing ctrls.
    dlg.downloadslist = {}
    dlg.pendingdownloads = {}
    dlg.activedownloads = {}

    func(start_date, unpack(arg))

    -- Make sure the layout set a sizer or we'll have big problems
    assert(dlg.panel.Sizer)

    -- Our own version of lua's "tag and sweep" garbage collection!
    -- Clean up any windows that are not used in the current layout.  Any
    -- window that is not part of a sizer will be destroyed.
    layout.cleanLayout()

    dlg.scroller:FitInside()
    dlg.scroller:Scroll(0,0)

    dlg:Thaw()
end

-- ============================================================================
-- Button callbacks
-- ============================================================================

-- Return a callback function that will start all downloads in the given
-- table of DownloadCtrls.
-- Default is all download controls
function layout.downloadAll(ctrls)
    -- ipairs will only iterate numeric keys, so the entire download table
    -- is safe to use here.
    local ctrls = ctrls or P.dlg.downloadslist

    return function()
        for _, dl in ipairs(ctrls) do
            wx.wxSafeYield() -- Prevent locking
            dl.start()
        end
    end
end


-- Download all puzzles on a given date
function layout.downloadAllDates(target_date)
    local ctrls = {}
    for name, dates in pairs(P.dlg.downloads) do
        for dl_date, dl in pairs(dates) do
            if target_date == dl_date then
                table.insert(ctrls, dl)
            end
        end
    end
    return layout.downloadAll(ctrls)
end


-- Download all available puzzles from a given source
function layout.downloadAllPuzzles(target_label)
    local ctrls = {}
    for _, dl in pairs(P.dlg.downloads[target_label]) do
        table.insert(ctrls, dl)
    end
    return layout.downloadAll(ctrls)
end




-- Standard fonts
layout.font = wx.wxFont(12, wx.wxFONTFAMILY_SWISS,
                        wx.wxFONTSTYLE_NORMAL, wx.wxFONTWEIGHT_NORMAL)

layout.boldfont = wx.wxFont(12, wx.wxFONTFAMILY_SWISS,
                            wx.wxFONTSTYLE_NORMAL, wx.wxFONTWEIGHT_BOLD)


-- Create and return a header
function layout.Header(parent, text, bold)
    local header = wx.wxStaticText(parent, wx.wxID_ANY, text)
    if bold then
        header:SetFont(layout.boldfont)
    else
        header:SetFont(layout.font)
    end
    return header
end

-- Require the actual layouts (order is important)
require 'download.layout.grid'
require 'download.layout.puzzle'
