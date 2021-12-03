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
        string puzzles[10]; //array of strings holding the puzzles
        string answers[10]; //array of string holding the answers to the puzzles
        int puzzleNum; //stores the current puzzle index
        int numMoves;
        Hacker hackArr[20]; //stores all the hacker objects based of file given
        string hackUsed[20]; //stores the names of the hackers that have been seen
        int count;
        int room;
        int visitedNPCs[6][2]; //used for when travelling a room; if they have found the NPC, they can't interact.
        int countVisited; //the count of visited hackers and NPCs in the rooms.
        int playerScore;

    public:
        //constructor:
        Game();

        //miscellaneous functions - described in the .cpp file
        void openMenu(Map &m, Player &p, Npc &n, Store s);
        void endGame(Player &p);
        void displayStats(Player &p);
        void misfortune(Player &p);
        void speakToNpc(Npc n, Player &p);
        void browseStackOverFlow(Player &p);
        void useAntivirus(Player &p);
        void repairComputer(Player &p);
        void nextTurn(Map &m, Player &p, Npc n, Store s);
        void travelRoom(Map &m, Player &p, Npc n, Store s);
        void newRoom(Map &m, Player &p, Npc n, Store &s);


        //setters
        void setTurn();
        void setPuzzles(string fileName);
        void setAnswers(string fileName);
        void setHackers(string fileName);
        void setProgress(int p);
        void addMove();
        void setPlayerScore(Player &p);

        //getters
        int getTurn();
        int getProgress();
        string getRandPuzzle(); //sets puzzleNum to a random index of the array + returns the puzzle
        string getAnswer(); //will use puzzleNum to return the answer
        int getMoves();
        Hacker getHacker(int roomNum);
        int getRoom(); //new
        int getPlayerScore(Player p);

};

#endif