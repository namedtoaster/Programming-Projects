#include <iostream>
#include <string>

using namespace std;

int main() {
  string menu_choice;

  while (menu_choice != "Burger"
         && menu_choice != "Fries"
         && menu_choice != "Milkshake"
         && menu_choice != "Coke") {
    cout << "MENU:\n\nBurger\nFries\nMilkshake\nCoke\n\nMenu Choice: ";
    cin >> menu_choice;
  }

  cout << "You chose a " << menu_choice << endl;

  return 0;
}
