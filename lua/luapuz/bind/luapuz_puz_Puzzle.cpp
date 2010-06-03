// ---------------------------------------------------------------------------
// luapuz_puz_Puzzle.cpp was generated by puzbind.lua
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "../luapuz_functions.hpp"
#include "../luapuz_tracking.hpp"

#include "luapuz_puz_Puzzle_helpers.hpp"
#include "luapuz_puz_Puzzle.hpp"
#include "luapuz_puz_Grid.hpp"
// ---------------------------------------------------------------------------
// class Puzzle
// ---------------------------------------------------------------------------



const char * Puzzle_meta = "puz.Puzzle";

// Create a new userdata with actual data and push it on the stack.
// The userdata will be tracked in the tracked objects table.
LUAPUZ_API void luapuz_newPuzzle(lua_State * L,
                               puz::Puzzle * puzzle,
                               bool should_gc)
{
    // Create the userdata
    Puzzle_ud * ud =
        (Puzzle_ud *)lua_newuserdata(L, sizeof(Puzzle_ud));

    ud->should_gc = should_gc;

    // Set the data member
    ud->puzzle = puzzle;

    // Set the metatable
    luaL_getmetatable(L, Puzzle_meta);
    lua_setmetatable(L, -2);

    // Track the object
    luapuz_track_object(L, puzzle);
}



// Delete the data on garbage collection
int Puzzle_gc(lua_State * L)
{
#ifdef LUAPUZ_DEBUG
    std::cout << "Garbage collecting puz::Puzzle ";
#endif
    Puzzle_ud * ud = luapuz_checkPuzzle_ud(L, 1);
    luapuz_untrack_object(L, ud->puzzle);
    if (ud->should_gc)
    {
        delete ud->puzzle;
#ifdef LUAPUZ_DEBUG
        std::cout << "and deleting data" << std::endl;
#endif
    }
    else
    {
#ifdef LUAPUZ_DEBUG
        //std::cout << "but not deleting data" << std::endl;
#endif
    }
    return 0;
}

// tostring() -> userdata 0xHHHHH (puz.Puzzle 0xHHHH)
int Puzzle_tostring(lua_State * L)
{
    Puzzle_ud * ud = luapuz_checkPuzzle_ud(L, 1);
    lua_pushfstring(L, "userdata: %p (%s: %p gc = %s)", ud, Puzzle_meta, ud->puzzle, ud->should_gc ? "true" : "false");
    return 1;
}

