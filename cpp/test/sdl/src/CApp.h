#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <string>
#include <iostream>

#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
 private:
  bool Running;
  
  SDL_Window* Surf_Window;
  
  SDL_Surface* Surf_Display;

 private:
  SDL_Surface* Surf_Grid;

  SDL_Surface* Surf_X;
  SDL_Surface* Surf_O;

 private:
  int Grid[9];

  enum {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
  };
  
 public:
  CApp();
  
  int OnExecute();

 public:
  bool OnInit();
  
  void OnEvent(SDL_Event* Event);
  
  void OnLoop();
  
  void OnRender();
  
  void OnCleanup();

  void printError(std::string message) {
    std::cout << message << std::endl;
  }

  void Reset();
};

#endif
