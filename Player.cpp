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
    maintenanceLevel += m;
}

void Player::subMaintenance(int m){
    if(maintenanceLevel <= m){
        maintenanceLevel = 0;
    }else{
        maintenanceLevel -= m;
    }
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


/* This function will find determine the outcome of a battle with a hacker
    Inputs: a hacker object
    Outputs: outputs true or false for whether the player beats the hacker
*/

bool Player::fightHacker(Hacker h){

    cout << "You have chosen to fight " << h.getName() << "!" << endl;
    cout << "Let's see if you have what it takes: " << endl << endl;
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;

    double eq1 = rand1 * double(IPlevel);
    double eq2 = (rand2 * double(h.getRoomNum())) * (1/ double(numVPN));

    double total = eq1 - eq2;

    if(total > 0.0){
        cout << "You have won the battle!" << endl;
        cout << "For your success, you have won 50 dogecoins!" << endl << endl;

        dogecoins += 50;

        cout << "Unfortunately, you have lost a computer part in the aftermath." << endl << endl;
        bool foundPart = false;
        int randpart = 0;
        int count = 0;
        int used[] = {0,0,0,0,0,0};

        while(!foundPart){
            randpart = rand() % 6;
            
            if(randpart == 0){

                if(used[0] == 1){
                    continue;
                }

                used[0] = 1;

                if(getNumGpu() > 0){
                    addNumgpu(-1);
                    cout << "You lost a GPU!" << endl;
                    foundPart = true;
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
            
            for(int i = 0; i < 6; i++){
                total += used[i];
            }

            if(total == 5){
                cout << "You have no computer parts left!" << endl;
                break;
            }
        }

        return true;

    }else{
        cout << "OH NO! You have lost the battle with " << h.getName() << endl;
        int chanceVirus = rand() % 10;

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
            cout << "By dropping 10 points, you have dropped to zero, and lost the game. Better luck next time!" << endl;
            
        }
    }
 
    return true;
}