#include <iostream>

#include "App.h"
#include "Surface.h"

Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
// TODO: For some reason, I get a compiler error when running this
// (with the current Makefile) that says "'rmask' does not name a
// type" and so on for g,b, and a. Figure out how to fix this!
/*#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;*/
#endif

// TODO Set global? variable for width and height to be used in the
// window and surface initializations

bool App::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printError(SDL_GetError());
    return false;
  }

  if ((Surf_Window = SDL_CreateWindow("My Game Window",
				      SDL_WINDOWPOS_CENTERED,
				      SDL_WINDOWPOS_CENTERED,
				      700, 500,
				      SDL_WINDOW_RESIZABLE)) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  // Use SDL_WINDOW_FULLSCREEN_DESKTOP (set 0 for width/height) to
  // set the game to be fullscreen or SDL_WINDOW_RESIZABLE to make
  // it windowed (set width/height params)

  if ((sdlRenderer = SDL_CreateRenderer(Surf_Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  else {
    // Not really sure what the following does, but it was outlined in the
    // migration guide as something you might want to do. Also, I don't know if
    // you are supposed to do this on every loop or if you can just be one and
    // done (initialize it)
    if ((SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear")) < 0) {
      printError(SDL_GetError());
      return false;
    }
    
    if ((SDL_RenderSetLogicalSize(sdlRenderer, 600, 600)) < 0) {
      printError(SDL_GetError());
      return false;
    }
  }

  // Load the images
  // First, the grid
  if ((Surf_Grid = Surface::OnLoad("../media/images/png/grid.png")) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  Tex_Grid = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Grid);

  // Now the X
  if ((Surf_X = Surface::OnLoad("../media/images/png/x.png")) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  Surface::Transparent(Surf_X, 255, 0, 255);
  Tex_X = SDL_CreateTextureFromSurface(sdlRenderer, Surf_X);

  // Finally the O
  if ((Surf_O = Surface::OnLoad("../media/images/png/o.png")) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  Surface::Transparent(Surf_O, 255, 0, 255);
  Tex_O = SDL_CreateTextureFromSurface(sdlRenderer, Surf_O);

  Reset();
  
  return true;
}
