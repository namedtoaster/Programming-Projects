//
//  main.cpp
//  Practice
//
//  Created by Dave Campbell on 6/25/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;

// globals
string::size_type sz;
vector<Employee> employee_list;

void print_menu() {
    cout << "Staff Management System Options:\n\n";
    cout << "1. Insert an employee" << endl;
    cout << "2. Search for employee (given ID number)" << endl;
    cout << "3. Edit an employee (given ID number)" << endl;
    cout << "4. Delete an employee (given ID number)" << endl;
    cout << "5. Print all employees with a salary more than $20k" << endl;
    cout << "0. Exit program" << endl;
    cout << ": ";
}

void print_employee(Employee e) {
    cout << "Employe ID#: " << e.id_number << endl;
    cout << "First: " << e.first << endl;
    cout << "Last: " << e.last << endl;
    cout << "Age: " << e.age << endl;
    cout << "Address: " << e.address << endl;
    cout << "Role: " << e.role << endl;
    cout << "Salary: " << e.salary << endl;
    cout << endl;
}

void print_employees() {
    for (int i = 0; i < employee_list.size(); i++) {
        cout << "Employee #" << i + 1 << endl;
        print_employee(employee_list[i]);
    }
}

void load_data(string filename) {
    ifstream data(filename);
    if (!data.is_open())
        cout << "File has not been opened" << endl;

    vector<string> values;
    string value;
    
    for (int i = 0; i < 7; i++) {
        if (getline(data, value)) {
            values.push_back(value);
        }
        else {
            cout << "Error reading data" << endl;
            return;
        }
    }
    
    // convert the int values so they can be stored properly
    int salary, age, id_num;
    
    id_num = stoi(values[0], &sz);
    salary = stoi(values[6], &sz);
    age = stoi(values[3], &sz);
    
    // only add one employee for now
    
    Employee temp;
    temp.id_number = id_num;
    temp.first = values[1];
    temp.last = values[2];
    temp.age = age;
    temp.address = values[4];
    // i have to assign the role in a messy way like this. not really sure how else to do it right now. not effeciently at least
    temp.role = (values[5] == "Manager" ? Manager : (values[5] == "Associate" ? Associate : CEO));
    temp.salary = salary;
    
    employee_list.push_back(temp);
}

void insert_employee() {
    Employee temp;
    string in, age, role, salary;
    int id_num = employee_list[employee_list.size() - 1].id_number + 1;
    
    temp.id_number = id_num;
    cout << "Employee's first name: ";
    cin >> temp.first;
    cout << "Employee's last name: ";
    cin >> temp.last;
    cout << "Employee's age: ";
    cin >> age;
    cin.ignore();
    cout << "Employee's address (street address, not city, state or zip): ";
    getline(cin, temp.address);
    cout << "Employee's role: ";
    cin >> role;
    cout << "Employee's salary: ";
    cin >> salary;
    
    temp.age = stoi(age, &sz);
    temp.role = (in == "Manager" ? Manager : (in == "Associate" ? Associate : CEO));
    temp.salary = stoi(salary, &sz);
    
    employee_list.push_back(temp);
}

// maybe eventually return an employee, but just print the values for now
void search_by_id() {
    cout << "Search by ID: ";
    string in;
    cin >> in;
    
    int id_search = stoi(in, &sz);
    
    for (int i = 0; i < employee_list.size(); i++) {
        if (employee_list[i].id_number == id_search) {
            print_employee(employee_list[i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    // load saved employee data into a list
    string filename = "employee_data";
    load_data(filename);
    
    // ask the user what they want
    //  1. insert an employee
    //  2. search for an employee via an id number
    //  3. edit an employee based on an id number
    //  4. delete an employee based on an id number
    //  5. print employees with a salary more than 20k
    print_menu();
    
    int option;
    cin >> option;
    
    // keep the loop going until the user exits
    while (option != 0) {
        switch (option) {
            case 1:
                insert_employee();
                break;
            case 2:
                search_by_id();
                break;
            default:
                break;
        }
        print_menu();
        cin >> option;
    }
    
    print_employees();
    
    return 0;
}
