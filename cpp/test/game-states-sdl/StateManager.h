#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include "GameState.h"

class StateManager {
 public:
  void Init();
  void Cleanup();

  void ChangeState(GameState *state);
  void PushState(GameState *state);
  void PopState();

  void HandleEvents();
  void Update();
  void Render();

  bool Running() { return running; }
  void Quit() { running = false; }

 private:
  std::vector<GameState*> states;
  bool running;
};

#endif
