#include <iostream>

class Complex {
public:
  Complex(int a, int b) { real = a; complex = b; }
  Complex() { real = 1; complex = 1; }

  void set_real(int a) { real = a; }
  void set_complex(int b) { complex = b; }
  int get_real() { return real; }
  int get_complex() { return complex; }
  
  Complex add(Complex z) {
    Complex var;

    var.set_real(get_real() + z.get_real());
    var.set_complex(get_complex() + z.get_complex());

    return var;
  }
private:
  int real;
  int complex;
};

int main() {
  Complex x(2, 4);
  Complex a(3, 5);

  Complex z;
  z = x.add(a);

  std::cout << "z: " << z.get_real() << " + " << z.get_complex() <<
    "i" << std::endl;
  
  return 0;
}
