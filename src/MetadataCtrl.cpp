// This file is part of XWord    
// Copyright (C) 2012 Mike Richards ( mrichards42@gmx.com )
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "MetadataCtrl.hpp"
#include "MyFrame.hpp"
#include "utils/string.hpp"
#include "App.hpp"
#include <wx/tokenzr.h>
#ifdef XWORD_USE_LUA
#   include "../lua/luapuz/bind/luapuz_puz_Puzzle.hpp"
#endif

// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

IMPLEMENT_DYNAMIC_CLASS(MetadataCtrl, HtmlText)

bool
MetadataCtrl::Create(wxWindow * parent,
                   wxWindowID id,
                   const wxString & displayFormat,
                   const wxPoint & position,
                   const wxSize & size,
                   long style,
                   const wxString & name)
{
    m_cfg = NULL;
    m_useLua = style & META_USE_LUA;
    style = style & ~ META_USE_LUA;
    if (! HtmlText::Create(parent, id, wxEmptyString, position, size, style, name))
        return false;
    // Find a MyFrame instance somewhere in the parent hierarchy
    while (parent)
    {
        MyFrame * frame = wxDynamicCast(parent, MyFrame);
        if (frame)
        {
            m_frame = frame;
            break;
        }
        parent = parent->GetParent();
    }
    SetBackgroundColour(*wxWHITE);
    SetDisplayFormat(displayFormat);
    return true;
}

MetadataCtrl::~MetadataCtrl()
{
    wxGetApp().GetConfigManager().RemoveCallbacks(this);
}


wxString MetadataCtrl::GetMeta(const wxString & str_, MyFrame * frame)
{
    wxString str = str_.Lower();
    if (str == _T("cluenumber"))
    {
        puz::Clue * clue = frame->GetFocusedClue();
        if (clue)
            return puz2wx(clue->GetNumber());
        else
            return wxEmptyString;
    }
    else if (str == _T("clue"))
    {
        puz::Clue * clue = frame->GetFocusedClue();
        if (clue)
            return puz2wx(clue->GetText());
        else
            return wxEmptyString;
    }
    else
        return puz2wx(frame->GetPuzzle().GetMeta(wx2puz(str)));
}

wxString MetadataCtrl::FormatLabel(const wxString & format, MyFrame * frame,
                                   bool useLua)
{
    if (! frame || ! frame->GetPuzzle().IsOk())
        return wxEmptyString;
    wxString result;
    const puz::Puzzle & puz = frame->GetPuzzle();
    wxStringTokenizer tok(format, _T("%"), wxTOKEN_RET_EMPTY_ALL);
    bool ismeta = false; // Is the current token a metadata value?
    while (tok.HasMoreTokens())
    {
        if (! ismeta)
        {
            result << tok.GetNextToken();
            ismeta = true; // The next token is a metadata value
        }
        else // We're in the middle of a percent-delimited string
        {
            wxString str = tok.GetNextToken();
            if (str.empty()) // This is a literal %
            {
                result << _T("%");
            }
            else // This is a metadata value
            {
                str = GetMeta(str, frame);
#if XWORD_USE_LUA
                if (useLua)
                {
                    if (str.empty()) {
                        result << _T("nil");
                    }
                    else {
                        str.Replace("'", "\\'");
                        result << _T("'") << str << _T("'");
                    }
                }
                else // plain text
                    result << str;
#else // ! XWORD_USE_LUA
                result << str;
#endif // XWORD_USE_LUA
            }
            ismeta = false; // The next token is plain text
        }
    }
#if XWORD_USE_LUA
    if (! useLua)
        return result;
    // Process this with lua
    wxLuaState & luastate = wxGetApp().GetwxLuaState();
    lua_State * L = luastate.GetLuaState();
    // Compile a lua function taking a puzzle argument
    if (result.Find(_T("return")) == -1) // Make sure we're returning something
        result = _T("return ") + result;
    wxLuaCharBuffer code(wxString::Format(_T("return function (puzzle) %s end"), (const wxChar *)result.c_str()));
    // Compile and run the code
    if (luaL_loadbuffer(L, code.GetData(), code.Length(), "") == 0)
    {
        if (lua_pcall(L, 0, 1, 0) == 0)
        {
            if (lua_isfunction(L, -1)) // Make sure we got a function
            {
                // Call this function
                luapuz_pushPuzzle(L, &frame->GetPuzzle());
                if (lua_pcall(L, 1, 1, 0) == 0)
                {
                    // Check the result
                    if (luastate.lua_IsString(-1))
                    {
                        result = luastate.lua_TowxString(-1);
                        lua_pop(L, 1);
                        return result;
                    }
                    // Clean up the stack
                    lua_pop(L, 1);
                }
            }
            else // Clean up the stack
            {
                lua_pop(L, 1);
            }
        }
    }
    else
    {
        // Return the error
        result = luastate.lua_TowxString(-1);
        lua_pop(L, 1);
        return result;
    }
    return wxEmptyString;
#else // ! XWORD_USE_LUA
    return result;
#endif // XWORD_USE_LUA
}

