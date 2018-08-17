#include <iostream>

using namespace std;

class Box{
public:
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout << "Box constructor called" << endl;
    length = l;
    breadth = b;
    height = h;
  }

  // This file was created to demonstrate the 'this' keyword. It's pretty
  // easy to see what's going on once observing the code. Whenever an instance
  // of this class is called, the instance's volume() method is called
  // when making the this.volume() call
  double volume() const { return length * breadth * height; }

  int compare(Box b) {
    return this->volume() > b.volume();
  }
private:
  double length;
  double breadth;
  double height;
};

int main() {
  Box a(3.3, 1.2, 1.5);
  Box b(8.5, 6.0, 2.0);

  cout << "Box " << ((a.compare(b)) ? "a is bigger than box b" : "b is bigger than box a") << endl;
}
