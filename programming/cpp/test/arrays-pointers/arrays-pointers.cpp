#include <iostream>

using namespace std;

string stringToLower(string input) {
  locale loc;
  string temp = "";
  for (string::size_type i = 0; i < input.length(); i++) {
    temp += tolower(input[i], loc);
  }

  return temp;
}

void print_array(int *start, int *stop) {
  // Set the counter as a const int pointer so as to not allow
  // modification

  // In this for loop, the const keyword says that the pointer itself
  // is not const but the data that it points to is. 
  for (const int *x = start; x < stop; x++) {
    // Apparently, you shouldn't use printf in C++ programs. It's even
    // advised to not use in C programs where it was originally
    // created. See http://stackoverflow.com/questions/10865957/c-printf-with-stdstring
    //printf("Element at %p: %d\n", x, *x);
    cout << "Element at " << x << ": " << *x << endl;
  }

  // THIS FOR LOOP WILL NOT COMPILE. It's a pointless function since
  // it can't compile, but what it tries to do is create a variable x
  // that is a const pointer to a const int and print its
  // values. Since it is a const pointer though, it won't compile
  // because the for loop attempts to increment the value as for loops do
  /*
    for (const int *const x = start; x < stop; x++) {
    printf("Element at %p: %d\n", x, *x);
    }*/
}

int main() {
  // Pointer examples
  char *b;
  char c = 'c';
  b = &c;
  // printf printing an address that a pointer points to
  cout << "b: " << b << endl;
  cout << "What b is pointing to: " << *b << endl;
  cout << "The address of c: " << b << endl;
  cout << "The address of c + 1: " << ++b << endl;

  // Example of passing arrays as pointers (and printing them)
  int my_array[] = {5, 32, 10, 37, 54};
  print_array(my_array, my_array + 4);

  // Example that shows that string literals are just pointers to the
  // first character in the string with a null terminator
  const char *foo = "hello";
  printf("This is a string literal: %s\n", foo);
  printf("This is the address of the string literal: %p\n", &foo);
  
  // Random pointer example
  int *a;
  int w = 10;
  a = &w;
  // Printing a pointer variable prints its address
  cout << "Address of a: " << a << endl;
  // Printing what a pointer refernces does just that: prints the
  // value located at the address it points to
  cout << "Value of a: " << a << endl;

  // Sometimes pointeres need to point to nothing. I'm not sure what
  // those cases are, but apparently there exists a use

  // NOTE: You must compile with -std=c++11
  int *x = 0;
  x = nullptr;
  // Now what happens when I try to print x?
  cout << x << endl;
  // Somewhat unsurprsingly, it just prints 0. Keep in mind that the
  // initialization and assignment of x in the previous lines assign
  // the same exact value to x.

  // Convert string to lower case test
  string test = "Post-It Notes";
  string lower = stringToLower(test);
  cout << lower << endl;

  // **********************************************************************
  // Variable names: b, c, my_array, foo, a, w, x, test, lower
  // **********************************************************************

  // It is possible to declare a pointer to a void type
  double y = 25.0;
  long q = 25l;
  float u = 25.0f;

  void *l = &y;                                    // Valid
  l = &q;                                          // Valid
  l = &u;                                          // Valid

  // But you can't dereference a void pointer type
  //cout << "*l: " << *l << endl;                  // INVALID
}
