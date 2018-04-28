#include <iostream>

class Mom {
public:
  void display() { std::cout << "Hi, this is mom speaking" << std::endl; }
};

class Daughter : public Mom {
public:
  void display() { std::cout << "Hi, this is the daughter speaking" <<
      std::endl; }
};

int main()
{
  Daughter a;
  a.display();

  return 0;
}
