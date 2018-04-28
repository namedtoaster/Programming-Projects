#include <iostream>

using namespace std;

int main() {
  // Let's talk about type casting. First, we'll declare tree types of variables.
  // They'll all be 3 different types
  double a = 21.99399;
  float b = 10.20;
  int c;

  // Now, we'll set the value of c (an int) to the int version of a (which is
  // a double)
  
  c = (int) a;
  cout << "(int) a: " << c << endl;

  // Notice, that even though 21.99399 rounds up to 22, c++ does not do this. It
  // just truncates the digits after the decimal point

  // We can do the same thing with b
  c = (int) b;
  cout << "(int) b: " << c << endl;

  
}
