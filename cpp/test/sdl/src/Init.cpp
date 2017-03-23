#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>

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

bool App::InitLibs() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0 || !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear")) {
    printError(SDL_GetError());
    return false;
  }
  if (TTF_Init() < 0) {
    printError(SDL_GetError());
    return false;
  }
    
  std::cout << "Libs initialized" << std::endl;
  return true;
}

bool App::InitDisplay() {
  if ((Surf_Window = SDL_CreateWindow("My Game Window",
				 SDL_WINDOWPOS_CENTERED,
				 SDL_WINDOWPOS_CENTERED,
				 1100, 900,
				      SDL_WINDOW_RESIZABLE)) == NULL ||
      (sdlRenderer = SDL_CreateRenderer(Surf_Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
    printError(SDL_GetError());
    return false;
  }
  if ((SDL_RenderSetLogicalSize(sdlRenderer, 600, 600)) < 0) {
    printError(SDL_GetError());
    return false;
  }
  SDL_SetRenderDrawColor(sdlRenderer, 70, 130, 180, 255);

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
    printError(IMG_GetError());
    return false;
  }

  //Initialize SDL_ttf
  if( TTF_Init() == -1) {
    printError(TTF_GetError());
    return false;
  }
  // Use SDL_WINDOW_FULLSCREEN_DESKTOP (set 0 for width/height) to
  // set the game to be fullscreen or SDL_WINDOW_RESIZABLE to make
  // it windowed (set width/height params)

  std::cout << "Display Initialized" << std::endl;
  return true;
}

bool App::InitFonts() {
  if ((LazyFont = TTF_OpenFont("../media/fonts/Lazy.ttf", 40)) == NULL) {
    printError(TTF_GetError());
    return false;
  }
  std::cout << "Fonts initialized" << std::endl;
  return true;
}

bool App::LoadMedia() {
  // Load the images
  // First, the grid
  if ((Surf_Grid = Surface::OnLoad("../media/images/png/grid.png")) == NULL) {
    return false;
  }
  else
    Tex_Grid = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Grid);

  // Now the X
  if ((Surf_X = Surface::OnLoad("../media/images/png/x.png")) == NULL) {
    return false;
  }
  else {
    Surface::Transparent(Surf_X, 255, 0, 255);
    Tex_X = SDL_CreateTextureFromSurface(sdlRenderer, Surf_X);
  }

  // Finally the O
  if ((Surf_O = Surface::OnLoad("../media/images/png/o.png")) == NULL) {
    return false;
  }
  else {
    Surface::Transparent(Surf_O, 255, 0, 255);
    Tex_O = SDL_CreateTextureFromSurface(sdlRenderer, Surf_O);
  }

  // Now load the test text
  SDL_Color color = {255, 0, 0};
  if ((Surf_GameOver = Surface::OnLoad(LazyFont, "Game Over!", color)) == NULL) {
    return false;
  }
  else
    Tex_GameOver = SDL_CreateTextureFromSurface(sdlRenderer, Surf_GameOver);

  std::cout << "Media initialized" << std::endl;
  return true;
}

bool App::OnInit() {  
  if (!InitLibs())
    return false;
  if (!InitDisplay())
    return false;
  if (!InitFonts())
    return false;
  if (!LoadMedia())
    return false;

  Reset();
  
  return true;
}
