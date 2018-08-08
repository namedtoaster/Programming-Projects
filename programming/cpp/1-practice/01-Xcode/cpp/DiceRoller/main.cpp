//
//  main.cpp
//  DiceRoller
//
//  Created by Dave Campbell on 6/30/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

// global vars
string::size_type sz;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    // ask the user how many dice they need to roll
    cout << "How many dice do you need to roll? ";
    int rolls;
    cin >> rolls;
    
    // enter a for loop that for each loop, asks how many and what kind of die to roll
    int sum = 0;
    for (int i = 0; i < rolls; i++) {
        cout << "Die #" << i + 1 << ": number of die: ";
        int num_die;
        cin >> num_die;
        
        cout << "Type of die (for d3-d100, pick a number from 3 to 100): ";
        int type_die;
        cin >> type_die;
        
        cout << "You will roll something between " << num_die << " and " << num_die * type_die << endl;
        cout << "But you will probably get something close to " << type_die / 2 * num_die << endl;
        cout << "Rolling..." << endl;
        
        int die_sum = 0;
        
        for (int j = 0; j < num_die; j++) {
            int single_roll = rand() % type_die + 1;
            
            if (single_roll == 20)
                cout << "You rolled a nat 20!" << endl;
            else if (single_roll == 1)
                cout << "You rolled a nat 1, rough luck!" << endl;
            
            die_sum += single_roll;
        }
        
        cout << "Those set of dice gave you " << die_sum << endl;
        cout << endl;
        
        sum += die_sum;
    }
    
    // print sum of rolls
    cout << "You rolled a grand total of " << sum << "! Hope that's what you wanted!" << endl;
    cout << endl;
    
    return 0;
}
