// This particular file was created because I realized I didn't know exactly
// all the different ways functions could be called/declared. The basic things
// one should know is the kind of return value the function will return and the
// parameters that the function operates on. These parameters are only "alive"
// within the scope of the function (that's a topic for another practice file).
// The first thing to go through is declaring a constant function

// I will surely come back to this file often because there are lots of things
// to cover.

#include <iostream>

using namespace std;

class Test {
private:
  int value;
protected:
  // The difference between private and protected is pretty simple,
  // but important to understand. In this particular case, the only
  // thing that is aware of value is Test. However, both Test and any
  // children of Test are aware of diff_value (protected). Everything
  // is aware of anything that is public
  // See https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
  int diff_value;
public:
  Test(int x = 0, int y = 0 ) { value = x; diff_value = y; }
  // get_value() simply returns the value of member variable 'value'. Since
  // the function is declared as a const type, if we try to modify any of
  // the class's member variables, the compiler will yell at us like it does
  // when....
  int get_value() const { cout << "**const method** "; return value; }

  // ...we try to compile this function:
  /*void set_value(int x = 0) const
    { value = x; }*/

  int get_value() { cout << "**non-const method** "; return value; }
};

// This class has been created to help demostrate constructors
class Line {
public:
  Line(){}; // This is the constructor. Dummy. It does nothing. In case
  // that wasn't obvious
  //Line(double l) { length = l; } // You can also do this, which allows you to
  // initialize the value of a member variable at construction
  Line(double n): length(n) {}; // This constructor is the same as the previous one,
  // but it initializes the member variable in a syntactically(sp) different way.
  // Note that you can only use one of the constructors since they do exactly the
  // same thing
  Line(double l, int a, float b): length(l), x(a), y(b) {}
  // This constructor was created just to illustrate how to initialize multiple
  // member variables. All you have to do is separate each initialization by commas
  void set_length(double l) { length = l; }
  double get_length() const { return length; }

private:
  double length;
  int x;
  float y;
};

void print_something() { cout << "something" << endl; }
// Note that these two functions are exactly the same. If you try tod eclare
// both functions, the compiler will give you a redefinition error
//void print_something(void) { cout << "something (void parameter)" << endl;

int main() {
  Test a(5);

  // Just test the first method...
  cout << "a's (of class Test) value: " << a.get_value() << endl;

  const Test b(10);
  // Which get_value() function will b call?
  cout << "b's (of class Test) value: " << b.get_value() << endl;

  // While going through some documentation found on Google, I found that it is not
  // possible for a const type to call a non-const function. Somewhat unsurprisingly,
  // if you have two functions with the same name, the const instance will call the
  // method that is of the const type. If you comment out the const method, the
  // compiler will throw an error

  print_something();

  // Since the constructor for this class dosn't allow you to set the value
  Line line;
  // for its member variable, you have to do it later with one of the member functions
  // which we'll do next
  line.set_length(4.0);
  cout << "Length of the Line is: " << line.get_length() << endl; // TODO std::cout precision

  Line lineb(6.3);
  cout << "Length of the new Line is: " << lineb.get_length() << endl;
}
