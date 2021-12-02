// CSCI 1300 Fall 2021
// Authors: William Dravenstott and Thomas Garcia
// Project 3

#include "Map.h"

using namespace std; 

Map::Map()
{
    resetMap();
}

// resets player position, count values, and initializes values in position arrays to -1
void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    bestBuyPosition[0] = -1;
    bestBuyPosition[1] = -1;

    npc_count = 0;
    hacker_count = 0;
    best_buy_on_map = false;

    for (int i = 0; i < num_npcs; i++) {
        npcPositions[i][0] = -1;
        npcPositions[i][1] = -1;
    }

    for (int i = 0; i < num_hackers; i++) {
        hackerPositions[i][0] = -1;
        hackerPositions[i][1] = -1;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getNPCCount() {
    return npc_count;
}

int Map::getHackerCount() {
    return hacker_count;
}

// set player's row position to parameter row
void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}

// set player's column position to parameter row
void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

void Map::setNPCCount(int count) {
    npc_count = count;
}

void Map::setHackerCount(int count) {
    hacker_count = count;
}

/* add Hacker to map
 * Parameters: where to spawn Hacker -- row (int), col (int)
 * Return: (bool) false if no more space in hackerPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnHacker(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (hacker_count >= num_hackers) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (hackerPositions[hacker_count][0] == -1 && hackerPositions[hacker_count][1] == -1) {
        hackerPositions[hacker_count][0] = row;
        hackerPositions[hacker_count][1] = col;
        mapData[row][col] = '-';
        hacker_count++;
        return true;
    }

    return false;
}

/* add NPC to map
 * Parameters: where to spawn NPC -- row (int), col (int)
 * Return: (bool) false if no more space in npcPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnNPC(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (npc_count >= num_npcs) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (npcPositions[npc_count][0] == -1 && npcPositions[npc_count][1] == -1) {
        npcPositions[npc_count][0] = row;
        npcPositions[npc_count][1] = col;
        mapData[row][col] = 'N';
        npc_count++;
        return true;
    }

    return false;
}

/* add Best Buy to map
 * Parameters: where to spawn Best Buy -- row (int), col (int)
 * Return: (bool) false if (row, col) is an invalid location
 *                      or if (row, col) is already populated
 *                      or if there is a best buy already on the map; else true
 */
bool Map::spawnBestBuy(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (best_buy_on_map) {
        return false;
    }

    if (bestBuyPosition[0] == -1 && bestBuyPosition[1] == -1) {
        bestBuyPosition[0] = row;
        bestBuyPosition[1] = col;
        mapData[row][col] = 'B';
        best_buy_on_map = true;
        return true;
    }

    return false;
}

// return true if x, y position has a best buy there
bool Map::isBestBuyLocation(){
    return bestBuyPosition[0] == playerPosition[0] && bestBuyPosition[1] == playerPosition[1];
}

// return true if x, y position has an npc there
bool Map::isNPCLocation(){
    for(int i = 0; i < num_npcs; i++){
        if(npcPositions[i][0] == playerPosition[0] && npcPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

// return true if x, y position has a hacker there
bool Map::isHackerLocation() {
    for(int i = 0; i < num_hackers; i++){
        if(hackerPositions[i][0] == playerPosition[0] && hackerPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

/*
 * This function prints a menu of valid moves based on playerPosition
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMoves(){
    if(!(playerPosition[0] == 0)){
        cout << "w (Up)" << endl;
    }
    if(!(playerPosition[0] == (num_rows - 1))){
        cout << "s (Down)" << endl; 
    }
    if(!(playerPosition[1] == 0)){
        cout << "a (Left)" << endl; 
    }
    if(!(playerPosition[1] == (num_cols - 1))){
        cout << "d (Right)" << endl; 
    }
}

/*
 * This function takes in user input
 * and updates playerPosition on the map.
 * Parameters: move (char) -- 'w' (up), 'a' (left), 's' (down), 'd' (right)
 * Return: (bool) if move is valid, then true, else false
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * This function prints a 2D map in the terminal.
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'H') {  // don't show hacker on the map
                 cout << "H";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

// returns true if there is already a Best Buy on the map
bool Map::isBestBuyOnMap() {
    return best_buy_on_map;
}
