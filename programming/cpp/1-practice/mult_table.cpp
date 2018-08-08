#include <iostream>

using namespace std;

int main() {
  // ask how many rows/columns the user wants to print up to (will probably have to find a limit since the screen is only so big. later on i can create a way to split up the table into multiple sections. there will still be a limit to that too because the compiler can only multiply so much)
  int size;
  cout << "How far do you want to multiply up to? ";
  cin >> size;

  // create a multi-dimensional array using pointers
  int **mult_table;
  mult_table = new int*[size];
  for (int i = 0; i < size; i++) {
    mult_table[i] = new int[size];
  }

  // set all the values in the array
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mult_table[i][j] = (i + 1) * (j + 1);
    }
  }

  // print the array
  cout << "  ";
  for (int i = 0; i < size; i++)
    cout << i + 1 << '\t';
  cout << endl;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j == 0)
        cout << i + 1 << ' ';
      cout << mult_table[i][j] << '\t';
    }
    cout << endl;
  }

  // delete the pointers
  for (int i = 0; i < size; i++) {
    delete [] mult_table[i];
    mult_table[i] = NULL;
  }

  return 0;
}
