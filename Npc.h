// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#ifndef NPC_H
#define NPC_H

#include <iostream>

using namespace std;

class Npc {

    private:
        string name;
        int adjective;
        int roomNum;

    public:
        //constructors
        Npc(string n, int rn);
        Npc();

        //getters
        string getName();
        int getAdjective();
        int getRoomNum();

        //setters
        void setName(string n);
        void setRoomNum(int n);

        //other methods
        void setRandAdjective(); //determines if npc is good, neutral, or bad

};

#endif