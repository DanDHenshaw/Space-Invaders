#include "LuaHelper.h"

#include <assert.h>
#include <iostream>

namespace LUA 
{
    bool IsOK(lua_State* luaState, int id)
    {
        if (id != LUA_OK)
        {
            std::cout << lua_tostring(luaState, -1) << std::endl; // print error to console
            return false;
        }
        return true;
    }

#pragma region Get Values from Lua

    int GetInt(lua_State* luaState, const string& name)
    {
        lua_getglobal(luaState, name.c_str());
        if (!lua_isinteger(luaState, -1))
            assert(false);
        return (int)lua_tointeger(luaState, -1);
    }

    float GetFloat(lua_State* luaState, const string& name)
    {
        lua_getglobal(luaState, name.c_str());
        float num = lua_tonumber(luaState, -1);
        if (num == (float)num)
            return num;
        assert(false);
    }

    double GetDouble(lua_State* luaState, const string& name)
    {
        lua_getglobal(luaState, name.c_str());
        float num = lua_tonumber(luaState, -1);
        if (num == (double)num)
            return num;
        assert(false);
    }

    bool GetBool(lua_State* luaState, const string& name)
    {
        lua_getglobal(luaState, name.c_str());
        if (!lua_isboolean(luaState, -1))
            assert(false);
        return (bool)lua_toboolean(luaState, -1);
    }

    string GetStr(lua_State* luaState, const string& name)
    {
        lua_getglobal(luaState, name.c_str());
        if (!lua_isstring(luaState, -1))
            assert(false);
        return lua_tostring(luaState, -1);
    }

#pragma endregion

#pragma region Get Value from Objects

  // Vector 2
      void Vector2::FromLua(lua_State* luaState, const std::string& name)
      {
        lua_getglobal(luaState, name.c_str());
        if (!lua_istable(luaState, -1))
          assert(false);

        lua_pushstring(luaState, "x");
        lua_gettable(luaState, -2);
        x = (int)lua_tointeger(luaState, -1);
        lua_pop(luaState, 1);

        lua_pushstring(luaState, "y");
        lua_gettable(luaState, -2);
        y = (int)lua_tointeger(luaState, -1);
        lua_pop(luaState, 1);
      };

#pragma endregion

}