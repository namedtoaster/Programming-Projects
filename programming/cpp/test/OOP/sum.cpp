#include <iostream>

class Base {
public:
  Base(int a = 0, int b = 0) { x = a; y = b; }
  void print_vals() { std::cout << x + y << std::endl; }

private:
  int x; int y;
};


int main() {
  Base x(1, 2);
  x.print_vals();
  
  return 0;
}
