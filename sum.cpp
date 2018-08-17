#include <iostream>

using namespace std;

int main() {
  double input, sum;

  cout << "Input: ";
  cin >> input;

  while (input != 0) {
    sum += input;
    cout << "Sum: " << sum << endl;

    cout << "Input: ";
    cin >> input;
  }

  return 0;
}
