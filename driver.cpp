// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Game.h"
#include "Hacker.h"
#include "Map.h"
#include "Npc.h"
#include "Player.h"
#include "Store.h"
#include <iostream>
using namespace std;

int main(){
    // testing Store default constructor
    // Store store1;
    // cout << "testing Store default constructor" << endl;
    // cout << store1.getcpuPrice() << endl;
    // cout << store1.getgpuPrice() << endl;
    // cout << store1.getPowerSupplyPrice() << endl;
    // cout << store1.getComputerCasePrice() << endl;
    // cout << store1.getInternetCardPrice() << endl;
    // cout << store1.getKeyboardAndMousePrice() << endl;
    // cout << store1.getPremadePrice() << endl;
    // cout << store1.getMaxParts() << endl;
    // cout << store1.getAntivirusPrice() << endl;
    // cout << store1.getvpnPrice() << endl;
    // cout << store1.getInternetPrice() << endl; //fix 
    // //testing Store parameterized constructor
    // Store store2(4);
    // store2.setBaseInternetPrice(4); //fix
    // store2.setPrices(4);
    // cout << "testing Store parameterized constructor" << endl;
    // cout << store2.getcpuPrice() << endl;
    // cout << store2.getgpuPrice() << endl;
    // cout << store2.getPowerSupplyPrice() << endl;
    // cout << store2.getComputerCasePrice() << endl;
    // cout << store2.getInternetCardPrice() << endl;
    // cout << store2.getKeyboardAndMousePrice() << endl;
    // cout << store2.getPremadePrice() << endl;
    // cout << store2.getMaxParts() << endl;
    // cout << store2.getAntivirusPrice() << endl;
    // cout << store2.getvpnPrice() << endl;
    // cout << store2.getInternetPrice() << endl; // fix
    //testing displayMenu function
    // cout << "testing displayMenu function" << endl;
    // Store store3(1);
    // Player will("Will");
    // store3.displayMenu(will, 1);


    
    //testing Player default constructor
//     Player player1;
//     cout << "testing Player default constructor" << endl;
//     cout << player1.getDogecoin() << endl;
//     cout << player1.getName() << endl;
//     cout << player1.getIPlvl() << endl;
//     cout << player1.getFrustration() << endl;
//     cout << player1.getProgress() << endl;
//     cout << player1.getHackersDefeated() << endl;
//     cout << player1.getComputers() << endl;
//     cout << player1.getVPN() << endl;
//     cout << player1.getNumGpu() << endl;
//     cout << player1.getnumcpu() << endl;
//     cout << player1.getnumPowerSupply() << endl;
//     cout << player1.getnumCases() << endl;
//     cout << player1.getnumInternetCard() << endl;
//     cout << player1.getnumKeyboardAndMouse() << endl;

//     //testing Player parameterized constructor 
//     Player player2("Will");
//     cout << "testing Player parameterized constructor and setters" << endl;
//     cout << player2.getName() << endl;

//     //testing Player setter functions
//     player2.setFrustration(5);
//     player2.setDogecoins(143);
//     player2.setIPlvl(4);
//     player2.setProgress(73);
//     player2.addHackersDefeated(2);
//     player2.setComputers(6);
//     player2.addVPN(1); //fix
//     player2.addNumgpu(7); //fix
//     player2.addNumcpu(9); //fix
//     player2.addNumPowerSupply(8); //fix
//     player2.addNumCases(2); //fix
//     player2.addNumInternetCard(11);
//     player2.addNumKeyboardAndMouse(6);
//     cout << player2.getDogecoin() << endl;
//     cout << player2.getIPlvl() << endl;
//     cout << player2.getFrustration() << endl;
//     cout << player2.getProgress() << endl;
//     cout << player2.getHackersDefeated() << endl;
//     cout << player2.getComputers() << endl;
//     cout << player2.getVPN() << endl;
//     cout << player2.getNumGpu() << endl;
//     cout << player2.getnumcpu() << endl;
//     cout << player2.getnumPowerSupply() << endl;
//     cout << player2.getnumCases() << endl;
//     cout << player2.getnumInternetCard() << endl;
//     cout << player2.getnumKeyboardAndMouse() << endl;



//     //testing Npc default constructor
//     cout << "testing Npc default constructor" << endl;
//     Npc npc1;
//     cout << npc1.getName() << endl;
//     cout << npc1.getAdjective() << endl;
//     cout << npc1.getRoomNum() << endl;
//     //testing Npc parameterized constructor
//     cout << "testing Npc parameterized constructor" << endl;
//     Npc npc2("Sam", 4);
//     cout << npc2.getName() << endl;
//     cout << npc2.getAdjective() << endl;
//     cout << npc2.getRoomNum() << endl;
//     //testing Npc setters
//     cout << "testing Npc setters" << endl;
//     Npc npc3;
//     npc3.setName("Prat");
//     npc3.setRoomNum(2);
//     npc3.setRandAdjective();
//     cout << npc3.getName() << endl;
//     cout << npc3.getAdjective() << endl;
//     cout << npc3.getRoomNum() << endl;


//     //testing Hakcer default constructor
//     Hacker hacker1;
//     cout << "testing Hakcer default constructor" << endl;
//     cout << hacker1.getName() << endl;
//     cout << hacker1.getRoomNum() << endl;
//     //testing Hacker parameterized constructor
//     Hacker hacker2("Jordan", 3);
//     cout << "testing Hacker parameterized constructor" << endl;
//     cout << hacker2.getName() << endl;
//     cout << hacker2.getRoomNum() << endl;
//     //testing Hacker setters
//     cout << "testing Hacker setters" << endl;
//     Hacker hacker3;
//     hacker3.setName("Julia");
//     hacker3.setRoomNum(1);
//     cout << hacker3.getName() << endl;
//     cout << hacker3.getRoomNum() << endl;


//     //testing Game default constructor
//     cout << "testing Game default constructor" << endl;
//     Game game1;
//     cout << game1.getTurn() << endl;
//     cout << game1.getVirus() << endl;
//     cout << game1.getProgress() << endl;
//     cout << game1.getMaintenence() << endl;
//     cout << game1.getRandPuzzle() << endl;
//     cout << game1.getAnswer() << endl;
//     cout << game1.getMoves() << endl;
//     //testing Game setters
//     cout << "testing Game setters" << endl;
//     Game game2;
//     game2.setTurn();
//     game2.setPuzzles("file1");
//     game2.setAnswers("file2");
//     game2.setProgress(14);
//     game2.addVirus();
//     game2.addMaintenence(21);
//     game2.subMaintenence(36);
//     game2.addMove();
//     cout << game2.getTurn() << endl;
//     cout << game2.getVirus() << endl;
//     cout << game2.getProgress() << endl;
//     cout << game2.getMaintenence() << endl;
//     cout << game2.getRandPuzzle() << endl;
//     cout << game2.getAnswer() << endl;
//     cout << game2.getMoves() << endl;
//     //testing Game miscellaneous functions
//     cout << "testing Game miscellaneous functions" << endl;
//     Game game3;
//     Player gamePlayer;
    // Npc gameNpc;
    // game3.openMenu();
    // game3.startGame();
    // game3.endGame();
    // game3.displayStats(gamePlayer);
    // game3.misfortune(gamePlayer);
    // game3.speakToNpc(gameNpc);
    // game3.browseStackOverFlow(gamePlayer);

    srand(time(0));

    // Game game;
    // Player p("Will");
    // Map m;
    // Store s;

    // game.misfortune(p);

    // Npc tony("Tony", 1);

    // p.addVPN(-1);

    // game.browseStackOverFlow(p);

    // p.addNumUSBstick(1);

    // game.useAntivirus(p);

    // cout << game.getVirus() << endl;

    //game.setPuzzles("puzzles.txt");

    // cout << game.getRandPuzzle();

    // game.setAnswers("answers.txt");

    // game.speakToNpc(tony, p);

    // cout << game.getAnswer();

    // cout << rand() % 6 + 1 << endl;

    // Hacker tommy;

    // p.fightHacker(tommy);

    // cout << p.getDogecoin() << endl;

    // game.repairComputer(p);

    // game.setHackers("hackers.txt");
    // game.newRoom(m, p, tony, s);
    // m.displayMap();
    // cout << "number of hackers: " << m.getHackerCount() << endl;
    // cout << "number of npcs: " << m.getNPCCount() << endl;
    // game.openMenu(m, p, tony, s);


    // Hacker b = game.getHacker(2);

    // cout << b.getName() << endl;

    // p.subMaintenance(100);

    // game.openMenu(m, p, tony, s);

    Hacker h;
    Map m;
    Player p;
    Store s;
    Npc n;
    Game g;

    g.setHackers("hackers.txt");
    g.setPuzzles("puzzles.txt");
    g.setAnswers("answers.txt");

    g.newRoom(m, p, n, s);

    m.resetMap();

    g.newRoom(m, p, n, s);

    m.resetMap();

    g.newRoom(m, p, n, s);

    m.resetMap();

    g.newRoom(m, p, n, s);

    m.resetMap();

    g.newRoom(m, p, n, s);

    m.resetMap();


    
}