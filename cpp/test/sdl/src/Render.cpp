#include <iostream>

#include "App.h"

void App::OnRender() {
  // Set the color to the screen and then clear everything
  SDL_SetRenderDrawColor(sdlRenderer, 70, 130, 180, 255);
  SDL_RenderClear(sdlRenderer);

  // Draw the grid to the screen
  Surface::OnDraw(sdlRenderer, Tex_Grid, MARGIN, 0, DISPLAY_W, DISPLAY_H);  

  // Now draw the X's and O's to the screen
  for (int i = 0; i < 9; i++) {
    int X = (i % 3) * (DISPLAY_W / 3);
    int Y = (i / 3) * (DISPLAY_H / 3);

    if (Grid[i] == GRID_TYPE_X) {
      Surface::OnDraw(sdlRenderer, Tex_X, X, Y, DISPLAY_W / 3, DISPLAY_H / 3);
    }
    else if (Grid[i] == GRID_TYPE_O) {
      Surface::OnDraw(sdlRenderer, Tex_O, X, Y, DISPLAY_W / 3, DISPLAY_H / 3);
    }
  }

  // Display "Game Over!" if the game is over
  if (IsGameOver)
    Surface::OnDraw(sdlRenderer, Tex_GameOver, 0 - MARGIN, 0, GO_W, GO_H);

  // Now that everything is drawn, show it on the screen
  SDL_RenderPresent(sdlRenderer);
}
