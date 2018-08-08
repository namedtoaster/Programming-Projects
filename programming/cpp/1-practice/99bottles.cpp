#include <iostream>

using namespace std;

int main() {
  for (int i = 99; i > 0; i--) {
    if (i != 1)
      cout << i << " bottles of beer on the wall, " << i << " bottles of beer. Take one down, pass it around, " << i - 1<< " bottles of beer on the wall" << endl;
    else
      cout << "1 bottle of beer on the wall, 1  bottle of beer. Take one down, pass it around, 0  bottles of beer on the wall" << endl;
  }

  return 0;
}
