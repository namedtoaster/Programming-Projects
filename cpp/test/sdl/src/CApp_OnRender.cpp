#include <iostream>

#include "CApp.h"

void CApp::OnRender() {
  CSurface::OnDraw(Surf_Window, Surf_Display, Surf_Test, 0, 0);
  //CSurface::OnDraw(Surf_Window, Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50);
  //SDL_BlitSurface(Surf_Test, NULL, Surf_Display, NULL);
  //SDL_UpdateWindowSurface(Surf_Window);
}
