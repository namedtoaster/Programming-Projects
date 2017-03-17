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
  SDL_Renderer* sdlRenderer;
  //SDL_Surface* Surf_Display;
  
 private:
  SDL_Surface* Surf_Grid;
  SDL_Texture* Tex_Grid;

  SDL_Surface* Surf_X;
  SDL_Texture* Tex_X;
  
  SDL_Surface* Surf_O;
  SDL_Texture* Tex_O;

 private:
  int Grid[9];

  enum {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
  };

  int CurrentPlayer;
  
 public:
  CApp();
  
  int OnExecute();

 public:
  bool OnInit();
  
  void OnEvent(SDL_Event* Event);
  void OnLButtonDown(int mX, int mY);

  bool PlayerWin();
  void DeclareWinner();
  void ContinueGame();
  void OnLoop();
  
  void OnRender();
  
  void OnCleanup();

  void printError(std::string message) {
    std::cout << message << std::endl;
  }

  void Reset();
  void SetCell(int ID, int Type);
};

#endif
