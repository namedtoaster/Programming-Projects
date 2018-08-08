//
//  main.cpp
//  Tally
//
//  Created by Dave Campbell on 6/30/18.
//  Copyright © 2018 Dave Campbell. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool check_player_exists(char test, char list[], int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == test)
            return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // get the input
    cout << "I'll take an string input of uppercase and lowercase letters and tally up the score: ";
    string in;
    cin >> in;
    
    // then do the scoring. if the player exists, add or subtract his score (based on the case of the char)
    map<char, int> player_score;
    for (int i = 0; i < in.length(); i++) {
        //if (check_player_exists((char)tolower(in[i]), all_lowercase, in.length())) {
        if (islower(in[i]))
            player_score[(char)tolower(in[i])] += 1;
        else
            player_score[(char)tolower(in[i])] -= 1;
    }
    
    // print out the score
    map<char, int>::iterator itr;
    for (itr = player_score.begin(); itr != player_score.end(); itr++) {
        cout << itr->first << "'s score: " << itr->second << endl;
    }
    
    return 0;
}
