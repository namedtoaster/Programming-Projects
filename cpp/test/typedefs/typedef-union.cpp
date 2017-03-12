#include <iostream>

using namespace std;

int main() {
  // Typedef example
  typedef int* myptr;

  // Now I can use the made-up "myptr" type to create pointers to ints
  int x = 7;
  myptr y = &x;

  cout << "My custom pointer type y: " << y << endl;
  cout << "The value y points to: " << *y << endl;

  // Typedef struct example

  typedef struct tellephone{
    string name;
    int number;
  } TELLEPHONE;

  // Notice that the above syntax is different from other typdef
  // declarations in that the name of the new type is declared after
  // the actual contents of the struct as opposed to immediately after
  // the type that it is an alias of. In other words, "TELLEPHONE" is
  // the name of the new type NOT tellephone (somewhat confusing since
  // the two words are the same, the only difference is the case).

  // So now, when you want to declare a struct of this type, you will
  // do it like so:
  TELLEPHONE home;

  // Now access/modify the member varaibles as usual
  home.name = "My home number";
  home.number = 1234567890;

  cout << "Home TELLEPHONE name: " << home.name << endl;
  cout << "Home TELLEPHONE number: " << home.number << endl;

  // Now let's create a pointer to the newly created struct type

  TELLEPHONE* homep = &home;

  // Let's change the values just for the sake of doing so
  homep->name = "A different name";
  homep->number = 987654321;

  // ...and print those values
  cout << "Pointer to home TELLEPHONE new name: " << homep->name << endl;
  cout << "Pointer to home TELLEPHONE new number: " << homep->number << endl;

  // Another datatype: unions. The syntax to create unions is similar to structs
  // but the implementation is different. Check out stackoverflow.com or
  // cppreference for a description of what a union is

  union MyUnion {
    int x;
    double y;
  };

  MyUnion example;
  example.x = 1;

  // Let's see what happens when we try to print the y member when it hasn't
  // been initialized
  cout << "example.y: " << example.y << endl; // I'm not really sure what has
  // been printed. Since x and y share the same memory location, I"m guessing x
  // is modifying y in some way, but I don't know exactly how
  // TODO figure out what's going on here

  // Now print member y. There should not be any unexpected behavior here
  cout << "example.x: " << example.x << endl;

  // Now we can create a new type based on the union
  
  typedef union {
    int x;
    double y;
  } NEWUNION;

  // Notice again how the syntax is similar to creating a struct typedef

  // Now, as before, declare a variable based on this new type
  NEWUNION mynew;
  mynew.x = 5;
  mynew.y = 3.14;

  // I'm not going to print these values since there's nothing crazy going on
  // here. Everything has been explained well enough. Well, at least I think it has
}
