#include "App.h"

void App::OnCleanup() {
  SDL_DestroyWindow(Surf_Window);
  Surf_Window = NULL;

  SDL_DestroyRenderer(sdlRenderer);
  sdlRenderer = NULL;
  
  SDL_FreeSurface(Surf_Grid);
  SDL_DestroyTexture(Tex_Grid);
  Tex_Grid = NULL;

  SDL_FreeSurface(Surf_X);
  SDL_DestroyTexture(Tex_X);
  Tex_X = NULL;

  SDL_FreeSurface(Surf_O);
  SDL_DestroyTexture(Tex_O);
  Tex_O = NULL;

  SDL_FreeSurface(Surf_Text);
  SDL_DestroyTexture(Tex_Text);
  Tex_Text = NULL;
  
  //SDL_FreeSurface(Surf_X);
  //SDL_FreeSurface(Surf_O);
  // Trying to free the display surface causes a segmentation fault
  // because either a) SDL_FreeSurface() is trying to delete something
  // that is pointing to NULL or b) something is trying to use the
  // surface after it has been freed (sp?) See:
  // https://forums.libsdl.org/viewtopic.php?t=7078&sid=4e7ebe3df4be87f0ee65a18a7a944738
  //
  // SDL_FreeSurface(Surf_Display);
  TTF_Quit();
  SDL_Quit();
}
