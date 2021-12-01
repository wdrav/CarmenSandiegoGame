// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Npc.h"
#include <iostream>
#include <time.h>
#include <random>

using namespace std;

Npc::Npc(){
    name = "Mysterious figure";
    roomNum = 1;
    setRandAdjective();
}

Npc::Npc(string n, int rn){
    name = n;
    roomNum = rn;
    setRandAdjective();
}

string Npc::getName(){
    return name;
}

int Npc::getAdjective(){
    return adjective;
}

int Npc::getRoomNum(){
    return roomNum;
}

void Npc::setName(string n){
    name = n;
}

void Npc::setRoomNum(int n){
    roomNum = n;
}

/* This function sets adjective to a number, 0 - 2 that shows the 
    adjective of the npc, 0 being good, 1 being neutral, and 2 being bad.
        Inputs: none
        Outputs: sets the int of adjective
*/
void Npc::setRandAdjective(){
    // srand(time(0)); at the top of the main function
    int selection = rand() % 3;
    adjective = selection;
}