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
				      0, 0,
				      SDL_WINDOW_FULLSCREEN_DESKTOP)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

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
  if ((Tex_Grid = CSurface::OnLoad("../media/images/png/grid.png", sdlRenderer)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  /*if ((Surf_X = CSurface::OnLoad("../media/images/png/x.png")) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  if ((Surf_O = CSurface::OnLoad("../media/images/png/o.png")) == NULL) {
    printError(SDL_GetError());
    return false;
    }*/

  //CSurface::Transparent(Surf_X, 255, 0, 255);
  //CSurface::Transparent(Surf_O, 255, 0, 255);

  Reset();

  // TODO ***********************************************************
  // This is my problem child right meow. For some reason, when I try to load an image
  // and blit it on the screen, the system slows down significantly. The image loads
  // correctly, it just takes forever to manipulate anything
  // TODO ***********************************************************

  // TODO FIXED *****************************************************
  // The above problem was fixed when I used a different .bmp file (which is now
  // removed). I'm not sure what was wrong with that particular file, I may come
  // back to this to figure it out
  // TODO FIXED *****************************************************
  
  // TEST LOAD IMAGE
  /*if ((Surf_Test = CSurface::OnLoad("../media/images/bmp/myimage.bmp")) == NULL) {
    std::cout << SDL_GetError() << std::endl;
    return false;
  }*/
  return true;
}
