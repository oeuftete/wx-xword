-- ============================================================================
-- Import
--     A somewhat complex XWord add-on that implements an Import menu for
--     foreign crossword puzzle types.

--     Each recognized type requires a separate lua script that must be placed
--     in the import directory.  In order to add a file type to the Import
--     menu, the script should call import.addType() described below.
-- ============================================================================

local importMenu

-- The package table
import = {}

-- handler table format:
-- {
--     label = {
--         types = { ext1 = 'desc1', ext2 = 'desc2' },
--         load = function(filename, puz) end
--         convert = function(filename, puz) end
--     },
--     [...]
-- }
import.handlers = {}

-- ============================================================================
-- Add a handler to the import handlers table
-- addType will add the file selector dialogs, etc.

-- loadfunc should take a filename as the parameter, and return true if loading
-- succeeded.  loadfunc can get a puzzle using xword.frame:GetPuzzle().

-- types should be a table { ext = 'file description', [...] }
-- ============================================================================
function import.addType(label, types, loadfunc)
    assert(label and types and loadfunc)
    local menuItem = importMenu:Append(wx.wxID_ANY, label)

    -- Make the wildcard string
    local wildcard = ''
    for ext, desc in pairs(types) do
        wildcard = wildcard..desc..'(*.'..ext..')|*.'..ext..'|'
    end
    -- Remove the trailing '|' from the wildcard
    wildcard = wildcard:sub(1, -2)

    -- Add to the handlers table
    import.handlers[label] = {
        types = types,
        load = function(filename)
            -- Load and display the puzzle
            xword.frame.Puzzle:Clear()
            local success, err = pcall(loadfunc, filename, xword.frame.Puzzle)
            if err then
                wx.wxMessageBox(err)
            else
                xword.frame.Puzzle:SetFilename(filename)
                xword.frame.Puzzle:SetOk(true)
            end
            -- Show the puzzle regardless (a failed puzzle will display blank)
            xword.frame:ShowPuzzle()
        end,
        convert = function(filename, deleteOld)
            local puz = xword.XPuzzle()
            local success, err = pcall(loadfunc, filename, puz)
            if err then
                return false, err
            else
                -- Save the file as a .puz
                local newfile = filename:match("^(.*)%..*$") or filename
                puz:Save(newfile..'.puz')
                -- Remove the old file
                if deleteOld then os.remove(filename) end
                return true
            end
        end,
    }

    -- Connect the menu event
    xword.frame:Connect(menuItem:GetId(),
                        wx.wxEVT_COMMAND_MENU_SELECTED,
        function(evt)
            local filename = wx.wxFileSelector(
                'Select a file to import',
                '', '', '', wildcard,
                wx.wxFD_OPEN + wx.wxFD_FILE_MUST_EXIST,
                xword.frame
            )

            if filename ~= '' then
                import.handlers[label].load(filename)
            end
        end)
end

local function init()
    -- Add an Import submenu to the file menu
    -- We can't just use FindOrCreateMenu for the whole path
    -- (i.e. FindOrCreateMenu({'File', 'Import'}) because we need to stick
    -- the Import menu in a specific place instead of just appending it to
    -- the File menu.
    local fileMenu = xword.frame:FindOrCreateMenu({'File'})

    -- Find the Close menu item index
    local menuItems = fileMenu:GetMenuItems()
    local index = 0
    local node = menuItems:GetFirst()
    while node do
        -- This method of accessing the wxMenuItem is disgusting, but it's even
        -- how the wxLua reference suggests using a wxMenuItemList
        local item = node:GetData():DynamicCast("wxMenuItem")
        if item:GetItemLabelText() == "Close" then
            break
        end
        node = node:GetNext()
        index = index + 1
    end

    -- The next item should be a separator
    index = index + 1

    -- Insert a separator for the Import menu
    fileMenu:InsertSeparator(index + 1)

    -- Add the Import menu
    importMenu = wx.wxMenu()
    -- Get a menu item this way
    local item = fileMenu:Append(wx.wxID_ANY, "Import", importMenu)
    fileMenu:Insert(index + 1, fileMenu:Remove(item))

    -- Require the rest of the files in the import directory
    xword.requiredir('import')
end

init()