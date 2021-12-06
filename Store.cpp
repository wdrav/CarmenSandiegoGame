// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Store.h"
#include "Player.h"

using namespace std;

//constructors

Store::Store(){
    setPrices(1);
    setBaseInternetPrice(2); 
}

Store::Store(int rn){
    setPrices(rn);
}

//getters

double Store::getcpuPrice(){
    return cpuPrice;
}

double Store::getgpuPrice(){
    return gpuPrice;
}

double Store::getPowerSupplyPrice(){
    return powerSupplyPrice;
}

double Store::getComputerCasePrice(){
    return computerCasePrice;
}

double Store::getInternetCardPrice(){
    return internetCardPrice;
}

double Store::getKeyboardAndMousePrice(){
    return keyboardAndMousePrice;
}

double Store::getPremadePrice(){
    return premadePrice;
}

int Store::getMaxParts(){
    return MAX_PART;
}

double Store::getAntivirusPrice(){
    return antivirusPrice;
}

double Store::getvpnPrice(){
    return vpnPrice;
}

int Store::getInternetPrice(){
    return internetPrice;
}

//setters

void Store::setBaseInternetPrice(int level){
    switch(level){
        case 2:{
        baseInternetPrice = 10;
        break;
        }

        case 3:{
        baseInternetPrice = 25;
        break;
        }

        case 4:{
        baseInternetPrice = 40;
        break;
        }

        case 5:{
        baseInternetPrice = 50;
        break;
        }
    }
}

/*  This function sets the pries depending on the room number of the best buy.
        Inputs: int room number
        Ouputs: sets the price of all of the variables

*/

void Store::setPrices(int roomNum){
    if(roomNum == 1){
        cpuPrice = basecpu;
        gpuPrice = basegpu;
        powerSupplyPrice = basePower;
        computerCasePrice = baseCase;
        internetCardPrice = baseInternet;
        keyboardAndMousePrice = baseKeyboard;
        premadePrice = basePremade;
        antivirusPrice = baseAntivirus;
        vpnPrice = basevpn;
        internetPrice = baseInternetPrice;
    }else if(roomNum == 2){
        cpuPrice = basecpu * 1.1;
        gpuPrice = basegpu * 1.1;
        powerSupplyPrice = basePower * 1.1;
        computerCasePrice = baseCase * 1.1;
        internetCardPrice = baseInternet * 1.1;
        keyboardAndMousePrice = baseKeyboard * 1.1;
        premadePrice = basePremade * 1.1;
        antivirusPrice = baseAntivirus * 1.1;
        vpnPrice = basevpn * 1.1;
        internetPrice = baseInternetPrice * 1.1;
    }else if(roomNum == 3){
        cpuPrice = basecpu * 1.2;
        gpuPrice = basegpu * 1.2;
        powerSupplyPrice = basePower * 1.2;
        computerCasePrice = baseCase * 1.2;
        internetCardPrice = baseInternet * 1.2;
        keyboardAndMousePrice = baseKeyboard * 1.2;
        premadePrice = basePremade * 1.2;
        antivirusPrice = baseAntivirus * 1.2;
        vpnPrice = basevpn * 1.2;
        internetPrice = baseInternetPrice * 1.2;
    }else if(roomNum == 4){
        cpuPrice = basecpu * 1.25;
        gpuPrice = basegpu * 1.25;
        powerSupplyPrice = basePower * 1.25;
        computerCasePrice = baseCase * 1.25;
        internetCardPrice = baseInternet * 1.25;
        keyboardAndMousePrice = baseKeyboard * 1.25;
        premadePrice = basePremade * 1.25;
        antivirusPrice = baseAntivirus * 1.25;
        vpnPrice = basevpn * 1.25;
        internetPrice = baseInternetPrice * 1.25;
    }else if(roomNum == 5){
        cpuPrice = basecpu * 1.3;
        gpuPrice = basegpu * 1.3;
        powerSupplyPrice = basePower * 1.3;
        computerCasePrice = baseCase * 1.3;
        internetCardPrice = baseInternet * 1.3;
        keyboardAndMousePrice = baseKeyboard * 1.3;
        premadePrice = basePremade * 1.3;
        antivirusPrice = baseAntivirus * 1.3;
        vpnPrice = basevpn * 1.3;
        internetPrice = baseInternetPrice * 1.3;
    }else{
        cpuPrice = basecpu;
        gpuPrice = basegpu;
        powerSupplyPrice = basePower;
        computerCasePrice = baseCase;
        internetCardPrice = baseInternet;
        keyboardAndMousePrice = baseKeyboard;
        premadePrice = basePremade;
        antivirusPrice = baseAntivirus;
        vpnPrice = basevpn;
        internetPrice = baseInternetPrice;
    }

}

