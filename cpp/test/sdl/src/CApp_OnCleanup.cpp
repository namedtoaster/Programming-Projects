#include "CApp.h"

void CApp::OnCleanup() {
  SDL_DestroyWindow(Surf_Window);
  Surf_Window = NULL;
  SDL_FreeSurface(Surf_Test);
  Surf_Test = NULL;
  // Trying to free the display surface causes a segmentation fault
  // because either a) SDL_FreeSurface() is trying to delete something
  // that is pointing to NULL or b) something is trying to use the
  // surface after it has been freed (sp?) See:
  // https://forums.libsdl.org/viewtopic.php?t=7078&sid=4e7ebe3df4be87f0ee65a18a7a944738
  //
  // SDL_FreeSurface(Surf_Display);
  SDL_Quit();
}
