//
//  main.cpp
//  Practice
//
//  Created by Dave Campbell on 6/25/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

void print_menu() {
    cout << "Staff Management System Options:\n\n";
    cout << "1. Insert an employee" << endl;
    cout << "2. Search for employee (given ID number)" << endl;
    cout << "3. Edit an employee (given ID number)" << endl;
    cout << "4. Delete an employee (given ID number)" << endl;
    cout << "5. Print all employees with a salary more than $20k" << endl;
    cout << "0. Exit program" << endl;
}

int main(int argc, const char * argv[]) {
  // set up vars

  // vector to store all created employees
  vector<Employee> list_of_employees;

  // ask the user what they want
  //  1. insert an employee
  //  2. search for an employee via an id number
  //  3. edit an employee based on an id number
  //  4. delete an employee based on an id number
  //  5. print employees with a salary more than 20k

  // notes -- put data into a file and load employee details for each employee into a linked list

  print_menu();

  int option;
  cin >> option;

  // keep the loop going until the user exits
  while (option != 0) {
    switch (option) {
    case 1:
      cout << "Option 1" << endl;
      break;
    case 2:
      cout << "Option 2" << endl;
      break;
    case 3:
      cout << "Option 3" << endl;
    case 4:
      cout << "Option 4" << endl;
    case 5:
      cout << "Option 5" << endl;
    default:
      break;
    }
    cin >> option;
  }

  return 0;
}

