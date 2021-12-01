// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#ifndef HACKER_H
#define HACKER_H

#include <iostream>

using namespace std;

class Hacker {

    private:
        string name;
        int roomNum;

    public:
        //constructors
        Hacker();
        Hacker(string n, int rn);

        //getters
        string getName();
        int getRoomNum();

        //setters
        void setName(string n);
        void setRoomNum(int n);
    
};

#endif