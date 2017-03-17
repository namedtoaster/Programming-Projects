#include <iostream>
#include "App.h"

App::App() {
  CurrentPlayer = 0;
  
  Surf_Window = NULL;

  Tex_Grid = NULL;
  Tex_X = NULL;
  Tex_O = NULL;
  
  Running = true;
};

int App::OnExecute() {
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

void App::Reset() {
  for (int i = 0; i < 9; i++) {
    Grid[i] = GRID_TYPE_NONE;
  }
}

void App::SetCell(int ID, int Type) {
  if (ID < 0 || ID >= 9) return;
  if (Type < 0 || Type > GRID_TYPE_O) return;

  Grid[ID] = Type;
}

int main(int argc, char* argv[]) {
  App theApp;

  return theApp.OnExecute();
}
