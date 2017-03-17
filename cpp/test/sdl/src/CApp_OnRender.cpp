#include <iostream>

#include "CApp.h"

void CApp::OnRender() {
  SDL_RenderClear(sdlRenderer);

  // Draw the texture to the screen
  CSurface::OnDraw(sdlRenderer, Tex_Grid, 0, 0);
  //SDL_RenderCopy(sdlRenderer, Tex_Grid, NULL, NULL);
  SDL_RenderPresent(sdlRenderer);

  /*for (int i = 0; i < 9; i++) {
    int X = (i % 3) * 200;
    int Y = (i / 3) * 200;

    if (Grid[i] == GRID_TYPE_X) {
      CSurface::OnDraw(Surf_Window, Surf_Display, Surf_X, X, Y);
    }
    else if (Grid[i] == GRID_TYPE_O) {
      CSurface::OnDraw(Surf_Window, Surf_Display, Surf_O, X, Y);
    }
  }*/
  
  //CSurface::OnDraw(Surf_Window, Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50);
  //SDL_BlitSurface(Surf_Test, NULL, Surf_Display, NULL);
  //SDL_UpdateWindowSurface(Surf_Window);
}
