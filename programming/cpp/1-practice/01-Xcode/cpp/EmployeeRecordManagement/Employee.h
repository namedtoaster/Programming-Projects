//
//  Employee.hpp
//  Practice
//
//  Created by Dave Campbell on 6/25/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//
#ifndef Employee_hpp
#define Employee_hpp

#include <string>
using namespace std;

enum Role {
    Manager,
    Associate,
    CEO
};

struct Employee {
    int id_number; // i'm arbitrarilly storing this as a string so i can have leading zeros. looks more like an id_number than a simple int does
    string first;
    string last;
    int age;
    string address; // just street number and street, not city, state or zip
    Role role;
    int salary;
};


#endif /* Employee_hpp */
