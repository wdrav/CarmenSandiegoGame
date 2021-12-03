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
#include <stdlib.h>

using namespace std;

Game::Game(){ // default constructor
    turn = 1;
    progressLevel = 0;
    puzzleNum = 0;
    numMoves = 0;
    count = 0;
    room = 0;
    for(int i = 0; i < 6; i++){ //sets all of the values to -1 to make sure that no false positives
        visitedNPCs[i][0] = -1;
        visitedNPCs[i][0] = -1;
    }
    countVisited = 0;
    playerScore = 0;
}

void Game::setProgress(int p){ //increase carmen's progress
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
    this function will use the random puzzleNum genewrated in getRandPuzzle
    to return the answer to the puzzle that is randomly selected
    */
}

int Game::getMoves(){
    return numMoves;
}

int Game::getRoom(){
    return room;
}

int Game::getPlayerScore(Player p){
    return playerScore;
}
/*  Function: repairComputer(Player p)
        This function is used on a turn when a player wants to repair their computer to increase their maintenance level. 
        Every part that they use increases the maintenance by 20, up to a maximum of 100.
        Inputs: Player p to get the amount of parts that the player has
        Outputs: Void, as all of the work is done in the function.
*/
void Game::repairComputer(Player &p){
    int option;
    int numPart = 0;
    int count = 0;
    if(p.getMaintenance() >= 100){ //check if the player doesn't need repair
        cout << "Your computer does not need repair! Yet..." << endl;
        turn--; //decreases the turn as the player couldn't do anything
    }
    else{
        if(p.getVirus() > 0){
            cout << "Your computer has a virus. You cannot repair your computer." << endl;
        }
        do{
            cout << "INVENTORY:" << endl; //print out the player's inventory
            cout << "1 - CPU: " << p.getnumcpu() << endl;
            cout << "2 - GPU: " << p.getNumGpu() << endl;
            cout << "3 - Power Supply Unit: " << p.getnumPowerSupply() << endl;
            cout << "4 - Computer Case: " << p.getnumCases() << endl;
            cout << "5 - Internet Card: " << p.getnumInternetCard() << endl;
            cout << "6 - Keyboard and Mouse: " << p.getnumKeyboardAndMouse() << endl;
            cout << "Enter the number of the computer part you would like to use. Press 7 to end repair." << endl;
            cin >> option;
            count += numPart; //
            switch(option){ //switch statement for which part the user has picked
                case 1:{ //pretty basic rubric for all of the cases
                    if(p.getnumcpu() > 0){
                        cout << "How many CPUs would you like to use? (Between 1 and 3)" << endl;
                        cin >> numPart; //take in how many they want to use
                        if(numPart > p.getnumcpu()){
                            cout << "You have less than " << numPart << " CPUs." << endl;  //if they don't have enough
                        }
                        else{
                            p.subNumcpu(numPart); //remove that many parts from the cpu

                        }
                    }
                    else{
                        cout << "You do not have any CPUs." << endl; // if they don't have any of that part
                    }
                    break;
                }
                case 2:{
                    if(p.getNumGpu() > 0){
                        cout << "How many GPUs would you like to use? (Between 1 and 3)" << endl;
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
                        cout << "How many Power Supply Units would you like to use? (Between 1 and 3)" << endl;
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
                        cout << "How many Computer Cases would you like to use? (Between 1 and 3)" << endl;
                        cin >> numPart;
                        if(numPart > p.getnumCases()){
                            cout << "You have less than " << numPart << " Computer Cases." << endl; 
                        }
                        else{
                            p.subNumCases(numPart);
                        }
                    }
                    else{
                        cout << "You do not have any Computer Cases." << endl;
                    }
                    break;
                }
                case 5:{
                    if(p.getnumInternetCard() > 0){
                        cout << "How many Internet Cards would you like to use? (Between 1 and 3)" << endl;
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
                        cout << "How many Keyboard and Mice would you like to use? (Between 1 and 3)" << endl;
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
                    p.addMaintenance(20 * count); //increase the maintenance to the player
                    cout << "You have successfully exited the computer repair process. Your computer's maintenance level is currently at " << p.getMaintenance() << "." << endl;
                    break;
                }
                default:{
                    cout << "Invalid input. Please select a number 1 to 7 from the menu." << endl;
                    break;
                }
            }
        }
        while(p.getMaintenance() < 100 && count < 5 && option != 7); //check if count is necessary
        cout << "You have repaired your computer to a maintenance level of " << p.getMaintenance() << "!" << endl;
    }
}

/* Display all of the stats of the player, the number of moves they have taken,
        the frustration, the maintenence of the computer, the dogecoins, and the parts.
        Inputs: Player whose stats must be printed
        Outputs: 
    */

void Game::displayStats(Player &p){

    //printing all of the stats
    
   cout << "Room Number: " << room << endl;
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
   cout << "Carmen's progress level: " << progressLevel << endl;
   cout << "Number of hackers defeated in this room: " << p.getHackersDefeated() << endl << endl;
   cout << "Your current score: " << p.getTotalHackersDefeated() << endl;
   cout << "Turn Number: " << turn << endl << endl;

}


/* Function: misfortune: This function takes in a player object and edits the player based on whether or not a random number points toward them getting a misfortune.
        Inputs: Player to get the misfortune
        Outputs: Prints out the results of the misfortune and takes the items out of the inventory.

*/

void Game::misfortune(Player &p){
    bool misfortune = false;

    int i = rand() % 10; //get a random number

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

            while(!foundPart){ //method found in Player.cpp fightHacker Methd; described there
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
            
        }else if(i == 1){ //damaged computer misfortune
            cout << "OH NO! Your computer was damaged!" << endl; 
            p.subMaintenance(10); //subtract 10 maintenance
            if(p.getMaintenance() <= 0){ //check if the player has lost the game
                if(p.getComputers() == 1){
                    cout << endl << "Your premade computer came to the rescue! Your maintenance is 100 again!" << endl << endl;
                    p.addMaintenance(100);
                    p.setComputers(0);
                }else{
                    cout << "You maintenance level is too low to continue! You lose!" << endl;
                    endGame(p); //end the game if maintenance == 0
                    return;
                }
            }
            
        }else if(i == 2){
            cout << "OH NO! Why won't my code work????" << endl; //frustration misfortune
            p.setFrustration(p.getFrustration() + 10); //add 10 to frustration

            if(p.getFrustration() >= 100){ //check if frustration loss
                cout << "OH NO! You have rage quit!" << endl;
                cout << "Looks like you couldn't handle Carmen's hackers." << endl;
                endGame(p); //end the game
                return;
            }
        }
    }
}

