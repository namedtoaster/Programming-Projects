#include <iostream>

#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
  switch  (Event->type) {
  case SDL_QUIT:
    Running = false;

  case SDL_MOUSEBUTTONDOWN: {
    switch(Event->button.button) {
    case SDL_BUTTON_LEFT: {
      OnLButtonDown(Event->button.x,Event->button.y);
      break;
    }
    }
  }
  }

}


void CApp::OnLButtonDown(int mX, int mY) {
  int ID = mX / 200;
  ID = ID + ((mY / 200) * 3);

  if (CurrentPlayer == 0) {
    SetCell(ID, GRID_TYPE_X);
    CurrentPlayer = 1;
  }
  else {
    SetCell(ID, GRID_TYPE_O);
    CurrentPlayer = 0;
  }
}
