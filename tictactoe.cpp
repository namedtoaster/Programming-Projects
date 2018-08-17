#include <iostream>
#include <string>

using namespace std;

bool a_player_won(char board[][3], char piece) {
  // check horizontal and vertical wins
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != piece)
        break;
      if (j == 2){
        return true;
      }
    }
  }

  // check diagonal wins
  for (int i = 0; i < 3; i++) {
    if (board[i][i] != piece)
      break;
    if (i == 2)
      return true;
  }

  for (int i = 0; i < 3; i++) {
    if (board[2 - i][i] != piece)
      break;
    if (i == 2)
      return true;
  }

  return false;
}

void update_board(char board[][3], int player_turn, string move) {
  char piece;
  if (player_turn == 0)
    piece = 'X';
  else
    piece = 'O';

  if (move == "00")
    board[0][0] = piece;
  else if (move == "01")
    board[0][1] = piece;
  else if (move == "02")
    board[0][2] = piece;
  else if (move == "10")
    board[1][0] = piece;
  else if (move == "11")
    board[1][1] = piece;
  else if (move == "12")
    board[1][2] = piece;
  else if (move == "20")
    board[2][0] = piece;
  else if (move == "21")
    board[2][1] = piece;
  else if (move == "22")
    board[2][2] = piece;
  else
    cout << "Invalid move" << endl;
}

void print_board(char board[][3], int size) {
  cout << "   0 1 2\n";
  cout << "  _______\n";

  for (int i = 0; i < size; i++) {
    cout << i << " |";
    for (int j = 0; j < size; j++) {
      if (board[i][j] == '-')
        cout << ' ';
      else
        cout << board[i][j];
      cout << '|';
    }
    cout << "\n  -------\n";
  }
}

int main() {
  // create board array
  char board[3][3];

  // initialize board with -s
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }

  print_board(board, 3);
  // begin game loop: loop will continue until a) game has been won or b) the board is full
  bool game_over = false;
  int turns = 0;
  int player_turn = 0;
  string move;
  char piece;

  while (!game_over) {
    // determine who's turn it is
    player_turn = turns % 2; // if this value is 0, it's player 1's turn. otherwise, it's player 2's turn
    cout << "Player " << player_turn + 1 << "'s turn" << endl;
    if (player_turn == 0)
      piece = 'X';
    else
      piece = 'O';

    // ask current player what spot they want to play
    cout << "Pick spot: ";
    getline(cin, move);

    // update the board
    update_board(board, player_turn, move);

    // print the board
    print_board(board, 3);

    // determine if current player won
    turns++;
    if (turns == 8)
      game_over = true;

    if (a_player_won(board, piece))
      game_over = true;
  }

  return 0;
}
