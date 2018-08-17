//
//  Employee.cpp
//  Practice
//
//  Created by Dave Campbell on 6/25/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

//  1. insert an employee
//  2. search for an employee via an id number
//  3. edit an employee based on an id number
//  4. delete an employee based on an id number
//  5. print employees with a salary more than 20k

// int id_number;
// string first;
// string last;
// int age;
// string address; // just street number and street, not city, state or zip
// Role role;
// int salary;

#include "Employee.hpp"
#include <string>

/*void Employee::insert_employee() {
    
}*/

string Employee::get_first() {
    return this->first;
}

void Employee::set_first(string in) {
    this->first = in;
}

void Employee::set_last(string in) {
    this->last = in;
}

void Employee::set_age(int in) {
    this->age = in;
}

void Employee::set_address(string in) {
    this->address = in;
}

Employee Employee::search(int id) {
    Employee temp;
    return temp;
}

void Employee::edit_employee(int id) {
    // find the employee
    Employee edit = search(id);

    // get the first name
    string first = edit.get_first();

    cout << "Enter new first name (0 if you wish to keep the same): ";
    string input;

    cin >> input;
    if (input != "0")
        edit.set_first(input);

    cout << "Enter new last name (0 if you wish to keep the same): ";
    cin >> input;
    if (input != "0")
        edit.set_last(input);

    cout << "Enter new age (0 if you wish to keep the same): ";
    int age;
    cin >> age;
    if (age != 0)
        edit.set_age(age);

    cout << "Enter new address (0 if you wish to keep the same): ";
    cin >> input;
    if (input != "0")
        edit.set_address(input);

    cout << "Role";

    cout << "Salary";
}

