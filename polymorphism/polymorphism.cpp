#include <iostream>
#include <string.h>
#include <locale>

using namespace std;

class Polygon {
  // I'd have to double check this, but I believe the the protected access modifer
  // allows classes derived from this class to access these member variables
  // where as private member variables are only accessible to instances of classes
  // of the same type
protected:
  int width, height;
public:
  void set_values(int a, int b)
  { width = a; height = b;  }
  // This virtual nonsense is a bit tricky...
  // Let's say that you want to create a new class (like Rectangle or Triangle) that is derived from
  // Polygon, which makes sense because Rectangles and Triangles are specific types of polygons. You
  // could obviously have many more. If, for whatever reason, you wanted to declare a pointer to the
  // base class and initialize that variable to the address of one of the derived classes, you could
  // call the virtual function from that pointer variable. See the example in main(). The example
  // classes are examples of polymorphism (see http://www.cplusplus.com/doc/tutorial/polymorphism/)
  // and are polymorphic classes

  // In order to be able to actually instantiate an object of type Polygon, the area() function must
  // have a definition. So uncomment "#1" if you want that to be the case. Otherwise, if you just
  // want it to be an abstract class, the area() function (or any other function with the 'virtual'
  // keyword) must have no definition. Instead, replace the definition with "=0" as is the case in
  // area() function "#2"

  // #1
  /*virtual int area()
    { return 0; }*/

  // #2
    virtual int area() = 0;
  // Another feature of abstract base classes is that the abstract base class can access the proper
  // virtual function when called by the pointer variable. For instance, if you created a variable
  // like so:
  //     Rectangle recta;
  // and then created another variable of type Polygon* (pointer to the abstract base class):
  //     Polygon* rectap = &recta;
  // any other member function in the base class could access the proper virtual method by using the
  // "this" keyword. For example:
  void printarea()
  { cout << this->area() << endl; }
};

class Rectangle : public Polygon {
public:
  int area()
  { return width * height; }
};

class Triangle : public Polygon {
public:
  int area()
  { return width * height / 2; }
};

int main() {
  // Apparently, a pointer to a derived class is type compatible with the base class
  // So...
  Rectangle recta;
  Polygon* rectap = &recta;
  // Doesn't break. ONLY if the derived class is from a PUBLIC version of the base
  // class

  // Using the member functions..
  rectap->set_values(3, 4);
  cout << "To get the area of the initialized Rectanlge, we have to call the area method "
       << "of the derived class, we can't access it through the pointer to the base "
       << "class. That is, not unless we make the function virtual..." << endl;
  cout << "The area of the rectap rectangle is: " << recta.area() << endl;

  // Now let's call the function from the base class
  cout << "The area of the rectap rectangle is (now using the virtual function): " << rectap->area() << endl;

  // The only time you can actually write the following declaration is if you define Polygon as an
  // abstract class. Instructions on how to do so are documented with the class at the top of the
  // file
  // Polygon test;

  // Now, let's still use the same Polygon* and Rectangle variables that were initialized and call
  // another method that was created to illustrate polymorphism -- again, see instructions written
  // out in the base class
  cout << "Again, the area of the rectangle, this time calling a new method in the base class: ";
  rectap->printarea();
  
  return 0;  
}
