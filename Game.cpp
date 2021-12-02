// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Game.h"
#include "Npc.h"
#include "Store.h"
#include "Hacker.h"
#include "Map.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

Game::Game(){
    turn = 1;
    progressLevel = 0;
    puzzleNum = 0;
    numMoves = 0;
    count = 0;
    room = 1;
}

void Game::setProgress(int p){
    progressLevel += p;
}

void Game::addMove(){
    numMoves++;
}

//getters

int Game::getTurn(){
    return turn;
}

int Game::getProgress(){
    return progressLevel;
}

string Game::getRandPuzzle(){
    /*
    this function will set puzzleNum to a random index between
    0-9 and will return the puzzle at this index
    */
   int num = rand() % 10;
   puzzleNum = num;
   return puzzles[num];
}

string Game::getAnswer(){
    return answers[puzzleNum];
    /*
    this function will use the random puzzleNum generated in getRandPuzzle
    to return the answer to the puzzle that is randomly selected
    */
}

int Game::getMoves(){
    return numMoves;
}



void Game::repairComputer(Player p){
    int option;
    int numPart = 0;
    int count = 0;
    if(p.getMaintenance() >= 100){
        cout << "Your computer does not need repair! Yet..." << endl;
    }
    else{
        if(p.getVirus() > 0){
            cout << "Your computer has a virus. You cannot repair your computer." << endl;
        }
        do{
            cout << "INVENTORY:" << endl;
            cout << "1 - CPU: " << p.getnumcpu() << endl;
            cout << "2 - GPU: " << p.getNumGpu() << endl;
            cout << "3 - Power Supply Unit: " << p.getnumPowerSupply() << endl;
            cout << "4 - Computer Case: " << p.getnumCases() << endl;
            cout << "5 - Internet Card: " << p.getnumInternetCard() << endl;
            cout << "6 - Keyboard and Mouse: " << p.getnumKeyboardAndMouse() << endl;
            cout << "Enter the number of the computer part you would like to use. Press 7 to end repair." << endl;
            cin >> option;
            count += numPart;
            switch(option){
                case 1:{
                    if(p.getnumcpu() > 0){
                        cout << "How many CPUs would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumcpu()){
                            cout << "You have less than " << numPart << " CPUs." << endl; 
                        }
                        else{
                            p.subNumcpu(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any CPUs." << endl;
                    }
                    break;
                }
                case 2:{
                    if(p.getNumGpu() > 0){
                        cout << "How many GPUs would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getNumGpu()){
                            cout << "You have less than " << numPart << " GPUs." << endl;
                        }
                        else{
                            p.subNumgpu(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any GPUs." << endl;
                    }
                    break;
                }
                case 3:{
                    if(p.getnumPowerSupply() > 0){
                        cout << "How many Power Supply Units would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumPowerSupply()){
                            cout << "You have less than " << numPart << " Power Supply Units." << endl;
                        }
                        else{
                            p.subNumPowerSupply(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any Power Supply Units." << endl;
                    }
                    break;
                }
                case 4:{
                    if(p.getnumCases() > 0){
                        cout << "How many Computer Cases would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumCases()){
                            cout << "You have less than " << numPart << " Computer Cases." << endl; 
                        }
                        else{
                            p.subNumcpu(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any Computer Cases." << endl;
                    }
                    break;
                }
                case 5:{
                    if(p.getnumInternetCard() > 0){
                        cout << "How many Internet Cards would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumInternetCard()){
                            cout << "You have less than " << numPart << " Internet Cards." << endl; 
                        }
                        else{
                            p.subNumInternetCard(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any Internet Cards." << endl;
                    }
                    break;
                }
                case 6:{
                    if(p.getnumKeyboardAndMouse() > 0){
                        cout << "How many Keyboard and Mice would you like to use? (Between 1 and 5)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumKeyboardAndMouse()){
                            cout << "You have less than " << numPart << " Keyboard and Mice." << endl; 
                        }
                        else{
                            p.subNumKeyboardAndMouse(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any Keyboard and Mice." << endl;
                    }
                    break;
                }
                case 7:{
                    cout << "You have successfully exited the computer repair process. Your computer's maintenance level is currently at " << p.getMaintenance() << "." << endl;
                    break;
                }
                default:{
                    cout << "Invalid input. Please select a number 1 to 7 from the menu." << endl;
                    break;
                }
            }
            p.addMaintenance(20 * numPart);
        }
        while(p.getMaintenance() < 100 && count < 5 && option != 7); //check if count is necessary
        cout << "You have repaired your computer to a maintenance level of " << p.getMaintenance() << "!" << endl;
    }
}

void Game::displayStats(Player p){
    /* Display all of the stats of the player, the number of moves they have taken,
        the frustration, the maintenence of the computer, the dogecoins, and the parts.
    */
   cout << "Room Number: " << room << endl;
   cout << "Turn Number: " << turn << endl;
   cout << "Current computer mainenance level: " << p.getMaintenance() << endl;
   cout << "Number of viruses: " << p.getVirus() << endl;
   cout << "Computer parts available: " << endl;
   cout << "\tNumber of CPUs: " << p.getnumcpu() << endl;
   cout << "\tNumber of GPUs: " << p.getNumGpu() << endl;
   cout << "\tNumber of Power Supplies: " << p.getnumPowerSupply() << endl;
   cout << "\tNumber of Computer Cases: " << p.getnumCases() << endl;
   cout << "\tNumber of Internet Cards: " << p.getnumInternetCard() << endl;
   cout << "\tNumber of Keyboard and Mouse: " << p.getnumKeyboardAndMouse() << endl;
   cout << "\tNumber of Premade Computers: " << p.getComputers() << endl;
   cout << "Number of Antivirus sticks available: " << p.getnumUSB() << endl;
   cout << "Number of VPNs available: " << p.getVPN() << endl;
   cout << "Internet Provider Level: " << p.getIPlvl() << endl;
   cout << "Dogecoins: " << p.getDogecoin() << endl;
   cout << "Frustration level: " << p.getFrustration() << endl;
   cout << "Progress: " << p.getProgress() << endl;
   cout << "Number of hackers defeated: " << p.getHackersDefeated() << endl << endl;

}

void Game::misfortune(Player p){
    /*
        returns whether or not a misfortune occurs at the end of every turn
    */
    bool misfortune = false;
    
    string arr[] = {"Vpn", "Gpu", "Cpu", "Power supply", "Cases", "Internet Card", "Keyboard and mouse", "USB", "Antivirus"};

    int i = rand() % 10;

    if(i <= 2){ //if it is 0, 1, or 2
        misfortune = true;
    }else{
        misfortune = false;
    }
    

    if(misfortune){
        if(i == 0){
            //robbed of a computer part
            cout << "OH NO! Your team was robbed by Carmen’s dastardly hackers!" << endl;

            bool foundPart = false;
            int randpart = 0;
            int count = 0;
            int used[] = {0,0,0,0,0,0,0,0};

            while(!foundPart){
                randpart = rand() % 6;
                
                if(randpart == 0){
                    if(used[0] == 1){
                        continue;
                    }

                    used[0] = 1;

                    if(p.getNumGpu() > 0){
                        p.addNumgpu(-1);
                        cout << "You lost a GPU!" << endl;
                        foundPart = true;
                    }


                }else if(randpart == 1){
                    if(used[1] == 1){
                        continue;
                    }

                    used[1] = 1;

                    if(p.getnumcpu() > 0){
                        p.addNumcpu(-1);
                        cout << "You lost a CPU!" << endl;
                        foundPart = true;
                    }
                    
                }else if(randpart == 2){
                    if(used[2] == 1){
                        continue;
                    }

                    used[2] = 1;

                    if(p.getnumPowerSupply() > 0){
                        p.addNumPowerSupply(-1);
                        cout << "You lost a Power supply!" << endl;
                        foundPart = true;
                    }

                }else if(randpart == 3){
                    if(used[3] == 1){
                        continue;
                    }

                    used[3] = 1;

                    if(p.getnumCases() > 0){
                        p.addNumCases(-1);
                        cout << "You lost a Case!" << endl;
                        foundPart = true;
                    }

                }else if(randpart == 4){
                    if(used[4] == 1){
                        continue;
                    }

                    used[4] = 1;

                    if(p.getnumInternetCard() > 0){
                        p.addNumInternetCard(-1);
                        cout << "You lost an internet card!" << endl;
                        foundPart = true;
                    }

                }else if(randpart == 5){
                    if(used[5] == 1){
                        continue;
                    }

                    used[5] = 1;

                    if(p.getnumKeyboardAndMouse() > 0){
                        p.addNumKeyboardAndMouse(-1);
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
                    i = 1;
                    break;
                }
            }
            
        }else if(i == 1){
            cout << "OH NO! Your computer was damaged!" << endl;
            p.subMaintenance(10);
            if(p.getMaintenance() <= 0){
                cout << "You maintenance level is too low to continue! You lose!" << endl;
                endGame(p);
            }
            
        }else if(i == 2){
            cout << "OH NO! Why won't my code work????" << endl;
            p.setFrustration(10);

            if(p.getFrustration() >= 100){
                cout << "OH NO! You have rage quit!" << endl;
                cout << "Looks like you couldn't handle Carmen's hackers." << endl;
                endGame(p);
            }
        }
    }
}

void Game::speakToNpc(Npc n, Player p){
    /* 
        means that the player has run into an npc object on the map, and is 
        able to get a puzzle or test their luck and see if the npc object is good, 
        neutral or bad, and then get the consequences
    */

   int choice;
   bool correctChoice = true;

   cout << "You have found a mysterious person on your travels. " << endl << endl;
   cout << "They have a puzzle, and would like to see if you can solve it" << endl << endl;
   cout << "You can also take your chances to see if they're your friend or not" <<  endl << endl;
   cout << "Take puzzle: 1" << endl;
   cout << "Take your chances: 2" << endl;
   
    while(correctChoice){
        cin >> choice;
        switch(choice){
            case 1: {
                string ans;

                cout << getRandPuzzle() << endl;
                cin >> ans;

                if(ans == getAnswer()){
                    cout << "Nice job! You got the question right!" << endl;
                    int part = rand() % 6;
                    switch(part){
                        case 0:{
                            cout << "You've gotten a GPU!" << endl;
                            p.addNumgpu(1);
                            break;
                        }
                        case 1:{
                            cout << "You've gotten a CPU!" << endl;
                            p.addNumcpu(1);
                            break;
                        }
                        case 2:{
                            cout << "You've gotten a Power Supply!" << endl;
                            p.addNumPowerSupply(1);
                            break;
                        }
                        case 3:{
                            cout << "You've gotten a Case!" << endl;
                            p.addNumCases(1);
                            break;
                        }
                        case 4:{
                            cout << "You've gotten an internet card!" << endl;
                            p.addNumInternetCard(1);
                            break;
                        }
                        case 5:{
                            cout << "You've gotten a Keyboard and mouse!" << endl;
                            p.addNumKeyboardAndMouse(1);
                            break;
                        }

                        default: break;

                    }
                }else{
                    cout << "You've gotten the problem wrong! " << endl;

                }
                correctChoice = false;

                break;
           }
            case 2:{
                cout << endl << "You've taken your chances!" << endl;
                if(n.getAdjective() == 0){
                    cout << endl << "Oh no! This NPC is an enemy!" << endl;
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

                            if(p.getNumGpu() > 0){
                                p.addNumgpu(-1);
                                cout << "You lost a GPU!" << endl;
                                foundPart = true;
                            }


                        }else if(randpart == 1){
                            if(used[1] == 1){
                                continue;
                            }

                            used[1] = 1;

                            if(p.getnumcpu() > 0){
                                p.addNumcpu(-1);
                                cout << "You lost a CPU!" << endl;
                                foundPart = true;
                            }

                        }else if(randpart == 2){
                            if(used[2] == 1){
                                continue;
                            }

                            used[2] = 1;

                            if(p.getnumPowerSupply() > 0){
                                p.addNumPowerSupply(-1);
                                cout << "You lost a Power supply!" << endl;
                                foundPart = true;
                            }

                        }else if(randpart == 3){
                            if(used[3] == 1){
                                continue;
                            }

                            used[3] = 1;

                            if(p.getnumCases() > 0){
                                p.addNumCases(-1);
                                cout << "You lost a Case!" << endl;
                                foundPart = true;
                            }

                        }else if(randpart == 4){
                            if(used[4] == 1){
                                continue;
                            }

                            used[4] = 1;

                            if(p.getnumInternetCard() > 0){
                                p.addNumInternetCard(-1);
                                cout << "You lost an internet card!" << endl;
                                foundPart = true;
                            }

                        }else if(randpart == 5){
                            if(used[5] == 1){
                                continue;
                            }

                            used[5] = 1;

                            if(p.getnumKeyboardAndMouse() > 0){
                                p.addNumKeyboardAndMouse(-1);
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
                }else if(n.getAdjective() == 1){
                    cout << endl << "Phew. This NPC is neutral. Nothing happens! :)" << endl;
                }else if(n.getAdjective() == 2){
                    cout << endl << "You got lucky! This NPC is a friend!" << endl;
                    int part = rand() % 6;
                    switch(part){
                        case 0:{
                            cout << "You've gotten a GPU!" << endl;
                            p.addNumgpu(1);
                            break;
                        }
                        case 1:{
                            cout << "You've gotten a CPU!" << endl;
                            p.addNumcpu(1);
                            break;
                        }
                        case 2:{
                            cout << "You've gotten a Power Supply!" << endl;
                            p.addNumPowerSupply(1);
                            break;
                        }
                        case 3:{
                            cout << "You've gotten a Case!" << endl;
                            p.addNumCases(1);
                            break;
                        }
                        case 4:{
                            cout << "You've gotten an internet card!" << endl;
                            p.addNumInternetCard(1);
                            break;
                        }
                        case 5:{
                            cout << "You've gotten a Keyboard and mouse!" << endl;
                            p.addNumKeyboardAndMouse(1);
                            break;
                        }

                        default: break;

                    }
               }

                correctChoice = false;
               break;
           }
           default: 
           cout << "Invalid option. pick again." << endl; //have to add loop
           correctChoice = true;
           break;
       }
    }

return;

}

void Game::browseStackOverFlow(Player p){
    /* 
        prompts the user to either pick a game or a puzzle to 
        reduce frustration, and then adjust the frustration of the player 
        accordingly.
    */

    int option;
    bool choice = true;
    cout << "You've chosen to browse Stack Overflow!" << endl;
    cout << "You have two options: " << endl;
    cout << "\t1: Solve a puzzle" << endl;
    cout << "\t2: Play rock paper scissors" << endl;
    
    while(choice){
        cin >> option;
        switch(option){
            case 1:{
                string answer;
                cout << getRandPuzzle() << endl;
                cin >> answer;

                if(answer == getAnswer()){
                    cout << "Nice! You've gotten the answer right!" << endl;
                    if(p.getFrustration() < 5){
                        p.setFrustration(-1 * (p.getFrustration()));
                    }else{
                        p.setFrustration(-5);
                    }
                    cout << "Your frustration has gone down to " << p.getFrustration() << endl;
                }else{
                    cout << "Dang. You got that wrong." << endl;
                }
                choice = false;
                break;
            }
            case 2:{
                int selection;
                cout << "You've chosen to play rock paper scissors!" << endl;
                cout << "Type your selection: 1: rock 2: paper 3: scissors" << endl;
                bool keepGoing = true;
                while(keepGoing){
                    cin >> selection;
                    int num = rand() % 3 + 1; //1 is rock 2 is paper and 3 is scissors
                    if(selection == 1){
                        if(num == 1){
                            cout << "I also chose rock. Tie." << endl;
                        }else if(num == 3){
                            cout << "Oh you got me! I chose scissors." << endl;
                            if(p.getFrustration() < 5){
                                p.setFrustration(-1 *(p.getFrustration()));
                            }else{
                                p.setFrustration(-5);
                            }
                        }else if(num == 2){
                            cout << "I chose paper. You lose" << endl;
                        }else{
                            cout << "Invalid option. You can't cheat!" << endl;
                        }
                        keepGoing = false;
                    }else if(selection == 2){
                        if(num == 1){
                            cout << "You got me. I chose rock." << endl;
                            if(p.getFrustration() < 5){
                                p.setFrustration(-1 *(p.getFrustration()));
                            }else{
                                p.setFrustration(-5);
                            }
                        }else if(num == 2){
                            cout << "I also chose paper. Tie." << endl;
                        }else if(num == 2){
                            cout << "I chose scissors! You lose!" << endl;
                        }else{
                            cout << "Invalid option. You can't cheat!" << endl;
                        }
                        keepGoing = false;
                    }else if(selection == 3){
                        if(num == 1){
                            cout << "I chose rock. You lose." << endl;
                        }else if(num == 2){
                            cout << "I chose paper! You got me!" << endl;
                            if(p.getFrustration() < 5){
                                p.setFrustration(-1 *(p.getFrustration()));
                            }else{
                                p.setFrustration(-5);
                            }
                        }else if(num == 3){
                            cout << "I also chose scissors. Tie." << endl;
                        }else{
                            cout << "Invalid option. You can't cheat!" << endl;
                        }
                        keepGoing = false;
                    }else{
                        cout << "Choose again. 1 for rock, 2 for paper, and 3 for scissors." << endl;

                    }
                }
                choice = false;
                break;
            }default: 
                cout << "Please select either 1 or 2" << endl;
                choice = true;
                break;
        }
    }

}

//setters

void Game::setTurn(){
    turn++;
}

void Game::setPuzzles(string fileName){
    /*
        goes through a file of puzzles and sets the puzzles to
        each part of the array
    */
    ifstream stream;
    stream.open(fileName);

    if(stream.fail()){
        cout << "Could not open the file" << endl;
        return;
    }
    string currQ = "", line;
    int count = 0;

    while(getline(stream, line)){
        if(line == "---"){
            puzzles[count] = currQ;
            currQ = "";
            count++;
            continue;
        }

        currQ += line;
        currQ += "\n";
    }

    puzzles[count] = currQ;
    currQ = "";
    count++;



}

void Game::setAnswers(string fileName){
    /*
        goes through a file of answers and sets the answers to
        each part of the array
    */
    ifstream stream;
    stream.open(fileName);

    if(stream.fail()){
        cout << "Could not open the file" << endl;
        return;
    }
    string currQ = "", line;
    int count = 0;

    while(getline(stream, line)){
        if(line == "---"){
            answers[count] = currQ;
            currQ = "";
            count++;
            continue;
        }

        currQ += line;
    }

    answers[count] = currQ;
    currQ = "";
    count++;
    
}

void Game::useAntivirus(Player p){
    if(p.getVirus() == 0){
        cout << "You don't need to use antivirus" << endl;
        return;
    }

    if(p.getnumUSB() == 0){
        cout << "You don't have any USBs to remove the antivirus" << endl;
        return;
    }else{
        p.addNumUSBstick(-1);
        p.addVirus(-1 * p.getVirus());
        cout << "You have removed all of the viruses on your computer!" << endl;
    }
}

void Game::setHackers(string fileName){
    ifstream stream;
    stream.open(fileName);

    string line;
    int count = 0;

    if(stream.fail()){
        cout << "Failed to open the hacker file" << endl;
    }

    while(getline(stream, line)){
        string name = "", rn = "";
        for(int i = 0; i < line.length() - 2; i++){
            name += line[i];
        }
        rn = line.substr(line.length() - 1, 1);
        int roomNum = stoi(rn);
        Hacker temp(name, roomNum);

        hackArr[count] = temp;
        count++;

    }
}

Hacker Game::getHacker(int rn){

    int start = (rn * 4) - 4;
    bool foundHacker = false;
    while(!(foundHacker)){
        int randHacker = rand() % 4;
        foundHacker = true;
        cout << hackArr[start + randHacker].getName() << endl;
        for(int i = 0; i < 20; i++){
            if(hackArr[start + randHacker].getName() == hackUsed[i]){
                foundHacker = false;
            }
        }

        if(foundHacker == true){
            hackUsed[count] = hackArr[start + randHacker].getName();
            count++;
            return hackArr[start + randHacker];
        }
        
    }

    return hackArr[start];

}

void Game::newRoom(Map m, Player p){
    room++;
    if(room == 6){
        cout << "Nice job! You finished the game!" << endl;
        endGame(p);
        return;
    }

    m.resetMap();
    int numberHackers = rand() % 3 + 1; //1,2,3
    m.setHackerCount(numberHackers);
    bool running = true;
    for(int i = 0; i < numberHackers; i++){
        while(running){
            int rows = rand() % 5; //0-4
            int col = rand() % 9;  //0 - 8
            if(m.isHackerLocation()){
                continue;
            }else{
                m.spawnHacker(rows, col);
                running = false;
            }
        }
    }

    int numberNpcs = rand() % 3 + 1;
    m.setNPCCount(numberNpcs);
    running = true;
    for(int i = 0; i < numberNpcs; i++){
        while(running){
            int rows = rand() % 5; //0-4
            int col = rand() % 9;  //0 - 8 
            if(m.isHackerLocation()){
                continue;
            }else if(m.isNPCLocation()){
                continue;
            }else{
                m.spawnNPC(rows, col);
                running = false;
            }
        }
    }

    running = true;
    while(running){
        int rows = rand() % 5; //0-4
        int col = rand() % 9;  //0 - 8
        if(m.isHackerLocation()){
            continue;
        }else if(m.isNPCLocation()){
            continue;
        }else{
            m.spawnBestBuy(rows, col);
            running = false;
        }
            
    }

    turn = 0;
    p.resetHackersDefeated();
    
}

void Game::nextTurn(Map m, Player p, Npc n, Store s){
    turn++;
    p.setDogecoins(5);
    int num = 5;
    for(int i = 0; i < p.getNumGpu(); i++){
        p.setDogecoins(5);
        num += 5;
    }

    if(turn == 11){
        if(p.getHackersDefeated() == 0){
            cout << "You haven't defeated any hackers!!" << endl;
            cout << "You lose!" << endl;
            endGame(p);
        }else{
            //nextRoom implementation
        }

    }
    openMenu(m, p, n, s);
}

void Game::travelRoom(Map m, Player p, Npc n, Store s){
    char move;
    bool moving = true;
    int frustration = p.getFrustration();

    while(moving){
        m.displayMap();
        cout << "Valid moves are:" << endl;
        m.displayMoves();
        cout << "Input a move:" << endl;
        cin >> move;
        m.executeMove(move);
        frustration = p.getFrustration() + 2;
        p.setFrustration(frustration);
        if(p.getFrustration() >= 100){
            endGame(p);
        }
        misfortune(p);
        if(m.isHackerLocation()){
                // fight a hacker
            Hacker temp = getHacker(room); //add implementation to see if you landed on a spot with a hacker
            bool result = p.fightHacker(temp);
            if(p.getMaintenance() <=0){
                    cout << "Because of your maintenance level dropping, you have lost the game! Better luck next time!" << endl;
                    endGame(p);
                }
            if(result == false){
                progressLevel += 25;
                if(progressLevel >= 100){
                    cout << "Carment has reached her maximum progress! You have lost the game!" << endl;
                    endGame(p);
                }
            }
        }
        if(m.isNPCLocation()){
            speakToNpc(n, p);
        }
        if(m.isBestBuyLocation()){
            s.displayMenu(p, room);
        }
        //nextGame();
    }

}

void Game::endGame(Player p){
    //produces text that congratulates the player, shows them their stats, and 
    //finishes the game.
    cout << "You've finished the game!" << endl;
    cout << "Your stats are: " << endl;
    displayStats(p);

    fstream stream;
    

}

void Game::openMenu(Map m, Player p, Npc n, Store s){
    //displays the menu given to the player at the beginning of every turn.
    //switch statement inside of driver catches player response and what to do
    
    int option = 0;

    cout << "-----Menu-----" << endl;
    cout << "1 - Status Update" << endl;
    cout << "2 - Travel the Server Room" << endl;
    cout << "3 - Repair your Computer" << endl;
    cout << "4 - Use your Antivirus Software" << endl;
    cout << "5 - Browse Stack Overflow" << endl;
    cout << "6 - Quit" << endl;
    if(p.getHackersDefeated() >= 1){
        cout << "7 - Next Room" << endl;
    }


    cin >> option;


    switch(option){
        case 1:{ //status update
            displayStats(p);
            openMenu(m, p, n, s);
            break;
        }
        case 2:{
            travelRoom(m, p, n, s);
            break;


            // fight a hacker
            // Hacker temp = getHacker(room); //add implementation to see if you landed on a spot with a hacker
            // bool result = p.fightHacker(temp);
            // if(p.getMaintenance() <=0){
            //         cout << "Because of your maintenance level dropping, you have lost the game! Better luck next time!" << endl;
                        //eendgame;
            //     }
            // if(result == false){
            //     progressLevel += 25;
            //     if(progressLevel >= 100){
            //         cout << "Carment has reached her maximum progress! You have lost the game!" << endl;
            //         endGame(p);
            //     }
            // }
            // break;
        }
        case 3:{ 
            if(p.getTotalParts() <= 0){
                cout << "You do not have any computer parts to repair your computer." << endl;
            }
            else{
                repairComputer(p);
            }
            break;
            nextTurn(m, p, n, s);
            break;
        }
        case 4:{ 
            useAntivirus(p);
            nextTurn(m, p, n, s);
            break;
        }
        case 5:{ 
            browseStackOverFlow(p);
            nextTurn(m, p, n, s);
            break;
        }
        case 6:{ 
            cout << "You have quit the game!" << endl;
            endGame(p);
            break;
            
        }
        case 7:{ 
            if(p.getHackersDefeated() == 0){
                cout << "Invalid input. Select an option from 1 to 6" << endl;
                openMenu(m, p, n, s);
            }else if(p.getHackersDefeated() >= 1){
                //implement nextRoom method
            }
        }
        default:{
            cout << "Invalid input. Select an option from 1 to 6." << endl;
            openMenu(m, p, n, s);
            break;
        }
    }
}