// Puzzle functions
//----------------
// Puzzle()
// Puzzle(const std::string & filename)
// Puzzle(const std::string & filename, const std::string & ext)
// Puzzle(const std::string & filename, FileHandlerDesc * desc)
int Puzzle_Puzzle(lua_State * L)
{
    try {
        puz::Puzzle * returns;

        // metatable is first argument
        int argCount = lua_gettop(L) - 1;
        if (argCount >= 2)
        {
            std::string filename = luapuz_checkStdString(L, 2);
            if (lua_isstring(L, 3))
            {
                std::string ext = luapuz_checkStdString(L, 3);
                returns = new puz::Puzzle(filename, ext);
            }
            else if (lua_isfunction(L, 3))
            {
                // make sure the function is on top of the stack
                lua_pushvalue(L, 3);
                luapuz_LoadSaveData luapuzdata(L);

                // Create the puz::Puzzle file handler
                puz::Puzzle::FileHandlerDesc desc;
                desc.data = &luapuzdata;
                desc.handler = luapuz_LoadSave_Puzzle;

                returns = new puz::Puzzle(filename, &desc);

                // Clean up our data pointer
                luapuzdata.unref();
            }
            else
            {
                luaL_typerror(L, 3, "string or function");
            }
        }
        else if (argCount >= 1)
        {
            std::string filename = luapuz_checkStdString(L, 2);
            returns = new puz::Puzzle(filename);

        }
        else if (argCount >= 0)
        {
            returns = new puz::Puzzle();
        }

        luapuz_newPuzzle(L, returns);
        if (returns->HasError())
        {
            lua_pushstring(L, returns->GetError().c_str());
            returns->ClearError();
            return 2;
        }
        else
        {
            return 1;
        }
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return 0;
}
// void Load(const std::string & filename)
// void Load(const std::string & filename, const std::string & ext)
// void Load(const std::string & filename, FileHandlerDesc * desc)
int Puzzle_Load(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string filename = luapuz_checkStdString(L, 2);
    try {
        int argCount = lua_gettop(L) - 1;
        if (argCount >= 2)
        {
            if (lua_isstring(L, 3))
            {
                std::string ext = luapuz_checkStdString(L, 3);
                puzzle->Load(filename, ext);
            }
            else if (lua_isfunction(L, 3))
            {
                // make sure the function is on top of the stack
                lua_pushvalue(L, 3);
                luapuz_LoadSaveData luapuzdata(L);

                // Create the puz::Puzzle file handler
                puz::Puzzle::FileHandlerDesc desc;
                desc.data = &luapuzdata;
                desc.handler = luapuz_LoadSave_Puzzle;

                puzzle->Load(filename, &desc);

                // Clean up our data pointer
                luapuzdata.unref();
            }
            else
            {
                luaL_typerror(L, 3, "string or function");
            }
        }
        else
        {
            puzzle->Load(filename);
        }

        if (puzzle->HasError())
        {
            lua_pushstring(L, puzzle->GetError().c_str());
            puzzle->ClearError();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return 0;
}// void Save(const std::string & filename)
// void Save(const std::string & filename, const std::string & ext)
// void Save(const std::string & filename, FileHandlerDesc * desc)
int Puzzle_Save(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string filename = luapuz_checkStdString(L, 2);
    try {
        int argCount = lua_gettop(L) - 1;
        if (argCount >= 2)
        {
            if (lua_isstring(L, 3))
            {
                std::string ext = luapuz_checkStdString(L, 3);
                puzzle->Save(filename, ext);
            }
            else if (lua_isfunction(L, 3))
            {
                // make sure the function is on top of the stack
                lua_pushvalue(L, 3);
                luapuz_LoadSaveData luapuzdata(L);

                // Create the puz::Puzzle file handler
                puz::Puzzle::FileHandlerDesc desc;
                desc.data = &luapuzdata;
                desc.handler = luapuz_LoadSave_Puzzle;

                puzzle->Save(filename, &desc);

                // Clean up our data pointer
                luapuzdata.unref();
            }
            else
            {
                luaL_typerror(L, 3, "string or function");
            }
        }
        else
        {
            puzzle->Save(filename);
        }

        if (puzzle->HasError())
        {
            lua_pushstring(L, puzzle->GetError().c_str());
            puzzle->ClearError();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return 0;
}
// static void AddLoadHandler(FileHandler func, const char * ext, void * data)
int Puzzle_AddLoadHandler(lua_State * L)
{
    if (! lua_isfunction(L, 1))
        luaL_typerror(L, 1, "function");
    const char * ext = luaL_checkstring(L, 2);

    // Push the function for luapuz_LoadSaveData
    lua_pushvalue(L, 1);
    luapuz_newLoadSaveData(L);

    puz::Puzzle::AddLoadHandler(luapuz_LoadSave_Puzzle,
                                ext,
                                luapuz_checkLoadSaveData(L, -1));
    return 0;
}
// static void AddSaveHandler(FileHandler func, const char * ext, void * data)
int Puzzle_AddSaveHandler(lua_State * L)
{
    if (! lua_isfunction(L, 1))
        luaL_typerror(L, 1, "function");
    const char * ext = luaL_checkstring(L, 2);

    // Push the function for luapuz_LoadSaveData
    lua_pushvalue(L, 1);
    luapuz_newLoadSaveData(L);

    puz::Puzzle::AddSaveHandler(luapuz_LoadSave_Puzzle,
                                ext,
                                luapuz_checkLoadSaveData(L, -1));
    return 0;
}
// static bool CanLoad(std::string filename)
static int Puzzle_CanLoad(lua_State * L)
{
    std::string filename = luapuz_checkStdString(L, 1);
    bool returns = puz::Puzzle::CanLoad(filename);
    lua_pushboolean(L, returns);
    return 1;
}
// static bool CanSave(std::string filename)
static int Puzzle_CanSave(lua_State * L)
{
    std::string filename = luapuz_checkStdString(L, 1);
    bool returns = puz::Puzzle::CanSave(filename);
    lua_pushboolean(L, returns);
    return 1;
}
// short GetVersion()
static int Puzzle_GetVersion(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    short returns = puzzle->GetVersion();
    lua_pushnumber(L, returns);
    return 1;
}
// bool IsScrambled()
static int Puzzle_IsScrambled(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    bool returns = puzzle->IsScrambled();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsOk()
static int Puzzle_IsOk(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    bool returns = puzzle->IsOk();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetOk(bool ok)
static int Puzzle_SetOk(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    bool ok = luapuz_checkboolean(L, 2);
    puzzle->SetOk(ok);
    return 0;
}
// bool IsTimerRunning()
static int Puzzle_IsTimerRunning(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    bool returns = puzzle->IsTimerRunning();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetTimerRunning(bool running)
static int Puzzle_SetTimerRunning(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    bool running = luapuz_checkboolean(L, 2);
    puzzle->SetTimerRunning(running);
    return 0;
}
// std::string GetAuthor()
static int Puzzle_GetAuthor(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string returns = puzzle->GetAuthor();
    luapuz_pushStdString(L, returns);
    return 1;
}
// void SetAuthor(std::string author)
static int Puzzle_SetAuthor(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string author = luapuz_checkStdString(L, 2);
    puzzle->SetAuthor(author);
    return 0;
}
// std::string GetTitle()
static int Puzzle_GetTitle(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string returns = puzzle->GetTitle();
    luapuz_pushStdString(L, returns);
    return 1;
}
// void SetTitle(std::string title)
static int Puzzle_SetTitle(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string title = luapuz_checkStdString(L, 2);
    puzzle->SetTitle(title);
    return 0;
}
// std::string GetCopyright()
static int Puzzle_GetCopyright(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string returns = puzzle->GetCopyright();
    luapuz_pushStdString(L, returns);
    return 1;
}
// void SetCopyright(std::string copyright)
static int Puzzle_SetCopyright(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string copyright = luapuz_checkStdString(L, 2);
    puzzle->SetCopyright(copyright);
    return 0;
}
// int GetTime()
static int Puzzle_GetTime(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    int returns = puzzle->GetTime();
    lua_pushnumber(L, returns);
    return 1;
}
// void SetTime(int time)
static int Puzzle_SetTime(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    int time = luaL_checknumber(L, 2);
    puzzle->SetTime(time);
    return 0;
}
// std::string GetNotes()
static int Puzzle_GetNotes(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string returns = puzzle->GetNotes();
    luapuz_pushStdString(L, returns);
    return 1;
}
// void SetNotes(std::string notes)
static int Puzzle_SetNotes(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    std::string notes = luapuz_checkStdString(L, 2);
    puzzle->SetNotes(notes);
    return 0;
}
// Grid & GetGrid()
static int Puzzle_GetGrid(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Grid * returns = &puzzle->GetGrid();
    luapuz_pushGrid(L, returns);
    return 1;
}
// void SetGrid(puz::Grid & grid)
static int Puzzle_SetGrid(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Grid * grid = luapuz_checkGrid(L, 2);
    puzzle->SetGrid(*grid);
    return 0;
}
// ClueList & GetAcross()
static int Puzzle_GetAcross(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Puzzle::ClueList * returns = &puzzle->GetAcross();
    luapuz_pushClueList(L, returns);
    return 1;
}
// ClueList & GetDown()
static int Puzzle_GetDown(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Puzzle::ClueList * returns = &puzzle->GetDown();
    luapuz_pushClueList(L, returns);
    return 1;
}
// void SetAcross(puz::Puzzle::ClueList & cluelist)
static int Puzzle_SetAcross(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Puzzle::ClueList cluelist;
    luapuz_checkClueList(L, 2, &cluelist);
    puzzle->SetAcross(cluelist);
    return 0;
}
// void SetDown(puz::Puzzle::ClueList & cluelist)
static int Puzzle_SetDown(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puz::Puzzle::ClueList cluelist;
    luapuz_checkClueList(L, 2, &cluelist);
    puzzle->SetDown(cluelist);
    return 0;
}
// void RenumberClues()
static int Puzzle_RenumberClues(lua_State * L)
{
    puz::Puzzle * puzzle = luapuz_checkPuzzle(L, 1);
    puzzle->RenumberClues();
    return 0;
}
static const luaL_reg Puzzlelib[] = {
    {"Load", Puzzle_Load},
    {"Save", Puzzle_Save},
    {"AddLoadHandler", Puzzle_AddLoadHandler},
    {"AddSaveHandler", Puzzle_AddSaveHandler},
    {"CanLoad", Puzzle_CanLoad},
    {"CanSave", Puzzle_CanSave},
    {"GetVersion", Puzzle_GetVersion},
    {"IsScrambled", Puzzle_IsScrambled},
    {"IsOk", Puzzle_IsOk},
    {"SetOk", Puzzle_SetOk},
    {"IsTimerRunning", Puzzle_IsTimerRunning},
    {"SetTimerRunning", Puzzle_SetTimerRunning},
    {"GetAuthor", Puzzle_GetAuthor},
    {"SetAuthor", Puzzle_SetAuthor},
    {"GetTitle", Puzzle_GetTitle},
    {"SetTitle", Puzzle_SetTitle},
    {"GetCopyright", Puzzle_GetCopyright},
    {"SetCopyright", Puzzle_SetCopyright},
    {"GetTime", Puzzle_GetTime},
    {"SetTime", Puzzle_SetTime},
    {"GetNotes", Puzzle_GetNotes},
    {"SetNotes", Puzzle_SetNotes},
    {"GetGrid", Puzzle_GetGrid},
    {"SetGrid", Puzzle_SetGrid},
    {"GetAcross", Puzzle_GetAcross},
    {"GetDown", Puzzle_GetDown},
    {"SetAcross", Puzzle_SetAcross},
    {"SetDown", Puzzle_SetDown},
    {"RenumberClues", Puzzle_RenumberClues},
    {NULL, NULL}
};


// typedef ClueList
//------------

void luapuz_checkClueList(lua_State * L, int index, puz::Puzzle::ClueList * clues)
{
    luaL_checktype(L, index, LUA_TTABLE);

    clues->clear();

    // Iterate the table
    lua_pushnil(L);  /* first key */
    while (lua_next(L, index) != 0)
    {
        // key is index -2
        // value is index -1
        int number = luapuz_checkuint(L, -2);
        std::string text = luapuz_checkStdString(L, -1);
        clues->push_back(puz::Puzzle::Clue(number, text));

        /* removes 'value'; keeps 'key' for next iteration */
        lua_pop(L, 1);
    }

    // Sort the clues, because there is no guarantee that the lua table is
    // sorted.
    std::sort(clues->begin(), clues->end());
}

int luapuz_pushClueList(lua_State * L, puz::Puzzle::ClueList * clues)
{
    // The clue table
    lua_newtable(L);

    for (puz::Puzzle::ClueList::const_iterator it = clues->begin();
         it != clues->end();
         ++it)
    {
        // t[number] = text
        lua_pushnumber(L, it->Number());
        luapuz_pushStdString(L, it->Text());
        lua_settable(L, -3);
    }

    return 1;
}

const luaL_reg staticPuzzlelib[] = {
    {"AddLoadHandler", Puzzle_AddLoadHandler},
    {"AddSaveHandler", Puzzle_AddSaveHandler},
    {"CanLoad", Puzzle_CanLoad},
    {"CanSave", Puzzle_CanSave},
    {NULL, NULL}
};

const luaL_reg classPuzzlelib[] = {
    { "__gc",        Puzzle_gc },
    { "__index",     luapuz_index },
    { "__newindex",  luapuz_newindex },
    { "__tostring",  Puzzle_tostring },
    { NULL, NULL }
};

void luapuz_openPuzzlelib (lua_State *L) {
    luaL_newmetatable(L, Puzzle_meta);

    // register metatable functions
    luaL_register(L, NULL, Puzzlelib);
    luaL_register(L, NULL, classPuzzlelib);

    // remove metatable from stack
    lua_pop(L, 1);

    // puz.Puzzle table
    lua_newtable(L);
    luaL_register(L, NULL, staticPuzzlelib);
    // Register constructor
    luapuz_registerConstructor(L, Puzzle_Puzzle);
    // puz.Puzzle = the table
    lua_setfield(L, -2, "Puzzle");
}