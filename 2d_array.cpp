#include <iostream>

using namespace std;

int main() {
  // ask the user the dimensions of the 2d array
  int width, height;
  cout << "What is the width and height of the 2d array you want to create?" << endl;
  cout << "Width: ";
  cin >> width;
  cout << "Height: ";
  cin >> height;

  // assign values to the 2d array (just multiply the row by the col)
  int **my_array;
  my_array = new int*[width];
  for (int i = 0; i < width; i++) {
    my_array[i] = new int[height];
  }

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      my_array[i][j] = i * j;
    }
  }

  // print the addresses of each element in the 2d array
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      cout << &my_array[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
