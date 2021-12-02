// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#ifndef PLAYER_H
#define PLAYER_H

#include "Hacker.h"
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std; 

class Player {

    private:
        string name;
        double dogecoins;
        int computers;
        int IPlevel;
        int frustration;
        int progress;
        int hackersDefeated;
        int numVPN;
        int numgpu;
        int numcpu;
        int numPowerSupply;
        int numCases;
        int numInternetCard;
        int numKeyboardAndMouse;
        int numUSB;
        int numVirus;
        int maintenanceLevel;

    public:
        //constructors
        Player();
        Player(string n);

        //setters
        void setName(string n);
        void setFrustration(int f);
        void setDogecoins(double d);
        void setIPlvl(int l);
        void setProgress(int p);
        void addHackersDefeated(int a);
        void resetHackersDefeated();
        void setComputers(int c);
        void addVPN(int v);
        void addNumgpu(int g);
        void addNumcpu(int c);
        void addNumPowerSupply(int p);
        void addNumCases(int c);
        void addNumInternetCard(int i);
        void addNumKeyboardAndMouse(int k);
        void addNumUSBstick(int u);
        void subNumgpu(int g);
        void subNumcpu(int c);
        void subNumPowerSupply(int p);
        void subNumCases(int c);
        void subNumInternetCard(int i);
        void subNumKeyboardAndMouse(int k);
        void addVirus(int a);
        void addMaintenance(int m);
        void subMaintenance(int m);
        
        //getters
        double getDogecoin();
        string getName();
        int getIPlvl();
        int getFrustration();
        int getProgress();
        int getHackersDefeated();
        int getComputers();
        int getVPN();
        int getNumGpu();
        int getnumcpu();
        int getnumPowerSupply();
        int getnumCases();
        int getnumInternetCard();
        int getnumKeyboardAndMouse();
        int getnumUSB();
        int getMaintenance();
        int getVirus();
        int getTotalParts();

        //methods
        bool fightHacker(Hacker h);


};

#endif