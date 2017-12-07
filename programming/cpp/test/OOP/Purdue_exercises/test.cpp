#include <iostream>

int main() {
  char* p = "test";
  p = "something else";

  std::cout << p << std::endl;
}
