#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool out_of_bounds(int width, int height, int row, int col, int direction) {
  // up = 0, down = 1, left = 2, right = 3
  // check top and bottom edges
  if (direction == 0 && row == 0)
    return true;
  if (direction == 1 && row == height - 1)
    return true;

  // check left and right edges
  if (direction == 2 && col == 0)
    return true;
  if (direction == 3 && col == width - 1)
    return true;

  return false;
}

char ***create_maze(int width, int height) {
  char ***new_maze = new char**[width];
  int yes_no = 0;

  for (int i = 0; i < width; i++) {
    new_maze[i] = new char*[height];
  }

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++)
      new_maze[i][j] = new char[2];
  }

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      new_maze[i][j][0] = '|';
      new_maze[i][j][1] = '_';
    }
  }

  int row = 0, col = 0;
  int next;

  while ((row != (height - 1)) && (col != (width - 1))) {
    next = rand() % 4;
    cout << "row: " << row << " col: " << col << endl;

    // up = 0, down = 1, left = 2, right = 3

    // if the move is out of bounds, keep checking
    while (out_of_bounds(width, height, row, col, next)) {
      // try a different direction
      next = rand() % 4;
    }

    // change the row/col based on the next position
    if (next == 0)
      row--;
    else if (next == 1)
      row++;
    else if (next == 2)
      col--;
    else if (next == 3)
      col++;

    // if the move is right or down, the current index can be modified
    if (next == 1) {
      new_maze[row][col][1] = ' ';
      continue;
    }
    if (next == 3) {
      new_maze[row][col][0] = ' ';
      continue;
    }

    // if the move is left or up, you have to modify a different index
    /*if (next == 2) {
      new_maze[row][col - 1][0] = ' ';
      continue;
    }
    if (next == 0) {
      new_maze[row - 1][col][1] = ' ';
      }*/
  }

  return new_maze;
}

void print_maze(int width, int height, char ***maze) {
  cout << ' ';
  for (int i = 0; i < width; i++)
    cout << "_ ";
  cout << endl;

  for (int i = 0; i < width; i++) {
    cout << '|';
    for (int j = 0; j < height; j++) {
      cout << maze[i][j][1];
      cout << maze[i][j][0];
    }
    cout << endl;
  }
}

int main() {
  srand(time(NULL));

  // ask for the width and height
  int width, height;
  cout << "What's the width and height of the maze? " << endl;
  cout << "Width: ";
  cin >> width;
  cout << "Height: ";
  cin >> height;

  // create the maze
  char ***maze = create_maze(width, height);

  // print the maze
  print_maze(width, height, maze);
  delete [] maze;
  maze = NULL;

  return 0;
}
