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
				      SDL_WINDOWPOS_UNDEFINED,
				      SDL_WINDOWPOS_UNDEFINED,
				      1000, 1000,
				      SDL_WINDOW_OPENGL)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

  if ((Surf_Display = SDL_GetWindowSurface(Surf_Window)) == NULL) {
    printError(SDL_GetError());
    return false;
  }

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
