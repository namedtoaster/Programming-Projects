#ifndef SURFACE_H
#define SURFACE_H
 
#include <SDL.h>
#include <SDL_ttf.h>
 
class Surface {
 public:
  Surface();
 
 public:
  static SDL_Texture* OnLoad(char* File, SDL_Renderer* sdlRenderer);
  static SDL_Texture* OnLoad(char* File, int R, int G, int B, SDL_Renderer* sdlRenderer);
  static SDL_Texture* OnLoad(TTF_Font* font, char* text, SDL_Color color, SDL_Renderer* sdlRenderer);
  
  static bool OnDraw(SDL_Renderer* sdlRenderer, SDL_Texture* tex_draw,
		     int X, int Y, int W, int H);
  static bool OnDraw(SDL_Window* Window_Dest,SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src,
		     int X, int Y, int X2, int Y2, int W, int H);
  static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};
 
#endif
