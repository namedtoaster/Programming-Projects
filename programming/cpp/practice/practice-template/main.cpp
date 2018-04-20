#include <iostream>

#include "calc.h"

using namespace std;

int main() {
  double x = 1.3, y = 4.2;
  calc<double> myClass;

  cout << myClass.add(x, y) << endl;
  
  return 0;
}
