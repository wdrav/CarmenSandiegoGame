// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Player.h"
#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

//constructors

Player::Player(){
    name = "Player1";
    dogecoins = 200;
    frustration = 0;
    computers = 1;
    IPlevel = 1;
    numVPN = 1;
    progress = 0;
    hackersDefeated = 0;
    numCases = 0;
    numPowerSupply = 0;
    numKeyboardAndMouse = 0;
    numInternetCard = 0;
    numcpu = 0;
    numgpu = 0;
    numUSB = 0;
    numVirus = 0;
    maintenanceLevel = 100;
    totalHackersDefeated = 0;

}

Player::Player(string n){
    name = n;
    dogecoins = 200;
    frustration = 0;
    computers = 1;
    IPlevel = 1;
    numVPN = 1;
    progress = 0;
    hackersDefeated = 0;
    numCases = 0;
    numPowerSupply = 0;
    numKeyboardAndMouse = 0;
    numInternetCard = 0;
    numcpu = 0;
    numgpu = 0;
    numUSB = 0;
    numVirus = 0;
    maintenanceLevel = 100;
    totalHackersDefeated = 0;

}

//setters

void Player::setName(string n){
    name = n;
}

void Player::setFrustration(int f){
    frustration = f;
}

void Player::setDogecoins(double d){
    dogecoins = d;
}

void Player::setIPlvl(int l){
    IPlevel = l;
}

void Player::setProgress(int p){
    progress = p;
}

void Player::addHackersDefeated(int h){
    hackersDefeated += h;
}
void Player::resetHackersDefeated(){
    hackersDefeated = 0;
}

void Player::addVPN(int vpn){
    numVPN += vpn;
}

void Player::setComputers(int c){
    computers = c;
}

void Player::addNumgpu(int g){
    numgpu += g;
}

void Player::addNumcpu(int c){
    numcpu += c;
}

void Player::addNumPowerSupply(int p){
    numPowerSupply += p;
}

void Player::addNumCases(int c){
    numCases += c;
}

void Player::addNumInternetCard(int i){
    numInternetCard += i;
}

void Player::addNumKeyboardAndMouse(int k){
    numKeyboardAndMouse += k;
}

void Player::addNumUSBstick(int u){
    numUSB += u;
}

void Player::subNumgpu(int g){
    numgpu -= g;
}

void Player::subNumcpu(int c){
    numcpu -= c;
}

void Player::subNumPowerSupply(int p){
    numPowerSupply -= p;
}

void Player::subNumCases(int c){
    numCases -= c;
}

void Player::subNumInternetCard(int i){
    numInternetCard -= i;
}

void Player::subNumKeyboardAndMouse(int k){
    numKeyboardAndMouse -= k;
}

void Player::addVirus(int a){
    numVirus += a;
}

void Player::addMaintenance(int m){

    if(maintenanceLevel + m > 100){
        maintenanceLevel = 100;
    }else{
        maintenanceLevel += m;
    }
}

void Player::subMaintenance(int m){
    if(maintenanceLevel <= m){
        maintenanceLevel = 0;
    }else{
        maintenanceLevel -= m;
    }
}

void Player::setTotalHackersDefeated(int x){
    totalHackersDefeated += x;
}

//getters

double Player::getDogecoin(){
    return dogecoins;
}

string Player::getName(){
    return name;
}

int Player::getIPlvl(){
    return IPlevel;
}

int Player::getFrustration(){
    return frustration;
}

int Player::getProgress(){
    return progress;
}

int Player::getHackersDefeated(){
    return hackersDefeated;
}

int Player::getComputers(){
    return computers;
}

int Player::getVPN(){
    return numVPN;
}

int Player::getNumGpu(){
    return numgpu;
}

int Player::getnumcpu(){
    return numcpu;
}

int Player::getnumPowerSupply(){
    return numPowerSupply;
}

int Player::getnumCases(){
    return numCases;
}

int Player::getnumInternetCard(){
    return numInternetCard;
}

int Player::getnumKeyboardAndMouse(){
    return numKeyboardAndMouse;
}

int Player::getnumUSB(){
    return numUSB;
}

int Player::getVirus(){
    return numVirus;
}

int Player::getMaintenance(){
    return maintenanceLevel;
}

int Player::getTotalParts(){
    int parts = getNumGpu() + getnumcpu() + getnumPowerSupply() + getnumCases() + getnumInternetCard() + getnumKeyboardAndMouse();
    return parts;
}

int Player::getTotalHackersDefeated(){
    return totalHackersDefeated;
}


/* This function will find determine the outcome of a battle with a hacker by using a specific equation, and then seeing if the result is greater or less
    than 0. 

    Inputs: a hacker object to fight
    Outputs:  true or false for whether the player beats the hacker or not
*/

