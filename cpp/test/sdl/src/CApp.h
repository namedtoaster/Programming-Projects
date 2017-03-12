#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>

#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
 private:
  bool Running;
  SDL_Window* Surf_Window;
  SDL_Surface* Surf_Display;
  SDL_Surface* Surf_Test;
 public:
  CApp();
  int OnExecute();

 public:
  bool OnInit();
  void OnEvent(SDL_Event* Event);
  void OnLoop();
  void OnRender();
  void OnCleanup();
};

#endif
