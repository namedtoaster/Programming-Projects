#include <iostream>

#include <SDL_image.h> // For now I'll keep this here. But I would prefer to
		       // have it linked in the Makefile if possible
#include "Surface.h"
 
Surface::Surface() {
}
 
SDL_Surface* Surface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;

    // TODO Test what kinda of file is trying to be loaded and call
    // the appropirate function
    
    if((Surf_Temp = IMG_Load(File)) == NULL) {
      std::cout << SDL_GetError() << std::endl;
      return false;
    }
 
    return Surf_Temp;
}

TTF_Font* Surface::OnLoad(char* file, SDL_Color textcolor) {
}

bool Surface::OnDraw(SDL_Renderer* sdlRenderer, SDL_Texture* tex_draw, int X, int Y, int W, int H) {
  if (sdlRenderer == NULL || tex_draw == NULL)
    return false;
 
  SDL_Rect DestR;
 
  DestR.x = X;
  DestR.y = Y;
  DestR.w = W;
  DestR.h = H;

  SDL_RenderCopy(sdlRenderer, tex_draw, NULL, &DestR);

  return true;
}

bool Surface::OnDraw(SDL_Window* Win_Dest, SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src,
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

bool Surface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
  if (Surf_Dest == NULL) {
    return false;
  }

  // SDL_TRUE instead of SDL_SRCCOLORKEY - difference between 1.2-2.0
  SDL_SetColorKey(Surf_Dest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

  return true;
}
