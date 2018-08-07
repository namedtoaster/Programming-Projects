//
//  main.cpp
//  DigitalNumberTranslator
//
//  Created by Dave Campbell on 6/30/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    map<int, string> digits;
    digits[1] = "   \n  |\n  |"; // one
    digits[2] = " _\n _|\n|_"; // two
    digits[3] = " _\n _|\n _|"; // three

    // determing how many numbers are input
        // check the number of characters in a line -- just divide the number of characters in a line by 3
        // unless it's just one number, there will likely only be 1 or 2 characters in the first line if it's one number
    ifstream file("input");
    string line1, line2, line3;

    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return 0;
    }
    else {
        if (!(getline(file, line1, '\n'))) {
            cout << "Cannot read from file" << endl;
            return 0;
        }
        else {
            getline(file, line2, '\n');
            getline(file, line3, '\n');

            cout << line1 << endl;
            cout << line2 << endl;
            cout << line3 << endl;

            // decipher the lines
            for (int i = 0; i < line1.length(); i++) {
                string temp = "";

                /*temp = line1.substr(i * 3, 3) +
                    line2.substr(i * 3, 3) +
                    line3.substr(i * 3, 3);

                for (int j = 1; j < 4; j++) {
                    if (temp == digits[j])
                    cout << j;*/
                }
            }
        }
    }

    return 0;
}
 
