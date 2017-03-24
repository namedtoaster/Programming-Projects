#include <iostream>

#include "App.h"

void App::OnEvent(SDL_Event* Event) {
  switch  (Event->type) {
  case SDL_QUIT:
    Running = false;

  case SDL_MOUSEBUTTONDOWN: {
    switch(Event->button.button) {
    case SDL_BUTTON_LEFT: {
      if (!IsGameOver) {
	OnLButtonDown(Event->button.x,Event->button.y);
	break;
      }
    }
    }
  }
  }

}

void App::GameOver() {
  IsGameOver = true;
}

void App::OnLButtonDown(int mX, int mY) {
  int ID = mX / (DISPLAY_W / 3);
  ID = ID + ((mY / (DISPLAY_H / 3)) * 3);

  if (CurrentPlayer == 0) {
    while (true) { if (SetCell(ID, GRID_TYPE_X)) break; }
    if (PlayerWin()) {
      DeclareWinner();
    }
    else
      ContinueGame();
    CurrentPlayer = 1;
  }
  else {
    while (true) { if (SetCell(ID, GRID_TYPE_O)) break; }
    if (PlayerWin()) {
      DeclareWinner();
    }
    else
      ContinueGame();
    CurrentPlayer = 0;
  }
}
