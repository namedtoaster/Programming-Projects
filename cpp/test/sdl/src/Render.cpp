#include <iostream>

#include "App.h"

void App::OnRender() {
  // Set the color to the screen and then clear everything
  SDL_SetRenderDrawColor(sdlRenderer, 70, 130, 180, 255);
  SDL_RenderClear(sdlRenderer);

  // Draw the grid to the screen
  Surface::OnDraw(sdlRenderer, Tex_Grid, 0, 0, 600, 600);  

  // Now draw the X's and O's to the screen
  for (int i = 0; i < 9; i++) {
    int X = (i % 3) * 200;
    int Y = (i / 3) * 200;

    if (Grid[i] == GRID_TYPE_X) {
      Surface::OnDraw(sdlRenderer, Tex_X, X, Y, 200, 200);
    }
    else if (Grid[i] == GRID_TYPE_O) {
      Surface::OnDraw(sdlRenderer, Tex_O, X, Y, 200, 200);
    }
  }

  // Display "Game Over!" if the game is over
  if (IsGameOver)
    Surface::OnDraw(sdlRenderer, Tex_GameOver, 0, 0, GO_W, GO_H);

  // Now that everything is drawn, show it on the screen
  SDL_RenderPresent(sdlRenderer);
}
