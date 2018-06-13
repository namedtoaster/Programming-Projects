#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;

  for (int i = 0; i < 6; i++) {
    if (input != "password") {
      cout << "Enter password: ";
      cin >> input;

      continue;
    }
    else {
      cout << "Access granted" << endl;
      return 0;
    }
  }

  cout << "Access denied" << endl;
  return 0;
}
