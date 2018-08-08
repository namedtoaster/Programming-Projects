#include <iostream>
#include <string>

using namespace std;

struct Contact {
  string name;
  string address;
  string phone_number;
};

int main() {
  Contact first_person;
  cout << "Enter the name, address and phone number of a single contact:\n";
  cout << "Name (First Last): ";
  getline(cin, first_person.name);

  cout << "Address (Street, City, State, separated by commas): ";
  cin.ignore();
  getline(cin, first_person.address);

  cout << "Phone Number (10 digits, no dashes): ";
  getline(cin, first_person.phone_number);

  return 0;
}
