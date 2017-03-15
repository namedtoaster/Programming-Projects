#include <iostream>

#include "CSurface.h"
 
CSurface::CSurface() {
}
 
SDL_Surface* CSurface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    //SDL_Surface* Surf_Return = NULL;

    // TODO Test what kinda of file is trying to be loaded and call
    // the appropirate function
    if((Surf_Temp = IMG_Init(File)) == NULL) {
      // SDL_GetError(); <-- DO SOMETHING HERE
      return NULL;
    }

    // SDL_DisplayFormat(SDL_Surface*) no longer used in SDL 2.0 (see
    // http://stackoverflow.com/questions/17518759/sdl-displayformat-not-declared-in-this-scope-using-sdl2)
    // Instead, use SDL_ConvertSurfaceFormat
    //Surf_Return = SDL_DisplayFormat(Surf_Temp);

    // Leftover code
    //Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp, SDL_PIXELFORMAT_UNKNOWN, 0);
    //SDL_FreeSurface(Surf_Temp);
 
    return Surf_Temp;
}

bool CSurface::OnDraw(SDL_Window* Win_Dest, SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if (Win_Dest == NULL || Surf_Dest == NULL || Surf_Src == NULL) {
      // SDL_GetError(); <-- DO SOMETHING HERE
      return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    if (SDL_UpdateWindowSurface(Win_Dest) < 0) {
      return false;
      // SDL_GetError(); <-- DO SOMETHING HERE
    }

    return true;
}

bool CSurface::OnDraw(SDL_Window* Win_Dest, SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src,
		      int X, int Y, int X2, int Y2, int W, int H) {
  if (Win_Dest == NULL || Surf_Dest == NULL || Surf_Src == NULL) {
    return false;
  }

  SDL_Rect DestR;

  DestR.x = X;
  DestR.y = Y;

  SDL_Rect SrcR;

  SrcR.x = X2;
  SrcR.y = Y2;
  SrcR.w = W;
  SrcR.h = H;

  SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
  
  if (SDL_UpdateWindowSurface(Win_Dest) < 0) {
    // SDL_GetError() <-- DO SOMETHING HERE
    return false;
  }

  return true;
}
