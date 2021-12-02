// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#ifndef STORE_H
#define STORE_H
#include "Player.h"

using namespace std;

class Store {

    public:
        //constructors:
        Store();
        Store(int roomNum); //possibly transfer setPrices function info to here

        //set the prices based on the room number
        void setPrices(int roomNum);

        //set the base internet provider price based on the level
        void setBaseInternetPrice(int level);

        //display the menu of available parts
        void displayMenu(Player &p, int roomNum);

        //getters
        double getcpuPrice();
        double getgpuPrice();
        double getPowerSupplyPrice();
        double getComputerCasePrice();
        double getInternetCardPrice();
        double getKeyboardAndMousePrice();
        double getPremadePrice();
        int getMaxParts();
        double getAntivirusPrice();
        double getvpnPrice();
        int getInternetPrice();
    
    private:
        
        //Computer parts
        double cpuPrice;
        double gpuPrice;
        double powerSupplyPrice;
        double computerCasePrice;
        double internetCardPrice;
        double keyboardAndMousePrice;
        double premadePrice;

        const double basecpu = 10;
        const double basegpu = 20;
        const double basePower = 5;
        const double baseCase = 15;
        const double baseInternet = 5;
        const double baseKeyboard = 10;
        const double basePremade = 100;

        //max number of parts that can be purchased
        const int MAX_PART = 3;

        //antivirus software
        double antivirusPrice;
        const double baseAntivirus = 10;

        //vpn
        double vpnPrice;
        const double basevpn = 20;

        //internet provider
        int baseInternetPrice = 0;
        int internetPrice;

    

};

#endif