// ConfigManager and context menu
void MetadataCtrl::SetConfig(ConfigManager::Metadata_t * cfg)
{
    m_cfg = cfg;
    // Config callbacks
    cfg->displayFormat.AddCallback(this, &MetadataCtrl::SetDisplayFormat);
    cfg->font.AddCallback(this, &MetadataCtrl::SetFont);
    cfg->foregroundColor.AddCallback(this, &MetadataCtrl::SetForegroundColour);
    cfg->backgroundColor.AddCallback(this, &MetadataCtrl::SetBackgroundColour);
    cfg->alignment.AddCallback(this, &MetadataCtrl::SetAlignment);
    cfg->useLua.AddCallback(this, &MetadataCtrl::SetLuaFormat);
    // Context Menu
    Bind(wxEVT_CONTEXT_MENU, &MetadataCtrl::OnContextMenu, this);
}

enum
{
    ID_ALIGN_LEFT = 100,
    ID_ALIGN_CENTER,
    ID_ALIGN_RIGHT,
    ID_ALIGN_TOP,
    ID_ALIGN_MIDDLE,
    ID_ALIGN_BOTTOM
};

struct ContextHandler
{
    ContextHandler(ConfigManager::Metadata_t & cfg) : m_cfg(cfg) {}
    ConfigManager::Metadata_t & m_cfg;

    long GetAlignment(long id)
    {
        switch(id)
        {
        case ID_ALIGN_CENTER:
            return wxALIGN_CENTER_HORIZONTAL;
        case ID_ALIGN_RIGHT:
            return wxALIGN_RIGHT;
        case ID_ALIGN_LEFT:
        default:
            return wxALIGN_LEFT;
        }
    }

    void OnAlignment(wxCommandEvent & evt)
    {
        m_cfg.alignment.Set(GetAlignment(evt.GetId()));
    }
};



void MetadataCtrl::OnContextMenu(wxContextMenuEvent & evt)
{
    wxMenu menu;

    wxMenu * alignmenu = new wxMenu();
    alignmenu->AppendRadioItem(ID_ALIGN_LEFT, "Left");
    alignmenu->AppendRadioItem(ID_ALIGN_CENTER, "Center");
    alignmenu->AppendRadioItem(ID_ALIGN_RIGHT, "Right");
    long alignment = m_cfg->alignment();
    if (alignment & wxALIGN_CENTER_HORIZONTAL)
        alignmenu->Check(ID_ALIGN_CENTER, true);
    else if (alignment & wxALIGN_RIGHT)
        alignmenu->Check(ID_ALIGN_RIGHT, true);
    // Else ID_ALIGN_LEFT is already checked

    menu.AppendSubMenu(alignmenu, "Alignment");

    ContextHandler handler(*m_cfg);
    menu.Bind(wxEVT_MENU, &ContextHandler::OnAlignment, &handler, ID_ALIGN_LEFT, ID_ALIGN_RIGHT);

    PopupMenu(&menu);
    Refresh();
}