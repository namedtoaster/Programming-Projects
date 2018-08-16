#include <iostream>
#include <string>

class Animal {
protected:
  int age; std::string name;

public:
  void set_data(int x, std::string y) {
    age = x;
    name = y;
  }
};

class Dolphin : public Animal {
public:
  void print_info()
  {
    std::cout << "This dolphin that is " << age << " years old whose" \
      " name is " << name << " is from the water. *splash* *splash*" << std::endl;
  }
};

int main()
{
  Dolphin a;

  a.set_data(10, "Vinny");

  a.print_info();
}
