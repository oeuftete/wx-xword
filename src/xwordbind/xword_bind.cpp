// ---------------------------------------------------------------------------
// ./xword.cpp was generated by genwxbind.lua 
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------


#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
     #include "wx/wx.h"
#endif

#include "wxlua/wxlstate.h"
#include "xword_bind.h"
#include "xword_bind_helpers.hpp"


// ---------------------------------------------------------------------------
// Bind class MyFrame
// ---------------------------------------------------------------------------

// Lua MetaTable Tag for Class 'MyFrame'
int wxluatype_MyFrame = WXLUA_TUNKNOWN;

#if wxLUA_USE_wxAUI && wxCHECK_VERSION(2,8,0) && wxUSE_AUI
static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_AddPane[] = { &wxluatype_MyFrame, &wxluatype_wxWindow, &wxluatype_wxAuiPaneInfo, NULL };
static int LUACALL wxLua_MyFrame_AddPane(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_AddPane[1] = {{ wxLua_MyFrame_AddPane, WXLUAMETHOD_METHOD, 3, 3, s_wxluatypeArray_wxLua_MyFrame_AddPane }};
//     void AddPane(wxWindow * window, const wxAuiPaneInfo & info)
static int LUACALL wxLua_MyFrame_AddPane(lua_State *L)
{
    // const wxAuiPaneInfo info
    const wxAuiPaneInfo * info = (const wxAuiPaneInfo *)wxluaT_getuserdatatype(L, 3, wxluatype_wxAuiPaneInfo);
    // wxWindow window
    wxWindow * window = (wxWindow *)wxluaT_getuserdatatype(L, 2, wxluatype_wxWindow);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call AddPane
    self->AddPane(window, *info);

    return 0;
}

#endif // wxLUA_USE_wxAUI && wxCHECK_VERSION(2,8,0) && wxUSE_AUI

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_CheckPuzzle[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_CheckPuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_CheckPuzzle[1] = {{ wxLua_MyFrame_CheckPuzzle, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_CheckPuzzle }};
//     void CheckPuzzle()
static int LUACALL wxLua_MyFrame_CheckPuzzle(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call CheckPuzzle
    self->CheckPuzzle();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ClosePuzzle[] = { &wxluatype_MyFrame, &wxluatype_TBOOLEAN, NULL };
static int LUACALL wxLua_MyFrame_ClosePuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ClosePuzzle[1] = {{ wxLua_MyFrame_ClosePuzzle, WXLUAMETHOD_METHOD, 1, 2, s_wxluatypeArray_wxLua_MyFrame_ClosePuzzle }};
//     bool ClosePuzzle(bool prompt = true)
static int LUACALL wxLua_MyFrame_ClosePuzzle(lua_State *L)
{
    // get number of arguments
    int argCount = lua_gettop(L);
    // bool prompt = true
    bool prompt = (argCount >= 2 ? wxlua_getbooleantype(L, 2) : true);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ClosePuzzle
    bool returns = (self->ClosePuzzle(prompt));
    // push the result flag
    lua_pushboolean(L, returns);

    return 1;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetFilename[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetFilename(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetFilename[1] = {{ wxLua_MyFrame_GetFilename, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetFilename }};
//     const wxString & GetFilename()
static int LUACALL wxLua_MyFrame_GetFilename(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call GetFilename
    wxString returns = (self->GetFilename());
    // push the result string
    wxlua_pushwxString(L, returns);

    return 1;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetFocusedClue[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetFocusedClue(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetFocusedClue[1] = {{ wxLua_MyFrame_GetFocusedClue, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetFocusedClue }};
// %override wxLua_MyFrame_GetFocusedClue
// const puz::Puzzle::Clue * MyFrame::GetFocusedClue()
static int LUACALL wxLua_MyFrame_GetFocusedClue(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // call GetFocusedClue
    const puz::Clue * clue =  self->GetFocusedClue();

    // Return two nils if there is no focused clue
    if (clue == NULL)
    {
        lua_pushnil(L);
        lua_pushnil(L);
        return 2;
    }

    // Return a pair (number, text)
    lua_pushnumber(L, clue->GetInt());
    luapuz_pushstring_t(L, clue->GetText());
    return 2;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetFocusedDirection[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetFocusedDirection(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetFocusedDirection[1] = {{ wxLua_MyFrame_GetFocusedDirection, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetFocusedDirection }};
// %override wxLua_MyFrame_GetFocusedDirection
// puz::GridDirection GetFocusedDirection()
static int LUACALL wxLua_MyFrame_GetFocusedDirection(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    short returns = self->GetFocusedDirection();
    lua_pushnumber(L, returns);
    return 1;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetFocusedSquare[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetFocusedSquare(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetFocusedSquare[1] = {{ wxLua_MyFrame_GetFocusedSquare, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetFocusedSquare }};
// %override wxLua_MyFrame_GetFocusedSquare
// puz::Square * GetFocusedSquare()
static int LUACALL wxLua_MyFrame_GetFocusedSquare(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    puz::Square * returns = const_cast<puz::Square *>(self->GetFocusedSquare());
    luapuz_pushSquare(L, returns);
    return 1;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetFocusedWord[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetFocusedWord(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetFocusedWord[1] = {{ wxLua_MyFrame_GetFocusedWord, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetFocusedWord }};
// %override wxLua_MyFrame_GetFocusedWord
// %override [Lua table] MyFrame::GetFocusedWord()
// puz::Word * GetFocusedWord()
static int LUACALL wxLua_MyFrame_GetFocusedWord(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // call GetFocusedWord
    const puz::Word * word = self->GetFocusedWord();

    // Return nil if there is no focused word
    if (word == NULL)
    {
        lua_pushnil(L);
        return 1;
    }

    // Assemble a table of all squares in the focused word.

    lua_newtable(L);

    int i = 1; // lua indicies start with 1 not 0
    puz::square_iterator it;
    for (it = word->begin(); it != word->end(); ++it)
    {
        lua_pushnumber(L, i++);
        luapuz_pushSquare(L, &*it);
        // t[i] = square
        lua_settable(L, -3); // -3 = third from the top of the stack
    }

    return 1; // One object on the stack for lua.
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetPuzzle[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetPuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetPuzzle[1] = {{ wxLua_MyFrame_GetPuzzle, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetPuzzle }};
// %override wxLua_MyFrame_GetPuzzle
// puz::Puzzle & GetPuzzle()
static int LUACALL wxLua_MyFrame_GetPuzzle(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    puz::Puzzle & returns = self->GetPuzzle();
    luapuz_pushPuzzle(L, &returns);
    return 1;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_GetTime[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_GetTime(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_GetTime[1] = {{ wxLua_MyFrame_GetTime, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_GetTime }};
//     int  GetTime()
static int LUACALL wxLua_MyFrame_GetTime(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call GetTime
    int returns = (self->GetTime());
    // push the result number
    lua_pushnumber(L, returns);

    return 1;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_HidePane[] = { &wxluatype_MyFrame, &wxluatype_TSTRING, NULL };
static int LUACALL wxLua_MyFrame_HidePane(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_HidePane[1] = {{ wxLua_MyFrame_HidePane, WXLUAMETHOD_METHOD, 2, 2, s_wxluatypeArray_wxLua_MyFrame_HidePane }};
//     void HidePane(const wxString & name)
static int LUACALL wxLua_MyFrame_HidePane(lua_State *L)
{
    // const wxString name
    const wxString name = wxlua_getwxStringtype(L, 2);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call HidePane
    self->HidePane(name);

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_IsTimerRunning[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_IsTimerRunning(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_IsTimerRunning[1] = {{ wxLua_MyFrame_IsTimerRunning, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_IsTimerRunning }};
//     bool IsTimerRunning()
static int LUACALL wxLua_MyFrame_IsTimerRunning(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call IsTimerRunning
    bool returns = (self->IsTimerRunning());
    // push the result flag
    lua_pushboolean(L, returns);

    return 1;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_LoadPuzzle[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_LoadPuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_LoadPuzzle[1] = {{ wxLua_MyFrame_LoadPuzzle, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_LoadPuzzle }};
// %override wxLua_MyFrame_LoadPuzzle
//     bool LoadPuzzle(const wxString & filename, const puz::Puzzle::FileHandlerDesc * handler)
static int LUACALL wxLua_MyFrame_LoadPuzzle(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // const wxString filename
    const wxString filename = wxlua_getwxStringtype(L, 2);

    if (lua_gettop(L) < 3)
    {
        // call LoadPuzzle
        bool returns = self->LoadPuzzle(filename);
        lua_pushboolean(L, returns);
        return 1;
    }
    else
    {
        // Create a FileHandlerDesc
        luaL_checktype(L, 3, LUA_TFUNCTION);

        // Push the function for luapuz_Load_Puzzle.
        lua_pushvalue(L, 3);

        // Create the puz::Puzzle file handler
        puz::Puzzle::FileHandlerDesc desc;
        desc.data = L;
        desc.handler = luapuz_Load_Puzzle;

        bool returns = self->LoadPuzzle(filename, &desc);
        lua_pushboolean(L, returns);
        return 1;
    }
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ResetTimer[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ResetTimer(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ResetTimer[1] = {{ wxLua_MyFrame_ResetTimer, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ResetTimer }};
//     void ResetTimer()
static int LUACALL wxLua_MyFrame_ResetTimer(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ResetTimer
    self->ResetTimer();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SavePuzzle[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_SavePuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SavePuzzle[1] = {{ wxLua_MyFrame_SavePuzzle, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_SavePuzzle }};
// %override wxLua_MyFrame_SavePuzzle
//     bool SavePuzzle(const wxString & filename, const puz::Puzzle::FileHandlerDesc * handler)
static int LUACALL wxLua_MyFrame_SavePuzzle(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // const wxString filename
    const wxString filename = wxlua_getwxStringtype(L, 2);

    if (lua_gettop(L) < 3)
    {
        // call LoadPuzzle
        bool returns = self->SavePuzzle(filename);
        lua_pushboolean(L, returns);
        return 1;
    }
    else
    {
        // Create a FileHandlerDesc
        luaL_checktype(L, 3, LUA_TFUNCTION);

        // Push the function for luapuz_Save_Puzzle.
        lua_pushvalue(L, 3);

        // Create the puz::Puzzle file handler
        puz::Puzzle::FileHandlerDesc desc;
        desc.data = L;
        desc.handler = luapuz_Save_Puzzle;

        bool returns = self->SavePuzzle(filename, &desc);
        lua_pushboolean(L, returns);
        return 1;
    }
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetFilename[] = { &wxluatype_MyFrame, &wxluatype_TSTRING, NULL };
static int LUACALL wxLua_MyFrame_SetFilename(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetFilename[1] = {{ wxLua_MyFrame_SetFilename, WXLUAMETHOD_METHOD, 2, 2, s_wxluatypeArray_wxLua_MyFrame_SetFilename }};
//     void SetFilename(const wxString & filename)
static int LUACALL wxLua_MyFrame_SetFilename(lua_State *L)
{
    // const wxString filename
    const wxString filename = wxlua_getwxStringtype(L, 2);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call SetFilename
    self->SetFilename(filename);

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetFocusedDirection[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_SetFocusedDirection(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetFocusedDirection[1] = {{ wxLua_MyFrame_SetFocusedDirection, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_SetFocusedDirection }};
// %override wxLua_MyFrame_SetFocusedDirection
// void SetFocusedDirection(puz::GridDirection)
static int LUACALL wxLua_MyFrame_SetFocusedDirection(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    puz::GridDirection direction = luapuz_checkGridDirection(L, 2);
    self->SetFocusedDirection(direction);
    return 0;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetFocusedSquare[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_SetFocusedSquare(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetFocusedSquare[1] = {{ wxLua_MyFrame_SetFocusedSquare, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_SetFocusedSquare }};
// %override wxLua_MyFrame_SetFocusedSquare
// puz::Square * SetFocusedSquare(puz::Square * square)
static int LUACALL wxLua_MyFrame_SetFocusedSquare(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    puz::Square * square = luapuz_checkSquare(L, 2);
    puz::Square * returns = const_cast<puz::Square *>(self->SetFocusedSquare(square));
    luapuz_pushSquare(L, returns);
    return 1;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetSquareText[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_SetSquareText(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetSquareText[1] = {{ wxLua_MyFrame_SetSquareText, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_SetSquareText }};
// %override wxLua_MyFrame_SetSquareText
// bool SetSquareText(puz::Square * square, const wxString & text)
static int LUACALL wxLua_MyFrame_SetSquareText(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    puz::Square * square = luapuz_checkSquare(L, 2);
    const wxString text = wxlua_getwxStringtype(L, 3);
    bool returns = self->SetSquareText(square, text);
    lua_pushboolean(L, returns);
    return 1;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetStatus[] = { &wxluatype_MyFrame, &wxluatype_TSTRING, NULL };
static int LUACALL wxLua_MyFrame_SetStatus(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetStatus[1] = {{ wxLua_MyFrame_SetStatus, WXLUAMETHOD_METHOD, 2, 2, s_wxluatypeArray_wxLua_MyFrame_SetStatus }};
//     void SetStatus(const wxString & text)
static int LUACALL wxLua_MyFrame_SetStatus(lua_State *L)
{
    // const wxString text
    const wxString text = wxlua_getwxStringtype(L, 2);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call SetStatus
    self->SetStatus(text);

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_SetTime[] = { &wxluatype_MyFrame, &wxluatype_TNUMBER, NULL };
static int LUACALL wxLua_MyFrame_SetTime(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_SetTime[1] = {{ wxLua_MyFrame_SetTime, WXLUAMETHOD_METHOD, 2, 2, s_wxluatypeArray_wxLua_MyFrame_SetTime }};
//     void SetTime(int time)
static int LUACALL wxLua_MyFrame_SetTime(lua_State *L)
{
    // int time
    int time = (int)wxlua_getnumbertype(L, 2);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call SetTime
    self->SetTime(time);

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowClues[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ShowClues(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowClues[1] = {{ wxLua_MyFrame_ShowClues, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ShowClues }};
// %override wxLua_MyFrame_ShowClues
//     void ShowClues()
static int LUACALL wxLua_MyFrame_ShowClues(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // Check the puzzle
    if (self->GetPuzzle().IsOk())
    {
        try {
            self->GetPuzzle().TestOk();
            // call ShowClues
            self->ShowClues();
        }
        catch(...) {
            self->GetPuzzle().SetOk(false);
        }
    }
    return 0;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowGrid[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ShowGrid(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowGrid[1] = {{ wxLua_MyFrame_ShowGrid, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ShowGrid }};
// %override wxLua_MyFrame_ShowGrid
//     void ShowGrid()
static int LUACALL wxLua_MyFrame_ShowGrid(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // Check the puzzle
    if (self->GetPuzzle().IsOk())
    {
        try {
            self->GetPuzzle().TestOk();
            // call ShowGrid
            self->ShowGrid();
        }
        catch(...) {
            self->GetPuzzle().SetOk(false);
        }
    }
    return 0;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowMetadata[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ShowMetadata(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowMetadata[1] = {{ wxLua_MyFrame_ShowMetadata, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ShowMetadata }};
//     void ShowMetadata()
static int LUACALL wxLua_MyFrame_ShowMetadata(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ShowMetadata
    self->ShowMetadata();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowNotes[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ShowNotes(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowNotes[1] = {{ wxLua_MyFrame_ShowNotes, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ShowNotes }};
//     void ShowNotes()
static int LUACALL wxLua_MyFrame_ShowNotes(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ShowNotes
    self->ShowNotes();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowPane[] = { &wxluatype_MyFrame, &wxluatype_TSTRING, &wxluatype_TBOOLEAN, NULL };
static int LUACALL wxLua_MyFrame_ShowPane(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowPane[1] = {{ wxLua_MyFrame_ShowPane, WXLUAMETHOD_METHOD, 2, 3, s_wxluatypeArray_wxLua_MyFrame_ShowPane }};
//     void ShowPane(const wxString & name, bool show = true);
static int LUACALL wxLua_MyFrame_ShowPane(lua_State *L)
{
    // get number of arguments
    int argCount = lua_gettop(L);
    // bool show = true
    bool show = (argCount >= 3 ? wxlua_getbooleantype(L, 3) : true);
    // const wxString name
    const wxString name = wxlua_getwxStringtype(L, 2);
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ShowPane
    self->ShowPane(name, show);

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ShowPuzzle[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ShowPuzzle(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ShowPuzzle[1] = {{ wxLua_MyFrame_ShowPuzzle, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ShowPuzzle }};
// %override wxLua_MyFrame_ShowPuzzle
//     void ShowPuzzle()
static int LUACALL wxLua_MyFrame_ShowPuzzle(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);

    // Check the puzzle
    if (self->GetPuzzle().IsOk())
    {
        try {
            self->GetPuzzle().TestOk();
        }
        catch(...) {
            self->GetPuzzle().SetOk(false);
        }
    }


    // call ShowPuzzle
    self->ShowPuzzle();

    return 0;
}


static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_StartTimer[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_StartTimer(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_StartTimer[1] = {{ wxLua_MyFrame_StartTimer, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_StartTimer }};
//     void StartTimer()
static int LUACALL wxLua_MyFrame_StartTimer(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call StartTimer
    self->StartTimer();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_StopTimer[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_StopTimer(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_StopTimer[1] = {{ wxLua_MyFrame_StopTimer, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_StopTimer }};
//     void StopTimer()
static int LUACALL wxLua_MyFrame_StopTimer(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call StopTimer
    self->StopTimer();

    return 0;
}

static wxLuaArgType s_wxluatypeArray_wxLua_MyFrame_ToggleTimer[] = { &wxluatype_MyFrame, NULL };
static int LUACALL wxLua_MyFrame_ToggleTimer(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_MyFrame_ToggleTimer[1] = {{ wxLua_MyFrame_ToggleTimer, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_MyFrame_ToggleTimer }};
//     void ToggleTimer()
static int LUACALL wxLua_MyFrame_ToggleTimer(lua_State *L)
{
    // get this
    MyFrame * self = (MyFrame *)wxluaT_getuserdatatype(L, 1, wxluatype_MyFrame);
    // call ToggleTimer
    self->ToggleTimer();

    return 0;
}



void wxLua_MyFrame_delete_function(void** p)
{
    MyFrame* o = (MyFrame*)(*p);
    delete o;
}

// Map Lua Class Methods to C Binding Functions
wxLuaBindMethod MyFrame_methods[] = {
#if wxLUA_USE_wxAUI && wxCHECK_VERSION(2,8,0) && wxUSE_AUI
    { "AddPane", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_AddPane, 1, NULL },
#endif // wxLUA_USE_wxAUI && wxCHECK_VERSION(2,8,0) && wxUSE_AUI

    { "CheckPuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_CheckPuzzle, 1, NULL },
    { "ClosePuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ClosePuzzle, 1, NULL },
    { "GetFilename", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetFilename, 1, NULL },
    { "GetFocusedClue", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetFocusedClue, 1, NULL },
    { "GetFocusedDirection", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetFocusedDirection, 1, NULL },
    { "GetFocusedSquare", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetFocusedSquare, 1, NULL },
    { "GetFocusedWord", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetFocusedWord, 1, NULL },
    { "GetPuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetPuzzle, 1, NULL },
    { "GetTime", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_GetTime, 1, NULL },
    { "HidePane", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_HidePane, 1, NULL },
    { "IsTimerRunning", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_IsTimerRunning, 1, NULL },
    { "LoadPuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_LoadPuzzle, 1, NULL },
    { "ResetTimer", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ResetTimer, 1, NULL },
    { "SavePuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SavePuzzle, 1, NULL },
    { "SetFilename", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetFilename, 1, NULL },
    { "SetFocusedDirection", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetFocusedDirection, 1, NULL },
    { "SetFocusedSquare", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetFocusedSquare, 1, NULL },
    { "SetSquareText", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetSquareText, 1, NULL },
    { "SetStatus", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetStatus, 1, NULL },
    { "SetTime", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_SetTime, 1, NULL },
    { "ShowClues", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowClues, 1, NULL },
    { "ShowGrid", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowGrid, 1, NULL },
    { "ShowMetadata", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowMetadata, 1, NULL },
    { "ShowNotes", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowNotes, 1, NULL },
    { "ShowPane", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowPane, 1, NULL },
    { "ShowPuzzle", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ShowPuzzle, 1, NULL },
    { "StartTimer", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_StartTimer, 1, NULL },
    { "StopTimer", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_StopTimer, 1, NULL },
    { "ToggleTimer", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_MyFrame_ToggleTimer, 1, NULL },
    { 0, 0, 0, 0 },
};

int MyFrame_methodCount = sizeof(MyFrame_methods)/sizeof(wxLuaBindMethod) - 1;


// ---------------------------------------------------------------------------
// Bind class wxPuzEvent
// ---------------------------------------------------------------------------

// Lua MetaTable Tag for Class 'wxPuzEvent'
int wxluatype_wxPuzEvent = WXLUA_TUNKNOWN;

static wxLuaArgType s_wxluatypeArray_wxLua_wxPuzEvent_GetSquare[] = { &wxluatype_wxPuzEvent, NULL };
static int LUACALL wxLua_wxPuzEvent_GetSquare(lua_State *L);
static wxLuaBindCFunc s_wxluafunc_wxLua_wxPuzEvent_GetSquare[1] = {{ wxLua_wxPuzEvent_GetSquare, WXLUAMETHOD_METHOD, 1, 1, s_wxluatypeArray_wxLua_wxPuzEvent_GetSquare }};
// %override wxLua_wxPuzEvent_GetSquare
// puz::Square * GetSquare()
static int LUACALL wxLua_wxPuzEvent_GetSquare(lua_State *L)
{
    // get this
    wxPuzEvent * self = (wxPuzEvent *)wxluaT_getuserdatatype(L, 1, wxluatype_wxPuzEvent);

    puz::Square * returns = const_cast<puz::Square *>(self->GetSquare());
    luapuz_pushSquare(L, returns);
    return 1;
}




void wxLua_wxPuzEvent_delete_function(void** p)
{
    wxPuzEvent* o = (wxPuzEvent*)(*p);
    delete o;
}

// Map Lua Class Methods to C Binding Functions
wxLuaBindMethod wxPuzEvent_methods[] = {
    { "GetSquare", WXLUAMETHOD_METHOD, s_wxluafunc_wxLua_wxPuzEvent_GetSquare, 1, NULL },
    { 0, 0, 0, 0 },
};

int wxPuzEvent_methodCount = sizeof(wxPuzEvent_methods)/sizeof(wxLuaBindMethod) - 1;




// ---------------------------------------------------------------------------
// ./xword_bind.cpp was generated by genwxbind.lua 
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
// wxLuaGetEventList_xword() is called to register events
// ---------------------------------------------------------------------------

wxLuaBindEvent* wxLuaGetEventList_xword(size_t &count)
{
    static wxLuaBindEvent eventList[] =
    {
        { "wxEVT_PUZ_CLUE_FOCUS", WXLUA_GET_wxEventType_ptr(wxEVT_PUZ_CLUE_FOCUS), &wxluatype_wxPuzEvent },
        { "wxEVT_PUZ_GRID_FOCUS", WXLUA_GET_wxEventType_ptr(wxEVT_PUZ_GRID_FOCUS), &wxluatype_wxPuzEvent },
        { "wxEVT_PUZ_LETTER", WXLUA_GET_wxEventType_ptr(wxEVT_PUZ_LETTER), &wxluatype_wxPuzEvent },

        { 0, 0, 0 },
    };
    count = sizeof(eventList)/sizeof(wxLuaBindEvent) - 1;
    return eventList;
}

// ---------------------------------------------------------------------------
// wxLuaGetDefineList_xword() is called to register #define and enum
// ---------------------------------------------------------------------------

wxLuaBindNumber* wxLuaGetDefineList_xword(size_t &count)
{
    static wxLuaBindNumber numberList[] =
    {

        { 0, 0 },
    };
    count = sizeof(numberList)/sizeof(wxLuaBindNumber) - 1;
    return numberList;
}

// ---------------------------------------------------------------------------

// wxLuaGetStringList_xword() is called to register #define_string
// ---------------------------------------------------------------------------

wxLuaBindString* wxLuaGetStringList_xword(size_t &count)
{
    static wxLuaBindString stringList[] =
    {

        { 0, 0 },
    };
    count = sizeof(stringList)/sizeof(wxLuaBindString) - 1;
    return stringList;
}

// ---------------------------------------------------------------------------
// wxLuaGetObjectList_xword() is called to register object and pointer bindings
// ---------------------------------------------------------------------------

wxLuaBindObject* wxLuaGetObjectList_xword(size_t &count)
{
    static wxLuaBindObject objectList[] =
    {

        { 0, 0, 0, 0 },
    };
    count = sizeof(objectList)/sizeof(wxLuaBindObject) - 1;
    return objectList;
}

// ---------------------------------------------------------------------------
// wxLuaGetFunctionList_xword() is called to register global functions
// ---------------------------------------------------------------------------

// %override wxLua_function_GetFrame
// MyFrame * GetFrame()
// This is a lua-only function (it can't be accessed through the XWord C++ API)
int wxLua_function_GetFrame(lua_State *L)
{
    MyFrame * frame = wxGetApp().GetFrame();
    if (frame)
        wxluaT_pushuserdatatype(L, frame, wxluatype_MyFrame);
    else
        lua_pushnil(L);        
    return 1; // One object on the stack for lua.
}

static wxLuaBindCFunc s_wxluafunc_wxLua_function_GetFrame[1] = {{ wxLua_function_GetFrame, WXLUAMETHOD_CFUNCTION, 0, 0, g_wxluaargtypeArray_None }};

// %override wxLua_function_logerror
// void logerror(const wxString & msg)
// This is a lua-only function (it can't be accessed through the XWord C++ API)
int wxLua_function_logerror(lua_State *L)
{
    wxGetApp().LogLuaMessage(wxlua_getwxStringtype(L, 1));
    return 0;
}

static wxLuaBindCFunc s_wxluafunc_wxLua_function_logerror[1] = {{ wxLua_function_logerror, WXLUAMETHOD_CFUNCTION, 0, 0, g_wxluaargtypeArray_None }};

// ---------------------------------------------------------------------------
// wxLuaGetFunctionList_xword() is called to register global functions
// ---------------------------------------------------------------------------

wxLuaBindMethod* wxLuaGetFunctionList_xword(size_t &count)
{
    static wxLuaBindMethod functionList[] =
    {
        { "GetFrame", WXLUAMETHOD_CFUNCTION, s_wxluafunc_wxLua_function_GetFrame, 1, NULL },
        { "logerror", WXLUAMETHOD_CFUNCTION, s_wxluafunc_wxLua_function_logerror, 1, NULL },

        { 0, 0, 0, 0 }, 
    };
    count = sizeof(functionList)/sizeof(wxLuaBindMethod) - 1;
    return functionList;
}



// ---------------------------------------------------------------------------
// wxLuaGetClassList_xword() is called to register classes
// ---------------------------------------------------------------------------

static const char* wxluaclassname_MyFrame = "MyFrame";
static const char* wxluaclassname_wxCommandEvent = "wxCommandEvent";
static const char* wxluaclassname_wxFrame = "wxFrame";
static const char* wxluaclassname_wxPuzEvent = "wxPuzEvent";

static const char* wxluabaseclassnames_MyFrame[] = { wxluaclassname_wxFrame, NULL };
static wxLuaBindClass* wxluabaseclassbinds_MyFrame[] = { NULL };
static const char* wxluabaseclassnames_wxPuzEvent[] = { wxluaclassname_wxCommandEvent, NULL };
static wxLuaBindClass* wxluabaseclassbinds_wxPuzEvent[] = { NULL };
// ---------------------------------------------------------------------------
// Lua Tag Method Values and Tables for each Class
// ---------------------------------------------------------------------------

extern wxLuaBindMethod MyFrame_methods[];
extern int MyFrame_methodCount;
extern void wxLua_MyFrame_delete_function(void** p);
extern wxLuaBindMethod wxPuzEvent_methods[];
extern int wxPuzEvent_methodCount;
extern void wxLua_wxPuzEvent_delete_function(void** p);




wxLuaBindClass* wxLuaGetClassList_xword(size_t &count)
{
    static wxLuaBindClass classList[] =
    {
        { wxluaclassname_MyFrame, MyFrame_methods, MyFrame_methodCount, CLASSINFO(MyFrame), &wxluatype_MyFrame, wxluabaseclassnames_MyFrame, wxluabaseclassbinds_MyFrame, NULL, NULL, NULL, 0, &wxLua_MyFrame_delete_function, }, 
        { wxluaclassname_wxPuzEvent, wxPuzEvent_methods, wxPuzEvent_methodCount, CLASSINFO(wxPuzEvent), &wxluatype_wxPuzEvent, wxluabaseclassnames_wxPuzEvent, wxluabaseclassbinds_wxPuzEvent, NULL, NULL, NULL, 0, &wxLua_wxPuzEvent_delete_function, }, 

        { 0, 0, 0, 0, 0, 0, 0 }, 
    };
    count = sizeof(classList)/sizeof(wxLuaBindClass) - 1;

    return classList;
}

// ---------------------------------------------------------------------------
// wxLuaBinding_xword() - the binding class
// ---------------------------------------------------------------------------

IMPLEMENT_DYNAMIC_CLASS(wxLuaBinding_xword, wxLuaBinding)

wxLuaBinding_xword::wxLuaBinding_xword() : wxLuaBinding()
{
    m_bindingName   = wxT("xword");
    m_nameSpace     = wxT("xword");
    m_classArray    = wxLuaGetClassList_xword(m_classCount);
    m_numberArray   = wxLuaGetDefineList_xword(m_numberCount);
    m_stringArray   = wxLuaGetStringList_xword(m_stringCount);
    m_eventArray    = wxLuaGetEventList_xword(m_eventCount);
    m_objectArray   = wxLuaGetObjectList_xword(m_objectCount);
    m_functionArray = wxLuaGetFunctionList_xword(m_functionCount);
    InitBinding();
}



// ---------------------------------------------------------------------------

wxLuaBinding* wxLuaBinding_xword_init()
{
    static wxLuaBinding_xword m_binding;

    if (wxLuaBinding::GetBindingArray().Index(&m_binding) == wxNOT_FOUND)
        wxLuaBinding::GetBindingArray().Add(&m_binding);

    return &m_binding;
}


