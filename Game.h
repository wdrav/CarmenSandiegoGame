// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Npc.h"
#include "Hacker.h"
#include "Map.h"
#include "Store.h"
#include <string>

using namespace std;

class Game {
    private:
        int turn;
        int progressLevel;
        string puzzles[10];
        string answers[10];
        int puzzleNum;
        int numMoves;
        Hacker hackArr[20];
        string hackUsed[20];
        int count;
        int room;

    public:
        //constructor:
        Game();

        //miscellaneous functions
        void openMenu(Map m, Player p, Npc n, Store s);
        // void startGame();
        void endGame(Player p);
        void displayStats(Player p);
        void misfortune(Player p);
        void speakToNpc(Npc n, Player p);
        void browseStackOverFlow(Player p);
        void useAntivirus(Player p);
        void repairComputer(Player p);
        void nextTurn(Map m, Player p, Npc n, Store s);
        void travelRoom(Map m, Player p, Npc n, Store s);
        void newRoom(Map m, Player p);


        //setters
        void setTurn();
        void setPuzzles(string fileName);
        void setAnswers(string fileName);
        void setHackers(string fileName);
        void setProgress(int p);
        void addMove();

        //getters
        int getTurn();
        int getProgress();
        string getRandPuzzle(); //sets puzzleNum to a random index of the array + returns the puzzle
        string getAnswer(); //will use puzzleNum to return the answer
        int getMoves();
        Hacker getHacker(int roomNum);

};

#endif