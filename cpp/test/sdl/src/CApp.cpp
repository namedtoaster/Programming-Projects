#include <iostream>
#include "CApp.h"

CApp::CApp() {
  Surf_Window = NULL;
  Surf_Display = NULL;

  Surf_Grid = NULL;
  Surf_X = NULL;
  Surf_O = NULL;
  
  Running = true;
};

int CApp::OnExecute() {
  if (OnInit() == false)
    return -1;

  SDL_Event Event;

  while (Running) {
    while (SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }

    OnLoop();
    OnRender();
  }

  OnCleanup();
  
  return 0;
}

void CApp::Reset() {
  for (int i = 0; i < 9; i++) {
    Grid[i] = GRID_TYPE_NONE;
  }
}

int main(int argc, char* argv[]) {
  CApp theApp;

  return theApp.OnExecute();
}
