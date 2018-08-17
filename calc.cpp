#include <iostream>

using namespace std;

int main() {
  char op;
  double val1, val2;

  cout << "Simple calculator\n\nWhat operator do you want to use? (+, -, *, /,): ";
  cin >> op;

  cout << "First value: ";
  cin >> val1;
  cout << "Second value: ";
  cin >> val2;

  if (op == '+')
    cout << val1 << " + " << val2 << " = " << val1 + val2 << endl;
  else if (op == '-')
    cout << val1 << " - " << val2 << " = " << val1 - val2 << endl;
  else if (op == '*')
    cout << val1 << " * " << val2 << " = " << val1 * val2 << endl;
  else if (op == '/')
    cout << val1 << " / " << val2 << " = " << val1 / val2 << endl;

  return 0;
}
