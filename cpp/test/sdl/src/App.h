#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <string>
#include <iostream>

#include "Event.h"
#include "Surface.h"

class App : public Event {
 private:
  bool Running;
  
  SDL_Window* Surf_Window;
  SDL_Renderer* sdlRenderer;
  //SDL_Surface* Surf_Display;

  int DISPLAY_W = 1000;
  int DISPLAY_H = 1000;
  int MARGIN = 200;
  bool Fullscreen = false;
  
 private:
  SDL_Texture* Tex_Grid;

  SDL_Texture* Tex_X;
  
  SDL_Texture* Tex_O;

  SDL_Texture* Tex_GameOver;
  int GO_W, GO_H;
  
  TTF_Font* LazyFont;
 private:
  bool IsGameOver;
  int Grid[9];

  enum {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
  };

  int CurrentPlayer;
  
 public:
  App();
  void SetFullscreen() { Fullscreen = true; }

 public:  
  bool InitLibs();
  bool InitDisplay();
  bool InitFonts();
  bool LoadMedia();

 public:
  bool OnInit();
  int OnExecute();
  void OnLoop();
  void OnRender();
  void OnCleanup();

  void OnEvent(SDL_Event* Event);
  void OnLButtonDown(int mX, int mY);

 public:
  bool PlayerWin();
  void DeclareWinner();
  void ContinueGame();
  void GameOver();
  bool SetCell(int ID, int Type);

 public:
  void printError(std::string message) {
    std::cout << "Error: " +  message << std::endl;
  }

  void Reset();
};

#endif
