#include "App.h"

bool App::PlayerWin () {
  int temp[9] = {000000000};
  for (int x = 0; x < 9; x++) {
    temp[x] = Grid[x];
  }
  
  for (int x = 0; x < 9; x++) {
    if (CurrentPlayer == 0) {
      if (temp[x] == GRID_TYPE_X)
	temp[x] = 1;
      else
	temp[x] = 0;
    }
    else {
      if (temp[x] == GRID_TYPE_O)
	temp[x] = 1;
      else
	temp[x] = 0;
    }
  }

  int Win[8][9]= {{1,0,0,0,1,0,0,0,1},
		  {0,0,1,0,1,0,1,0,0},
		  {1,0,0,1,0,0,1,0,0},
		  {0,1,0,0,1,0,0,1,0},
		  {0,0,1,0,0,1,0,0,1},
		  {1,1,1,0,0,0,0,0,0},
		  {0,0,0,1,1,1,0,0,0},
		  {0,0,0,0,0,0,1,1,1}};

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 9; y++) {
      if (temp[y] != Win[x][y] && temp[y] == 0)
	break;
      if (y == 8)
	return true;
    }
  }
  return false;
}

void App::DeclareWinner() {
  std::cout << "Player " << CurrentPlayer + 1 << " won!" << std::endl;
}
void App::ContinueGame() {
  std::cout << "Game is still going!" << std::endl;
}

void App::OnLoop() {
}
