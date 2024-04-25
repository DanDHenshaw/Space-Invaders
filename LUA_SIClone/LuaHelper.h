/* Lua helper which link lua with C++ */

#pragma once

#include <assert.h>
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

#pragma region Get functions from Lua

  int CallRandomNumber(lua_State* luaState, const std::string& fname);

  void CallMovement(lua_State* luaState, const std::string& fname, float move_speed, float& value, float& frameValue);
  void CallReturnInt(lua_State* luaState, const std::string& fname, int& value);

#pragma endregion

#pragma region Call C++ functions from Lua

  void CallVoidVoidCFunc(lua_State* luaState, const std::string& fname);

  void CallVoidPassIntCFunc(lua_State* luaState, const std::string& fname, int value);

  // middle man between C++ and Lua. Register a function to be called from Lua
  class Dispatcher
  {
  public:
    // capture game functions here
    struct Command
    {
      typedef std::function<void(int)> voidintfunc; // a function which returns nothing and takes an int
      voidintfunc voidintfunct;
    };

    // call once at start
    void Init(lua_State* luaState)
    {
      lua_register(luaState, "CDispatcher", LuaCall);
    }

    // register game functions
    void Register(const std::string& name, Command cmd)
    {
      assert(library.find(name) == library.end());
        library[name] = cmd;
    }

    // Lua call this then the data gets dispatched to the named function
    static int LuaCall(lua_State* luaState);

  private:
    static std::map<std::string, Command> library; // this is where the game functions are stored
  };

#pragma endregion

}
