module canvas;

#include <lua.hpp>

namespace canvas
{
  template <auto fn>
  using c_delete = integral_constant<decay_t<decltype (fn)>, fn>;

  void
  lua_init ()
  {
    // The type (despite its name) refers to a thread. (Indirectly, through the
    // thread, it also refers to the Lua state associated to it.)
    //
    using lua_state = unique_ptr<lua_State, c_delete<lua_close>>;

    lua_state s (luaL_newstate ());

    luaopen_base (s.get());

    if (luaL_dofile (s.get (), "/home/wroy/Projects/canvas/libcanvas/tests/basics/driver.lua"))
      {
        println ("{}", lua_tostring (s.get(), -1));
      }
  }
}
