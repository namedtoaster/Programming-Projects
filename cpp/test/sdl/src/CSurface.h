#ifndef CSURFACE_H
#define CSURFACE_H
 
#include <SDL.h>
 
class CSurface {
 public:
  CSurface();
 
 public:
  static SDL_Texture* OnLoad(char* File, SDL_Renderer* renderer);
  static bool OnDraw(SDL_Renderer* sdlRenderer, SDL_Texture* tex_draw, int X, int Y);
  static bool OnDraw(SDL_Window* Window_Dest,SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src,
		     int X, int Y, int X2, int Y2, int W, int H);
  static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};
 
#endif
