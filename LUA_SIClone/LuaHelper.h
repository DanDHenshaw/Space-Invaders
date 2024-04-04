/* Lua helper which link lua with C++ */

#pragma once

#include <string>
#include <functional>
#include <map>

extern "C"
{
#include "../lua-5.4.4/include/lua.h"
#include "../lua-5.4.4/include/lauxlib.h"
#include "../lua-5.4.4/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "../lua-5.4.4/liblua54.a")
#endif // _WIN32

namespace LUA 
{
	using namespace std;

	// check for errors
	bool IsOK(lua_State* luaState, int id);

	#pragma region Get Values from Lua

	// get an int
	int GetInt(lua_State* luaState, const string& name);

	// get a float
	float GetFloat(lua_State* luaState, const string& name);

	// get a double
	double GetDouble(lua_State* luaState, const string& name);

	// get a bool
	bool GetBool(lua_State* luaState, const string& name);

	// get a string
	string GetStr(lua_State* luaState, const string& name);

	#pragma endregion

#pragma region Get Value from Objects

  struct Vector2
  {
    int x, y;

    void FromLua(lua_State* luaState, const std::string& name);
  };

#pragma endregion
}