/* 
        means that the player has run into an npc object on the map, and is 
        able to get a puzzle or test their luck and see if the npc object is good, 
        neutral or bad, and then get the consequences
            Inputs: NPC object, Player object
            Outputs: void, but adds and subtracts parts
    */


void Game::speakToNpc(Npc n, Player &p){
    
   int choice;
   bool correctChoice = true; //bool to go through the loop

   cout << "You have found a mysterious person on your travels. " << endl << endl;
   cout << "They have a puzzle, and would like to see if you can solve it" << endl << endl;
   cout << "You can also take your chances to see if they're your friend or not" <<  endl << endl;
   cout << "Take puzzle: 1" << endl;
   cout << "Take your chances: 2" << endl;
   
    while(correctChoice){
        cin >> choice; //take in a choice
        switch(choice){
            case 1: { //if they choose to take in a puzzle
                string ans; 

                cout << getRandPuzzle() << endl;
                cin >> ans; //take in their answer to the puzzle

                if(ans == getAnswer()){
                    cout << "Nice job! You got the question right!" << endl; //if they get it right
                    int part = rand() % 6; //random number for which part the player is going to get
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
                    cout << "You've gotten the problem wrong! " << endl; //if they get it wrong they get nothing

                }
                correctChoice = false;

                break; //break the while loop
           }
            case 2:{
                cout << endl << "You've taken your chances!" << endl;
                if(n.getAdjective() == 0){
                    cout << endl << "Oh no! This NPC is an enemy!" << endl; //the NPC is an enemy 
                    bool foundPart = false;
                    int randpart = 0;
                    int count = 0;
                    int used[] = {0,0,0,0,0,0};

                    while(!foundPart){ //methodology implemented in the fightHacker function in the Player.cpp class
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
                }else if(n.getAdjective() == 1){ //NPC is neutral
                    cout <<  endl << "Phew. This NPC is neutral. Nothing happens! :)" << endl;
                }else if(n.getAdjective() == 2){ //NPC is a friend
                    cout << endl << "You got lucky! This NPC is a friend!" << endl;
                    int part = rand() % 6; //getting a part implemented in the speakToNpc class
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

/* 
        prompts the user to either pick a game or a puzzle to 
        reduce frustration, and then adjust the frustration of the player 
        accordingly.
        Inputs: Player object to be interacted with 
    */

void Game::browseStackOverFlow(Player &p){
    

    int option;
    bool choice = true;
    cout << "You've chosen to browse Stack Overflow!" << endl;
    cout << "You have two options: " << endl;
    cout << "\t1: Solve a puzzle" << endl;
    cout << "\t2: Play rock paper scissors" << endl;
    
    while(choice){
        cin >> option;
        switch(option){ //solving a puzzle implemented in the speaktoNpc function above 
            case 1:{
                string answer;
                cout << getRandPuzzle() << endl;
                cin >> answer;

                if(answer == getAnswer()){
                    cout << "Nice! You've gotten the answer right!" << endl;
                    if(p.getFrustration() < 5){
                        p.setFrustration(0);
                    }else{
                        p.setFrustration(p.getFrustration() - 5);
                    }
                    cout << "Your frustration has gone down to " << p.getFrustration() << endl;
                }else{
                    cout << "Dang. You got that wrong." << endl;
                }
                choice = false;
                break;
            }
            case 2:{ //this part of the function determines if you can play rock paper scissors with the computer
                int selection;
                cout << "You've chosen to play rock paper scissors!" << endl;
                cout << "Type your selection: 1: rock 2: paper 3: scissors" << endl;
                bool keepGoing = true;
                while(keepGoing){ //if they have an applicable answer, you break the loop
                    cin >> selection; 
                    int num = rand() % 3 + 1; //1 is rock 2 is paper and 3 is scissors
                    if(selection == 1){ //cases for whatever the person inputs
                        if(num == 1){
                            cout << "I also chose rock. Tie." << endl; //if they are the same
                        }else if(num == 3){
                            cout << "Oh you got me! I chose scissors." << endl; //if they are not the same
                            if(p.getFrustration() < 5){
                                p.setFrustration(0); //set frustration to 0 if their current frustration is below 5
                            }else{
                                p.setFrustration(p.getFrustration() - 5); //set frustration -5
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
                                p.setFrustration(0);
                            }else{
                                p.setFrustration(p.getFrustration() - 5);
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
                                p.setFrustration(0);
                            }else{
                                p.setFrustration(p.getFrustration() - 5);
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
                choice = true; //go through until you get correct user input
                break;
        }
    }

}

//setters

void Game::setTurn(){ //increment turn
    turn++;
}

void Game::setPlayerScore(Player &p){ //increase player score
    playerScore += 1;
}

/*  This function goes through a text document of puzzles, and separates them out into strings
    by determining where the --- string is on a line
        Inputs: string name of file
        outputs: stores the puzzles in a designated string array

*/
void Game::setPuzzles(string fileName){
    /*
        goes through a file of puzzles and sets the puzzles to
        each part of the array
    */
    ifstream stream; //open an ifstream
    stream.open(fileName);

    if(stream.fail()){ //check if fails
        cout << "Could not open the file" << endl;
        return;
    }
    string currQ = "", line;
    int count = 0;

    while(getline(stream, line)){
        if(line == "---"){ //if next puzzle
            puzzles[count] = currQ; //set the current question string to an array slot
            currQ = ""; //reset the question string
            count++; // increment the count to get to the new array slot next time
            continue; //skip adding the line to the currQ (would have an extra ---)
        }

        currQ += line;
        currQ += "\n"; //add the newline so that it's not just one long line
    }

    puzzles[count] = currQ; //add the last question to the array
    currQ = "";
    count++;



}

/*
        goes through a file of answers and sets the answers to
        each part of the array
            Input: string file name
            Output: Puts a text file of answers into a designated array in the game class
*/
void Game::setAnswers(string fileName){
    
    ifstream stream; //open a stream
    stream.open(fileName);

    if(stream.fail()){
        cout << "Could not open the file" << endl;
        return;
    }
    string currQ = "", line; //same implementation as the setPuzzles function
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

/*
    function useAntivirus
        This function inputs a player object and allows them to use the antivirus if they have a virus

*/

void Game::useAntivirus(Player &p){
    if(p.getVirus() == 0){ //if they don't have a virus
        cout << "You don't need to use antivirus" << endl;
        turn--; //doesn't count as a turn
        return;
    }

    if(p.getnumUSB() == 0){
        cout << "You don't have any USBs to remove the antivirus" << endl; //if the player doesn't have a USB stick
        return;
    }else{
        p.addNumUSBstick(-1); //if they have a USB stick
        p.addVirus(-1 * p.getVirus());
        cout << "You have removed all of the viruses on your computer!" << endl;
    }
}

/*
    Function: setHackers: This function goes through a file and pulls hacker objects from it

*/

void Game::setHackers(string fileName){
    ifstream stream;
    stream.open(fileName);

    string line;
    int count = 0;

    if(stream.fail()){
        cout << "Failed to open the hacker file" << endl;
    }

    while(getline(stream, line)){ //go through file
        string name = "", rn = "";
        for(int i = 0; i < line.length() - 2; i++){ //for the whole line add it to name except last 2 characters
            name += line[i];
        }
        rn = line.substr(line.length() - 1, 1); //set room number to the last digit of the line
        int roomNum = stoi(rn);
        Hacker temp(name, roomNum); //create a hacker object with the name and room num from the file

        hackArr[count] = temp; //put the hacker object in the next available space
        count++;

    }
}

/*
    Function: getHacker: This function takes in a room number and gets a random hacker as a return. Will not return a duplicate.
        Input: room number
        Output: outputs a hacker object with the provided room number stored.

*/

Hacker Game::getHacker(int rn){

    int start = (rn * 4) - 4; // the first possible position you can pull from in the hacker array (4 per room)
    bool foundHacker = false;
    while(!(foundHacker)){
        int randHacker = rand() % 4; //get a random number 
        foundHacker = true;
        for(int i = 0; i < 20; i++){
            if(hackArr[start + randHacker].getName() == hackUsed[i]){
                foundHacker = false; //if there is the same name in hackArr then you can't use it again
            }
        }

        if(foundHacker == true){ //if there is no duplicate name, then you can use the hacker object.
            hackUsed[count] = hackArr[start + randHacker].getName();
            count++;
            return hackArr[start + randHacker];
        }
        
    }

    return hackArr[start]; //return the Hacker

}

/*
    Function newRoom: This function moves the player onto the next room if they either select it or have done 10 turns in the previous room.
        Inputs: Map m, Player p, and an npc and the store object
        Outputs: resets the map, increments some values

*/

void Game::newRoom(Map &m, Player &p, Npc n, Store &s){
    room++; //increase the room

    if(room == 6){ //if they have finished room 5
        cout << "Nice job! You finished the game!" << endl;
        endGame(p);
        return;
    }

    cout << endl << endl <<"Welcome to room " << room << "!" << endl;
    cout << "Best of luck! You're going to need it..." << endl << endl;

    for(int i = 0; i < 6; i++){ //reset the visited NPCs array
        visitedNPCs[i][0] = -1;
        visitedNPCs[i][0] = -1;
    }
    countVisited = 0; //reset the count

    srand(time(NULL)); //get a random time

    m.resetMap(); //reset map function found in map class

    int numberHackers = rand() % 3 + 1; //1,2,3 finding how many NPCs and hackers to make
    int numberNPC = rand() % 3 + 1;
    

    int bestBuyCol = rand() % 9;
    int bestBuyRow = rand() % 5;

    bool a = m.spawnBestBuy(bestBuyRow, bestBuyCol); //spawning best buy first

    if(a == false){
        m.spawnBestBuy(bestBuyRow, bestBuyCol); //if it didn't work
    }

    for(int i = 0; i < numberNPC; i++){ //go through spawning each NPC
        int row = rand() % 9; //get ran row and column
        int col = rand() % 5;

        bool a = m.spawnNPC(row, col); //spawn the npc

        if(a == false){
            numberNPC++; //if it doesn't spawn add to the loop
        }
    }

    for(int i = 0; i < numberHackers; i++){ //same as above
        int row = rand() % 9; 
        int col = rand() % 5;

        bool a = m.spawnHacker(row, col);

        if(row == bestBuyRow && col == bestBuyCol){
            numberHackers++;
        }

        if(a == false){
            numberHackers++;
        }

    }
    s.setPrices(room); //change the prices, function found in the store class

    turn = 1;

    m.displayMap(); //show the new room map

    p.resetHackersDefeated();
    //score goes to zero when defeating the hacker is the last turn;
    
    openMenu(m, p, n, s);
    
}

/* This function increments the turn that a player is on in the room.
    Inputs: Map, Player, Npc and store objects
    Outputs: void


*/

void Game::nextTurn(Map &m, Player &p, Npc n, Store s){
    turn++; //add to the turn variable
    p.setDogecoins(p.getDogecoin() + 5); //add 5 doge
    int num = 5;
    for(int i = 0; i < p.getNumGpu(); i++){ //for every gpu add 5
        p.setDogecoins(p.getDogecoin() + 5);
        num += 5;
    }

    if(turn == 11){ //if it is past the last possible turn
        if(p.getHackersDefeated() == 0){ //if they haven't beaten any hackers in the room 
            cout << "You haven't defeated any hackers!!" << endl;
            cout << "You lose!" << endl;
            endGame(p); //end the game
            return;
        }else{
            newRoom(m, p, n, s); //spawn the new room
        }

    }

    if(progressLevel >= 100){ //if carmen has won
        cout << "You have lost because Carmen's progress is 100!" << endl;
        endGame(p);
        return;
    }

    openMenu(m, p, n, s); //open the menu as a default to starting the next turn
}

/* Function: travelRoom
        This function gives the player capabilities based on where they have travelled in the server room,
        mainly if they have landed on an npc or a hacker, or best buy
            Inputs: all available objects
            Outputs: void
*/

void Game::travelRoom(Map &m, Player &p, Npc n, Store s){
    char move;
    bool moving = true;
    int frustration = p.getFrustration();

    //Have to put in the nextTurn class as this acts as a turn, but don't want to open menu
    turn++;
    p.setDogecoins(p.getDogecoin() + 5);
    int num = 5;
    for(int i = 0; i < p.getNumGpu(); i++){
        p.setDogecoins(p.getDogecoin() + 5);
        num += 5;
    }

    if(turn == 11){ 
        if(p.getHackersDefeated() == 0){
            cout << "You haven't defeated any hackers!!" << endl;
            cout << "You lose!" << endl;
            endGame(p);
            return;
        }else{
            newRoom(m, p, n, s);
        }

    }

    if(progressLevel >= 100){
        cout << "You have lost because Carmen's progress is 100!" << endl;
        endGame(p);
        return;
    }

    //end of nextTurn 

    while(moving){ //every move 
        m.displayMap(); //show map
        cout << "Valid moves are:" << endl;
        m.displayMoves(); //show moves 
        cout << "Input a move:" << endl;
        cin >> move; //take in a move
        m.executeMove(move); //determines if able to or not
        frustration = p.getFrustration() + 2; //add frustration
        p.setFrustration(frustration);
        if(p.getFrustration() >= 100){
            cout << "Your frustration is 100! You have lost the game!" << endl;
            endGame(p);
            return;
        }
        misfortune(p); //check to see if misfortune
        if(m.isHackerLocation()){ //check to see if it is a hacker location
            // fight a hacker
            cout << "You have run into a hacker!!!" << endl;
            bool alreadyUsed = false;
            for(int i = 0; i < 6; i++){
                if(visitedNPCs[i][0] == m.getPlayerRowPosition() && visitedNPCs[i][1] == m.getPlayerColPosition()){ //check to see if already visited
                    alreadyUsed = true;
                }
            }

            if(alreadyUsed){
                cout << "You have already found and defeated this hacker. Keep moving" << endl;
                turn--;
                travelRoom(m, p, n, s);
                break;
            }

            cout << "Do you choose to: " << endl; //options
            cout << "1. Fight the Hacker" << endl;
            cout << "2. Forfeit the battle" << endl;
            int input;
            cin >> input;

            if(input == 1){ //fight a hacker
                Hacker temp = getHacker(room); 

                bool result = p.fightHacker(temp); //get if the hacker was beaten
                if(result){ //if beaten
                    p.addHackersDefeated(1); //increment hackers defeated and score
                    p.setTotalHackersDefeated(1);
                    //total hackers
                    visitedNPCs[count][0] = m.getPlayerRowPosition(); //add to the array of locations visited 
                    visitedNPCs[count][1] = m.getPlayerColPosition();
                    count++;
                }
                // int num = rand() % 10; //
                // if(num <= 2){
                //     p.subMaintenance(10);
                // }

                if(p.getMaintenance() <=0){ //check if maintenance is too low
                    if(p.getComputers() == 1){
                        cout << endl << "Your premade computer came to the rescue! Your maintenance is 100 again!" << endl << endl;
                        p.addMaintenance(100);
                        p.setComputers(0);
                    }else{
                        cout << "Because of your maintenance level dropping, you have lost the game! Better luck next time!" << endl;
                        endGame(p);
                        return;
                    }
                }
                if(result == false){ //if you lose
                    progressLevel += 25; //carmen increase progress
                if(progressLevel >= 100){
                    cout << "Carmen has reached her maximum progress! You have lost the game!" << endl; //lose bc carmen progress too high
                    endGame(p);
                    return;
                }
            }
            nextTurn(m, p, n, s); //go to the next turn
            
            }else if(input == 2){ //forfeit function
                Hacker temp = getHacker(room);
                p.forfeit(temp);
                nextTurn(m, p, n, s);
            }
            
            
        }
        if(m.isNPCLocation()){ //check if it is an npc location
            bool alreadyUsed = false;
            for(int i = 0; i < 6; i++){
                if(visitedNPCs[i][0] == m.getPlayerRowPosition() && visitedNPCs[i][1] == m.getPlayerColPosition()){ //check if visited
                    alreadyUsed = true;
                }
            }

            if(alreadyUsed){ //if you have visited
                cout << "You have already found and defeated this NPC. Keep moving" << endl;
                turn--;
                travelRoom(m,p,n,s);
                return;
            }

            speakToNpc(n, p); //peaktoNpc function
            visitedNPCs[count][0] = m.getPlayerRowPosition(); //add to visited visitedNPCs
            visitedNPCs[count][1] = m.getPlayerColPosition();
            count++;



            nextTurn(m, p, n, s);
            return;
        }
        if(m.isBestBuyLocation()){ //check if it is bestBuy
            s.displayMenu(p, room);
            nextTurn(m,p,n,s);
            return;
        }

    }

}
/*
    Function endGame: This function ends the game, takes the results from a text file, and sorts them.
        Inputs: player object
        Ouputs: Writes onto results.txt.

*/

void Game::endGame(Player& p){
    //produces text that congratulates the player, shows them their stats, and 
    //finishes the game.
    ifstream stream("results.txt"); //create the input stream
    cout << "You've finished the game!" << endl;
    cout << "Player Name: " << p.getName() << endl;
    cout << "Total Hackers Defeated: " << p.getTotalHackersDefeated() << endl;
    cout << "Total remaining Dogecoin: " << p.getDogecoin() << endl;

    string arr[100];
    string line;
    int scores[100];

    // cout << p.getName();

    // stream << p.getName() << ", " << p.getTotalHackersDefeated() << endl;

    int resultCount = 0;

    // getline(stream, line); //getting past first line

    while(getline(stream, line)){ //reading the file
        string name;
        string score;

        bool names = true;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ','){
                names = false; //stop taking in name
            }

            if(isdigit(line[i]) && names == false && line.length() - 2){
                score = line.substr(i, 2);
                break; //if it is two digit number
            }

            if(isdigit(line[i]) && i == line.length() -1 && names == false){
                score = line.substr(i,1);
            } //if it is one digit number
            

            if(names){
                name += line[i]; //add char to name
            }
            
        }

        arr[resultCount] = name; //put the name into an array
        scores[resultCount] = stoi(score); //put the score into the same index of another array

        resultCount++; //increment count
    }



    arr[resultCount] = p.getName(); //put the player into both arrays
    scores[resultCount] = p.getTotalHackersDefeated();

    resultCount++;


    ofstream outStream("results.txt"); //create an output stream to put scores onto the file
    

    //bubblesort sorting algorithm put in here
    for(int i = 0; i < resultCount; i++) {  //for every item in the array (counted by resultCount)
        for(int j = i + 1; j < resultCount; j++) //go through every item in fron and get the smallest 
        {
            if(scores[j] < scores[i]) { //if the one ahead is smaller, switch the two
                int temp = scores[i];
                string temps = arr[i]; //also switch the names
                scores[i] = scores[j];
                arr[i] = arr[j];
                scores[j] = temp;
                arr[j] = temps;
            }
        }
    }

    for(int i = 0; i < resultCount; i++){ //write all to file 
        outStream << arr[i] << ", " << scores[i] << endl;
    }

    exit(1); //terminate the game

    
    

}

/*  
    Function: openMenu
        This function is the stepping stone for the entire game, giving the player every option they have available to them.
            Inputs: All possible objects used in the game
            Outputs: calls functions that allow the game to proceed

*/

void Game::openMenu(Map &m, Player &p, Npc &n, Store s){
    //displays the menu given to the player at the beginning of every turn.
    //switch statement inside of driver catches player response and what to do
    
    int option = 0;
 //display the menu
    cout << "-----Menu-----" << endl;
    cout << "1 - Status Update" << endl;
    cout << "2 - Travel the Server Room" << endl;
    cout << "3 - Repair your Computer" << endl;
    cout << "4 - Use your Antivirus Software" << endl;
    cout << "5 - Browse Stack Overflow" << endl;
    cout << "6 - Quit" << endl;
    if(p.getHackersDefeated() >= 1){ //if they've defeated a hacker
        cout << "7 - Next Room" << endl;
    }


    cin >> option; //take in option


    switch(option){
        case 1:{ //status update
            displayStats(p); //do the function and then open the menu
            openMenu(m, p, n, s);
            break;
        }
        case 2:{ //travel server room
            cout << endl; //go to the travel Room function
            travelRoom(m, p, n, s);
            return; //travelRoom calls openMenu
            break;
        }
        case 3:{ //repair computer
            if(p.getTotalParts() <= 0){
                cout << "You do not have any computer parts to repair your computer." << endl;
            }
            else{
                repairComputer(p);
                
            }
            nextTurn(m, p, n, s);
            return;
            break;
        }
        case 4:{ //use antivirus software
            useAntivirus(p);
            nextTurn(m, p, n, s);
            return;
            break;
        }
        case 5:{ //browse stack overflow
            browseStackOverFlow(p);
            nextTurn(m, p, n, s);
            return;
            break;
        }
        case 6:{ //quit game
            cout << "You have quit the game!" << endl;
            endGame(p);
            return;
            break;
            
        }
        case 7:{  //
            if(p.getHackersDefeated() == 0){ //if they can't leave 
                cout << "Invalid input. Select an option from 1 to 6" << endl;
                openMenu(m, p, n, s);
                return;
            }else if(p.getHackersDefeated() >= 1){ //if they can leave.
                cout << "You have chosen to move on. Good luck, " << p.getName() << endl;
                newRoom(m, p, n, s);
                return;
            }
        }
        default:{ //if they choose an incorrect int
            cout << "Invalid input. Select an option from 1 to 6." << endl;
            openMenu(m, p, n, s);
            return;
            break;
        }
    }
}

