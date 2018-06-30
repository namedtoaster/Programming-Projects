#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char **create_board(int width, int height) {
  char **setup;
  setup = new char*[width];

  for (int i = 0; i < width; i++) {
    setup[i] = new char[height];
  }

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      setup[i][j] = '_';
    }
  }

  return setup;
}

void print_board(char **board, int width, int height) {
  for (int i = 0; i < width; i++)
    cout << i;
  cout << endl;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}

bool not_valid(string move, int width, char **board) {
  int col = atoi(move.c_str());

  if (col >= 0 && col < width)
    return false;

  if (board[0][col] == '_') 
    return false;

  return true;
}

void place_piece(string move, char **board, int height, char piece) {
  int col = atoi(move.c_str());

  for (int i = height - 1; i >= 0; i--) {
    if (board[i][col] == '_') {
      board[i][col] = piece;
      return;
    }
    else
      continue;
  }
}

int main() {
  // GAME NOT COMPLETE
  cout << "GAME NOT COMPLETE: IT WON'T WORK" << endl;
  // ask what the width and the height of the game is
  int width, height;
  cout << "What's the width and height of the game?" << endl;
  cout << "Width: ";
  cin >> width;
  cout << "Height: ";
  cin >> height;

  // create the board
  char **board = create_board(width, height);
  print_board(board, width, height);

  // enter the game loop
  int counter = 0, turn = 0;
  bool game_won = false;
  string move;
  char piece;

  while (!game_won) {
    cout << "Player " << turn + 1 << "'s turn: ";
    cin >> move;

    while (not_valid(move, width, board)) {
      cout << "That move was not valid. Pick another: ";
      cin >> move;
    }

    if (turn == 0)
      piece = '+';
    else
      piece = 'x';

    place_piece(move, board, height, piece);

    print_board(board, width, height);
    counter++;
    turn = counter % 2;
    // only exit the game when a player wins 
  }

  return 0;
}
