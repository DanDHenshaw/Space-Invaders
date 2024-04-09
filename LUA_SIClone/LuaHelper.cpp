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
  }

#pragma endregion

#pragma region Get functions from Lua

  int CallRandomNumber(lua_State* luaState, const std::string& fname)
  {
    lua_getglobal(luaState, fname.c_str());

    if (!lua_isfunction(luaState, -1))
      assert(false);

    if (!IsOK(luaState, lua_pcall(luaState, 0, 1, 0))) // calls a function in protected mode. (state, number of parameters, number of return values, errorfunc)
      assert(false);

    int result = (int)lua_tointeger(luaState, -1);
    lua_pop(luaState, 1);
    return result;
  }

  void CallMoveRight(lua_State* luaState, const std::string& fname, float& xValue, float& frameValue)
  {
    lua_getglobal(luaState, fname.c_str());

    if (!lua_isfunction(luaState, -1))
      assert(false);

    lua_pushnumber(luaState, xValue);
    lua_pushnumber(luaState, frameValue);

    if (!IsOK(luaState, lua_pcall(luaState, 2, 2, 0))) // calls a function in protected mode. (state, number of parameters, number of return values, errorfunc)
      assert(false);

    xValue = (float)lua_tonumber(luaState, -2);
    frameValue = (float)lua_tonumber(luaState, -1);
    lua_pop(luaState, 2);
  }

#pragma endregion

#pragma region Call C++ functions from Lua

  void CallVoidVoidCFunc(lua_State* luaState, const std::string& fname)
  {
    lua_getglobal(luaState, fname.c_str());

    if (!lua_isfunction(luaState, -1))
      assert(false);

    if (!IsOK(luaState, lua_pcall(luaState, 0, 0, 0))) // calls a function in protected mode. (state, number of parameters, number of return values, errorfunc)
      assert(false);
  }

  std::map<std::string, Dispatcher::Command> Dispatcher::library;

  int Dispatcher::LuaCall(lua_State* luaState)
  {
    std::string name = lua_tostring(luaState, 1);
    std::map<std::string, Command>::iterator it = library.find(name);
    assert(it != library.end());
    Command& cmd = (*it).second;

    if (cmd.voidintfunct)
    {
      int param = lua_tointeger(luaState, 2);
      cmd.voidintfunct(param);
      lua_pop(luaState, 1);
    }
    else // add more cases...
      assert(false);

    return 1;
  }

#pragma endregio

}