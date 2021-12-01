// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Hacker.h"
#include <iostream>

using namespace std;

//constructors

Hacker::Hacker(){
    name = "Hacker1";
    roomNum = 1;
}

Hacker::Hacker(string n, int rn){
    name = n;
    roomNum = rn;
}

//getters

string Hacker::getName(){
    return name;
}

int Hacker::getRoomNum(){
    return roomNum;
}

//setters

void Hacker::setName(string n){
    name = n;
}

void Hacker::setRoomNum(int n){
    roomNum = n;
}