bool Player::fightHacker(Hacker h){
 
    cout << "You have chosen to fight " << h.getName() << "!" << endl;
    cout << "Let's see if you have what it takes: " << endl << endl;
    int rand1 = rand() % 6 + 1; //getting 2 random numbers 1 - 6
    int rand2 = rand() % 6 + 1; 

    double eq1 = rand1 * double(IPlevel); //doing the equation
    double eq2 = (rand2 * double(h.getRoomNum())) * (1/ double(numVPN));

    double total = eq1 - eq2;

    if(total > 0.0){ //checking the result - if win
        cout << "You have won the battle!" << endl;
        cout << "For your success, you have won 50 dogecoins!" << endl << endl;

        dogecoins += 50;

        cout << "Unfortunately, you have lost a computer part in the aftermath." << endl << endl;
        bool foundPart = false;
        int randpart = 0;
        int count = 0;
        int used[] = {0,0,0,0,0,0}; //an array to keep track of checked parts to decrease time

        while(!foundPart){ //losing a part, found many places in the code 
            randpart = rand() % 6; // get a random number to find the part under that number
            
            if(randpart == 0){ //if else to connect the randpart with a part

                if(used[0] == 1){
                    continue; //keep getting random numbers if this part has already been checked
                }

                used[0] = 1; //has checked this part

                if(getNumGpu() > 0){
                    addNumgpu(-1); //remove from inventory
                    cout << "You lost a GPU!" << endl;
                    foundPart = true; //break the loop 
                }

            }else if(randpart == 1){

                if(used[1] == 1){
                    continue;
                }

                used[1] = 1;

                if(getnumcpu() > 0){
                    addNumcpu(-1);
                    cout << "You lost a CPU!" << endl;
                    foundPart = true;
                }

            }else if(randpart == 2){
                if(used[2] == 1){
                    continue;
                }

                used[2] = 1;

                if(getnumPowerSupply() > 0){
                    addNumPowerSupply(-1);
                    cout << "You lost a Power supply!" << endl;
                    foundPart = true;
                }

            }else if(randpart == 3){
                if(used[3] == 1){
                    continue;
                }

                used[3] = 1;

                if(getnumCases() > 0){
                    addNumCases(-1);
                    cout << "You lost a Case!" << endl;
                    foundPart = true;
                }

            }else if(randpart == 4){
                if(used[4] == 1){
                    continue;
                }

                used[4] = 1;

                if(getnumInternetCard() > 0){
                    addNumInternetCard(-1);
                    cout << "You lost an internet card!" << endl;
                    foundPart = true;
                }

            }else if(randpart == 5){
                if(used[5] == 1){
                    continue;
                }

                used[5] = 1;

                if(getnumKeyboardAndMouse() > 0){
                    addNumKeyboardAndMouse(-1);
                    cout << "You lost a Keyboard and mouse!" << endl;
                    foundPart = true;
                }

            }

            int total = 0;
            
            for(int i = 0; i < 6; i++){ //do every loop to check if every part has been checked
                total += used[i];
            }

            if(total == 5){ //if every part has been checked and there are no parts left, 
                cout << "You have no computer parts left!" << endl;
                break;
            }
        }

        return true;

    }else{
        cout << "OH NO! You have lost the battle with " << h.getName() << endl;
        int chanceVirus = rand() % 10; //getting a number 0-9 to see if they get a virus

        if(chanceVirus == 0){
            cout << "Unbelievable. The hacker has given you a virus!" << endl;
            cout << "Now, every turn with the virus, you will lose 10 points of mainetance level." << endl;
            addVirus(1);
        }else{
            cout << "You got lucky this time. You haven't gotten a virus." << endl;
        }

        return false;
        
    }

    int chanceLoseMaintenance = rand() % 10;

    if(chanceLoseMaintenance <= 2){
        maintenanceLevel -= 10;
        cout << "The battle took a lot out of your computer. Because of this, your maintenance has dropped 10 points." << endl;
        if(maintenanceLevel <= 0){
            cout << "By dropping 10 points, you have dropped to zero, and lost the game. Better luck next time!" << endl; //give reasoning for losing, travel room checks if lost or not
            
        }
    }
 
    return true;
}

/*
    forfeit: This function is used if the player decides to forfeit a hacker battle.
        Inputs: Hacker object that they have chosen to forfeit
        Outputs: Prints out that they have lost their parts

*/

void Player::forfeit(Hacker h){
    cout << "You have chosen to forfeit the battle. How disappointing. " << endl; //
    cout << "Because of this, you lose all of your spare computer parts. " << endl;
    numgpu = 0;
    numcpu = 0; //remove all parts
    numPowerSupply = 0;
    numCases = 0;
    numInternetCard = 0;
    numKeyboardAndMouse = 0;
    return;
}