/*
    displayMenu(Player p, int roomNum){
        This function is used after a player has landed on bestbuy, or is just starting the game and is given the option to buy goods.
        inputs: the player and the room number in order to update the prices based on which room you're in
        outputs: updates the amount of dogecoins and items a player has with every loop through buying something. Displays menu and price of cart.
*/ 

void Store::displayMenu(Player &p, int roomNum){
    setPrices(roomNum);
    int menuOption = 0;
    double totalSpent = 0;
    int numPartsPurchased = 0;
    double totalDogecoins = p.getDogecoin();
    cout << "You have " << p.getDogecoin() << " dogecoins, " << 
    p.getComputers() << " computer, and " << p.getVPN() << " VPN." << endl;
    //do while loop to show the menu if the player wants to do more than one action

    do{
        cout << "Please select the category of items you would like to purchase from:" << endl;
        cout << "1 - COMPUTER PARTS" << endl;
        cout << "2 - ANTIVIRUS SOFTWARE" << endl;
        cout << "3 - VIRTUAL PRIVATE NETWORK (VPN)" << endl;
        cout << "4 - INTERNET PROVIDER" << endl;
        cout << "5 - STOP SHOPPING" << endl;
        cin >> menuOption; //take in the player input
        switch(menuOption){
            case 1:{ //if they choose to buy a computer part
                int compPartsOption = 0;
                
                cout << "You currently have these parts:" << endl; //get the player's inventory
                cout << p.getnumcpu() << " CPU(s)" << endl;
                cout << p.getNumGpu() << " GPU(s)" << endl;
                cout << p.getnumPowerSupply() << " Power Supply Unit(s)" << endl;
                cout << p.getnumCases() << " Computer Case(s)" << endl;
                cout << p.getnumInternetCard() << " Internet Card(s)" << endl;
                cout << p.getnumKeyboardAndMouse() << " Keyboard and Mouse" << endl;
                cout << p.getComputers() << " Premade Computer(s)" << endl; 

                cout << "You can have a maximum of 3 of each computer part and 1 extra premade computer." << endl; //show the price of each item
                cout << "These are the different parts available for purchase:" << endl;
                cout << "1 - A CPU costs " << getcpuPrice() << " dogecoins." << endl;
                cout << "2 - A GPU costs " << getgpuPrice() << " dogecoins." << endl;
                cout << "3 - A Power Supply Unit costs " << getPowerSupplyPrice() << " dogecoins." << endl;
                cout << "4 - A Computer Case costs " << getComputerCasePrice() << " dogecoins." << endl;
                cout << "5 - An Internet Card costs " << getInternetCardPrice() << " dogecoins." << endl;
                cout << "6 - A Keyboard and Mouse costs " << getKeyboardAndMousePrice() << " dogecoins." << endl;
                cout << "7 - A premade Computer costs " << getPremadePrice() << " dogecoins." << endl;
                cout << "8 - Return to main Best Buy menu." << endl;
                do{
                    cout << "Please select a part you would like to purchase:" << endl;
                    cin >> compPartsOption;
                    switch(compPartsOption){
                        case 1:{ //for every item in the lists, display how many, if they are able to purchase that many, and the price
                            cout << "How many CPUs would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getnumcpu() + numPartsPurchased > 3){ //check if they only have 3 at the end of buying the items
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if(getcpuPrice() * numPartsPurchased  > p.getDogecoin()){ //if they don't have enough to do it
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumcpu(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getcpuPrice();
                                    totalDogecoins -= numPartsPurchased * getcpuPrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 2:{ //buying GPUs, using same format as with CPUs
                            cout << "How many GPUs would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getNumGpu() + numPartsPurchased > 3){
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if((getgpuPrice() * numPartsPurchased) > p.getDogecoin()){
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumgpu(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getgpuPrice();
                                    totalDogecoins -= numPartsPurchased * getgpuPrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 3:{ //Power supplies
                            cout << "How many Power Supply Units would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getnumPowerSupply() + numPartsPurchased > 3){
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if((getPowerSupplyPrice() * numPartsPurchased) > p.getDogecoin()){
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumPowerSupply(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getPowerSupplyPrice();
                                    totalDogecoins -= numPartsPurchased * getPowerSupplyPrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 4:{ //computer cases
                            cout << "How many Computer Cases would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getnumCases() + numPartsPurchased > 3){
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if((getComputerCasePrice() * numPartsPurchased) > p.getDogecoin()){
                                    cout << p.getDogecoin() << ", " << (getComputerCasePrice() * numPartsPurchased) + totalSpent << endl;
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumCases(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getComputerCasePrice();
                                    totalDogecoins -= numPartsPurchased * getComputerCasePrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 5:{
                            cout << "How many Internet Cards would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getnumInternetCard() + numPartsPurchased > 3){
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if((getInternetCardPrice() * numPartsPurchased) > p.getDogecoin()){
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumInternetCard(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getInternetCardPrice();
                                    totalDogecoins -= numPartsPurchased * getInternetCardPrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 6:{
                            cout << "How many Keyboards and Mice would you like to purchase?" << endl;
                            cin >> numPartsPurchased;
                            if(p.getnumKeyboardAndMouse() + numPartsPurchased > 3){
                                cout << "The maximum amount of each computer part you can have at one time is 3." << endl;
                                cout << "Please select a different number of parts to purchase or select a different part." << endl;
                            }
                            else{
                                if((getKeyboardAndMousePrice() * numPartsPurchased) > p.getDogecoin()){
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.addNumKeyboardAndMouse(numPartsPurchased);
                                    totalSpent += numPartsPurchased * getKeyboardAndMousePrice();
                                    totalDogecoins -= numPartsPurchased * getKeyboardAndMousePrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                    numPartsPurchased = 0;
                                }
                            }
                            break;
                        }
                        case 7:{
                            if(p.getComputers() > 0){
                                cout << "You are only allowed one premade computer at a time in your inventory." << endl;
                                cout << "Please select a different part to purchase." << endl;
                            }
                            else{
                                if(getPremadePrice() + totalSpent > p.getDogecoin()){
                                    cout << "You do not have enough dogecoins to complete this purchase." << endl;
                                }
                                else{
                                    p.setComputers(1);
                                    totalSpent += getPremadePrice();
                                    totalDogecoins -= getPremadePrice();
                                    cout << "Total cost of items so far: " << totalSpent << endl;
                                }
                            }
                            break;
                        }
                        case 8:{
                            cout << "Returning to Best Buy main menu..." << endl;
                            cout << "You now have these parts in your inventory:" << endl;
                            cout << p.getnumcpu() << " CPU(s)" << endl;
                            cout << p.getNumGpu() << " GPU(s)" << endl;
                            cout << p.getnumPowerSupply() << " Power Supply Unit(s)" << endl;
                            cout << p.getnumCases() << " Computer Case(s)" << endl;
                            cout << p.getnumInternetCard() << " Internet Card(s)" << endl;
                            cout << p.getnumKeyboardAndMouse() << " Keyboard and Mouse" << endl;
                            cout << p.getComputers() << " Premade Computer(s)" << endl;
                            break;
                        }
                        default:{
                            cout << "Invalid Input. Computer Parts menu ranges from 1 to 8." << endl; //in case the user enters a number not 1 - 8
                            break;
                        }
                    }
                    // cout << totalDogecoins << endl;
                    p.setDogecoins(totalDogecoins);
                }
                while(p.getDogecoin() > 0 && compPartsOption != 8);
                break;
            }
            case 2:{ //when buying antivirus USB sticks
                cout << "One USB stick of antivirus software costs " << getAntivirusPrice() << " Dogecoins and will" << endl;
                cout << "give you a one-time use to get rid of any viruses on your computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cin >> numPartsPurchased;
                if(numPartsPurchased * getAntivirusPrice() > p.getDogecoin()){
                    cout << "You don't have enough dogecoins for this." << endl;
                    break;
                }
                p.addNumUSBstick(numPartsPurchased);
                totalSpent += numPartsPurchased * getAntivirusPrice();
                totalDogecoins -= numPartsPurchased * getAntivirusPrice();
                cout << "Total cost of items so far: " << totalSpent << endl;
                p.setDogecoins(totalDogecoins);
                break;
            }
            case 3:{ //buying VPNS
                cout << "A VPN costs " << getvpnPrice() << " Dogecoins each. VPNs reduce your chances of getting hacked by" << endl; 
                cout << "preventing hackers from tracking down your main computer. The increase in security maxes out at 2 VPNs." << endl;
                cout << "How many VPNs would you like to purchase?" << endl;
                cin >> numPartsPurchased;
                if(numPartsPurchased * getvpnPrice() > p.getDogecoin()){
                    cout << "You don't have enough money for this" << endl;
                    break;
                }
                p.addVPN(numPartsPurchased);
                totalSpent += numPartsPurchased * getvpnPrice();
                totalDogecoins -= numPartsPurchased * getvpnPrice();
                cout << "Total cost of items so far: " << totalSpent << endl;
                p.setDogecoins(totalDogecoins);
                break;
            }
            case 4:{ //When buying IP level
                int level;
                setBaseInternetPrice(2);
                setPrices(roomNum);
                cout << "Internet provider level 2 costs " << getInternetPrice() << " Dogecoins." << endl;
                setBaseInternetPrice(3);
                setPrices(roomNum);
                cout << "Internet provider level 3 costs " << getInternetPrice() << " Dogecoins." << endl;
                setBaseInternetPrice(4);
                setPrices(roomNum);
                cout << "Internet provider level 4 costs " << getInternetPrice() << " Dogecoins." << endl;
                setBaseInternetPrice(5);
                setPrices(roomNum);
                cout << "Internet provider level 5 costs " << getInternetPrice() << " Dogecoins." << endl;
                cout << "Internet providers can be upgraded at a later time if desired. Having a better internet provider" << endl;
                cout << "increases your chances of winning a hacker battle. Which internet provider would you like to buy?" << endl;
                cin >> level;
                setBaseInternetPrice(level);
                if(getInternetPrice() > p.getDogecoin()){
                    cout << "You don't have enough money for that!" << endl;
                    break;
                }
                p.setIPlvl(level);
                setPrices(roomNum);
                totalSpent += getInternetPrice();
                totalDogecoins -= getInternetPrice();
                cout << "Total cost of items so far: " << totalSpent << endl;
                // cout << totalDogecoins << endl;
                p.setDogecoins(totalDogecoins);
                break;
            }
            case 5:{ //if the user chooses to leave
                cout << "Thank you for shopping at Best Buy!" << endl;
                
                break;
            }
            default:{
                cout << "Invalid input. Please select a menu option 1 to 5." << endl;
                break;
            }
        }

    }
    while(menuOption != 5); //end the loop if the user chooses 5
}

