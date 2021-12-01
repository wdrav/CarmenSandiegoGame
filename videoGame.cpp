#include <iostream>
#include <string>
#include <fstream>
#include "Store.h"
#include "Player.h"
#include "Npc.h"
#include "Map.h"
#include "Hacker.h"
#include "Game.h"
using namespace std;

int main(){
    string playerName;
    Store bestBuy;
    //explain concept of the game to player
    cout << "Welcome to Where in the Code is Carmen San Diego!" << endl;
    cout << endl;
    cout << "Here is an overview of the rules of the game: " << endl;
    cout << "First, you will buy parts from Best Buy to get supplies for your journey." << endl;
    cout << "You will then travel through five hacker-infested server rooms where you will need to" << endl;
    cout << "explore the room to find the hackers and defeat between 1 to 3 hackers before moving on" << endl;
    cout << "to the next room. Along your way, you will have opportunities to visit Best Buy to buy" << endl;
    cout << "items to upgrade your equipment. You will also be able to interact with potentially friendly" << endl;
    cout << "non-playable characters (called NPCs) and fight hackers that you find during your exploration" << endl;
    cout << "of the server rooms. The game ends when you have defeated between 1 to 3 hackers in each room," << endl;
    cout << "when Carmen and her hackers steal all of the server's top-secret files, when your computer's" << endl;
    cout << "maintenance level reaches zero, or when the hackers succeed in making you rage quit." << endl;
    cout << endl;
    //start of the game
    cout << "To begin the game, please enter your name:" << endl;
    getline(cin, playerName); //store all the parts of the user input to the player name
    Player player(playerName);
    cout << "Hello, " << playerName << "!" << endl;
    cout << endl;
    cout << "You will now be placed inside a Best Buy store in order to purchase parts for the game." << endl;
    cout << "When you are done shopping, you will be placed in the first server room to start the game." << endl;
    cout << "Here is a selection of the parts available for purchase:" << endl;
    bestBuy.displayMenu(player);
}