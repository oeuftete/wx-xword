// ---------------------------------------------------------------------------
// luapuz_puz.cpp was generated by puzbind.lua
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

// ---------------------------------------------------------------------------
// namespace puz
// ---------------------------------------------------------------------------

#include "luapuz_puz_Grid.hpp"
#include "luapuz_puz_Puzzle.hpp"
#include "luapuz_puz_Square.hpp"
#include "luapuz_puz.hpp"
// GridDirection SwapDirection(puz::GridDirection dir)
static int puz_SwapDirection(lua_State * L)
{
    puz::GridDirection dir = luapuz_checkGridDirection(L, 1);
    puz::GridDirection returns = SwapDirection(dir);
    luapuz_pushGridDirection(L, returns);
    return 1;
}
static const luaL_reg puzlib[] = {
    {"SwapDirection", puz_SwapDirection},
    {NULL, NULL}
};


// enum GridDirection
//------------

const char * GridDirection_meta = "puz.GridDirection";

const luapuz_enumReg GridDirection_reg[] = {
    {"NONE", puz::NONE},
    {"ACROSS", puz::ACROSS},
    {"DOWN", puz::DOWN},
    {NULL, NULL}
};


// enum FindDirection
//------------

const char * FindDirection_meta = "puz.FindDirection";

const luapuz_enumReg FindDirection_reg[] = {
    {"PREV", puz::PREV},
    {"NEXT", puz::NEXT},
    {NULL, NULL}
};


// enum GextFlag
//------------

const char * GextFlag_meta = "puz.GextFlag";

const luapuz_enumReg GextFlag_reg[] = {
    {"FLAG_CLEAR", puz::FLAG_CLEAR},
    {"FLAG_PENCIL", puz::FLAG_PENCIL},
    {"FLAG_BLACK", puz::FLAG_BLACK},
    {"FLAG_X", puz::FLAG_X},
    {"FLAG_RED", puz::FLAG_RED},
    {"FLAG_CIRCLE", puz::FLAG_CIRCLE},
    {NULL, NULL}
};


// enum CheckTest
//------------

const char * CheckTest_meta = "puz.CheckTest";

const luapuz_enumReg CheckTest_reg[] = {
    {"NO_CHECK_BLANK", puz::NO_CHECK_BLANK},
    {"CHECK_BLANK", puz::CHECK_BLANK},
    {NULL, NULL}
};


// enum GridFlag
//------------

const char * GridFlag_meta = "puz.GridFlag";

const luapuz_enumReg GridFlag_reg[] = {
    {"FLAG_NORMAL", puz::FLAG_NORMAL},
    {"FLAG_NO_SOLUTION", puz::FLAG_NO_SOLUTION},
    {"FLAG_SCRAMBLED", puz::FLAG_SCRAMBLED},
    {NULL, NULL}
};


// enum GridType
//------------

const char * GridType_meta = "puz.GridType";

const luapuz_enumReg GridType_reg[] = {
    {"TYPE_NORMAL", puz::TYPE_NORMAL},
    {"TYPE_DIAGRAMLESS", puz::TYPE_DIAGRAMLESS},
    {NULL, NULL}
};

void luapuz_openpuzlib (lua_State *L) {
    // register functions
    luaL_register(L, "puz", puzlib);
    luapuz_registerEnum(L, GridDirection_meta, GridDirection_reg);
    luapuz_registerEnum(L, FindDirection_meta, FindDirection_reg);
    luapuz_registerEnum(L, GextFlag_meta, GextFlag_reg);
    luapuz_registerEnum(L, CheckTest_meta, CheckTest_reg);
    luapuz_registerEnum(L, GridFlag_meta, GridFlag_reg);
    luapuz_registerEnum(L, GridType_meta, GridType_reg);
    luapuz_openSquarelib(L);
    luapuz_openGridlib(L);
    luapuz_openPuzzlelib(L);
    lua_pop(L, 1);
}