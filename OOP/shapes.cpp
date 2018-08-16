#include <iostream>

class Shape {
public:
  Shape() { width = 1.0; height = 1.0; }

  void set_w_h(double x, double y) {
    width = x; height = y;
  }
protected:
  double width;
  double height;
};

class Triangle : public Shape {
public:
  double get_area() {
    return width * height / 2;
  }
private:
  double area;
};

class Rectangle : public Shape {
public:
  double get_area() {
    return width * height;
  }
};


int main() {
  Triangle a;
  a.set_w_h(3, 2);

  std::cout << a.get_area() << std::endl;
  return 0;
}
