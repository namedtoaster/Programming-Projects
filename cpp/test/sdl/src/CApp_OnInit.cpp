#include <iostream>

#include "CApp.h"
#include "CSurface.h"

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

bool CApp::OnInit() {
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

  if ((sdlRenderer = SDL_CreateRenderer(Surf_Window, -1, 0)) == NULL) {
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

    // Set the background color to steel blue
    if ((SDL_SetRenderDrawColor(sdlRenderer, 70, 130, 180, 255)) < 0) {
      printError(SDL_GetError());
      return false;
    }
  }

  // Load the images
  // First, the grid
  if ((Tex_Grid = CSurface::OnLoad("../media/images/png/grid.png", sdlRenderer)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  // Now the X
  if ((Tex_X = CSurface::OnLoad("../media/images/png/x.png", sdlRenderer)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  // Finally the O
  if ((Tex_O = CSurface::OnLoad("../media/images/png/o.png", sdlRenderer)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  //CSurface::Transparent(Surf_X, 255, 0, 255);
  //CSurface::Transparent(Surf_O, 255, 0, 255);

  Reset();
  
  return true;
}
