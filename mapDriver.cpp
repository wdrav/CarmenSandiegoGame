// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Map.h"

using namespace std; 

int main() {
    Map map;  // create object called map of type Map
    map.spawnBestBuy(1, 3);
    map.spawnNPC(2, 5);
    map.spawnNPC(3, 8);
    map.spawnHacker(1, 1);

    char move;  // for storing user input

    // quit after 10 moves
    for(int i = 0; i < 10; i++) {
        map.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl; 
        map.displayMoves();  // give user a menu of valid moves to pick from
        
        cout << "Input a move: "; 
        cin >> move;
        cout << endl;
        map.executeMove(move);  // move the player on map based on user input

        if (map.isBestBuyLocation()) {
            cout << "You're in a Best Buy!" << endl;
        }

        if (map.isHackerLocation()) {
            cout << "You've encountered a Hacker!" << endl;
        }

        if (map.isNPCLocation()) {
            cout << "You've encountered an NPC!" << endl;
        }
    }
}
