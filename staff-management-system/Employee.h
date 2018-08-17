//
//  Employee.hpp
//  Practice
//
//  Created by Dave Campbell on 6/25/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
using namespace std;

enum Role {
  Manager,
  Associate,
  CEO
};

class Employee {
 public:
  //Employee();
  Employee search(int id);
  void edit_employee(int id);
  string get_first();
  void set_first(string);
  void set_last(string);
  void set_age(int);
  void set_address(string);
 private:
  int id_number;
  string first;
  string last;
  int age;
  string address; // just street number and street, not city, state or zip
  Role role;
  int salary;
};


#endif /* Employee_hpp */
