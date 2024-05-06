import canvas;

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

int
main (int argc, char* argv[])
{
  using namespace canvas;

  if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
      println (cerr, "Error: %s\n", SDL_GetError ());
      return -1;
    }

  SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK,
                       SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 0);

#ifdef SDL_HINT_IME_SHOW_UI
  SDL_SetHint (SDL_HINT_IME_SHOW_UI, "1");
#endif

#ifdef SDL_HINT_SHUTDOWN_DBUS_ON_QUIT
  SDL_SetHint(SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1");
#endif

  SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute (SDL_GL_STENCIL_SIZE, 8);

  const auto create (SDL_CreateWindow);
  const auto window (create ("Canvas", 1280, 720,
                             bit_cast<SDL_WindowFlags> (SDL_WINDOW_OPENGL |
                                                        SDL_WINDOW_RESIZABLE)));
  if (window == nullptr)
    {
      println (cerr, "Error: SDL_CreateWindow(): {}", SDL_GetError ());
      return -1;
    }

  SDL_GLContext gl_context (SDL_GL_CreateContext (window));
  SDL_GL_MakeCurrent (window, gl_context);
  SDL_GL_SetSwapInterval (1);

  [&] ()
  {
    while (true)
      {
        SDL_Event event;

        while (SDL_PollEvent (&event) != 0)
          {
            switch (event.type)
              {
              case SDL_EVENT_QUIT:
                return; // break out from inner loop.
              default:;
              }
          }

        SDL_GL_SwapWindow (window);
      }
  }();

  SDL_GL_DeleteContext (gl_context);
  SDL_DestroyWindow (window);
  SDL_Quit ();
}
