#include <iostream>

using namespace std;

int main() {
  // ask how many rows/columns the user wants to print up to (will probably have to find a limit since the screen is only so big. later on i can create a way to split up the table into multiple sections. there will still be a limit to that too because the compiler can only multiply so much)
  int length, width, height;
  cout << "What is the length, width, and height of the multiplication table (cube)?" << endl;
  cout << "Length: ";
  cin >> length;
  cout << "Width: ";
  cin >> width;
  cout << "Height: ";
  cin >> height;

  // create a multi-dimensional array using pointers
  int ***mult_table;
  mult_table = new int**[length];
  for (int i = 0; i < length; i++) {
    mult_table[i] = new int*[width];
  }
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      mult_table[i][j] = new int[height];
    }
  }

  // set all the values in the array
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < height; k++) {
        mult_table[i][j][k] = (i + 1) * (j + 1) * (k + 1);
      }
    }
  }

  // print the array
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < height; k++) {
        cout << mult_table[i][j][k] << '\t';
      }
      cout << endl;
    }
    cout << "\n\n";
  }

  // delete the pointers
  /*for (int i = 0; i < size; i++) {
    delete [] mult_table[i];
    mult_table[i] = NULL;
    }*/

  return 0;
}
