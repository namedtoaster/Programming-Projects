#include <iostream>
#include <string>

using namespace std;

void print_name(string *first, string *last) {
  // print the name using pointers
  cout << *first << ' ' << *last << endl;
}

void print_name2(string &first, string &last) {
  // print the name using references
  cout << first << ' ' << last << endl;
}

int main() {
  // ask user for their first and last name
  cout << "What is your first name? ";

  string first, last;
  cin >> first;

  cout << "And last? ";
  cin >> last;

  // pass the values into the print_name function as pointers
  print_name(&first, &last);
  print_name(&first, &last);

  // print out which memory address of two stack vars is larger
  cout << "Address of \"first\" var: " << &first << endl;
  cout << "Address of \"last\" var: " << &last <<endl;
  
  if (&first > &last)
    cout << "The address of the var \"first\" (" << &first << ") is larger" << endl;
  else
    cout << "The address of the var \"last\" (" << &last << ") is larger" << endl;

  return 0;
}
