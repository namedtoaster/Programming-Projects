#include <iostream>

#include "SDL_image.h" // For now I'll keep this here. But I would prefer to
		       // have it linked in the Makefile if possible
#include "CSurface.h"
 
CSurface::CSurface() {
}
 
SDL_Texture* CSurface::OnLoad(char* File, SDL_Renderer* sdlRenderer) {
    SDL_Texture* Tex_Temp = NULL;

    // TODO Test what kinda of file is trying to be loaded and call
    // the appropirate function
    
    if((Tex_Temp = IMG_LoadTexture(sdlRenderer, File)) == NULL) {
      std::cout << SDL_GetError() << std::endl;
      return false;
    }
 
    return Tex_Temp;
}

bool CSurface::OnDraw(SDL_Renderer* sdlRenderer, SDL_Texture* tex_draw, int X, int Y) {
  if (sdlRenderer == NULL || tex_draw == NULL)
    return false;
  /*if (Win_Dest == NULL || Surf_Dest == NULL || Surf_Src == NULL) {
    // SDL_GetError(); <-- DO SOMETHING HERE
    return false;
    }*/
 
  SDL_Rect DestR;
 
  DestR.x = X;
  DestR.y = Y;


  SDL_RenderCopy(sdlRenderer, tex_draw, NULL, NULL);

    
  /*SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
  if (SDL_UpdateWindowSurface(Win_Dest) < 0) {
    return false;
    // SDL_GetError(); <-- DO SOMETHING HERE
    }*/

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

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
  if (Surf_Dest == NULL) {
    return false;
  }

  // SDL_TRUE instead of SDL_SRCCOLORKEY - difference between 1.2-2.0
  SDL_SetColorKey(Surf_Dest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

  return true;
}
