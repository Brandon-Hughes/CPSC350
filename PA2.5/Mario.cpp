/// @brief Creates a mario character that can interact with the world
/// @file Mario.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mario.h"
using namespace std;

//Default Constructor
Mario::Mario(){
    numCoins = 0;
    numPL = 0;
    numLives = 5;
    posRow = 0;
    posCol = 0;
    posLevel = 0;
    battleCount = 0;
}

//Overloaded constructor
Mario::Mario(int coins, int power, int lives, int curRow, int curCol, int curLevel){
    numCoins = coins;
    numPL = power;
    numLives = lives;
    posRow = curRow;
    posCol = curCol;
    posLevel = curLevel;
    battleCount = 0;
}

//Destructor
Mario::~Mario(){

}

//Returns the current row mario is on
int Mario::getRow(){
    return posRow;
}

//Returns the current coloumn mario is on
int Mario::getCol(){
    return posCol;
}

//Returns the current level mario is on
int Mario::getLevel(){
    return posLevel;
}

//Returns the amount of coins mario has
int Mario::getCoins(){
    return numCoins;
}

//Returns the amount of lives mario has
int Mario::getLives(){
    return numLives;
}

//Changes mario's row into a new row
void Mario::setRow(int newRow){
    posRow = newRow;
}

//Changes mario's column into a new column
void Mario::setCol(int newCol){
    posCol = newCol;
}

//Increases mario level by 1
void Mario::levelIncrease(){
    posLevel++;
}

//Decreases mario's level by 1
void Mario::levelDecrease(){
    posLevel--;
}

//Decrease's mario's lives by 1
void Mario::livesDecrease(){
    numLives--;
}

//Increases mario's power level by 1 if it's less than 2
void Mario::powerLevelIncrease(){
    if (numPL < 2){
        numPL++;
    }
    else{
        numPL = 2;
    }
}

//Decreases mario's power level by 1
void Mario::powerLevelDecrease(){
    numPL--;
}

//Decreases mario's power level by 2
void Mario::powerLevelDecrease2(){
    numPL--;
    numPL--;
}

//increases mario's coins by 1
void Mario::coinIncrease(){
    numCoins++;
}

//Increases lives by 1 if wins 7 battles in a row
void Mario::battleCountIncrease(){
    battleCount++;
    if(battleCount == 7){
        numLives++;
        battleCount -= 7;
    }
}

//Sets battlecount to 0 for losing fights
void Mario::battleCountReset(){
    battleCount = 0;
}

//Increases nummber of lives by 1 if he has 20 coins
void Mario::coinTrader(){
    if(numCoins >= 20){
        numCoins -= 20;
        numLives++;
    }
}

//Moves mario to a new spot on the map
void Mario::move(int mapRows, int mapCols){
    int rand1 = rand() % 4;
    if(rand1 == 0){
        if(posRow != 0){
            posRow--;
        }
        else{
            posRow = (mapRows-1);
        }
    }
    else if(rand1 == 1){
        if(posRow != (mapRows-1)){
            posRow++;
        }
        else{
            posRow = 0;
        }
    }
    else if(rand1 == 2){
        if(posCol != 0){
            posCol--;
        }
        else{
            posCol = (mapCols-1);
        }
    }
    else if(rand1 == 3){
        if(posCol != (mapCols-1)){
            posCol++;
        }
        else{
            posCol = 0;
        }
    }
}

//Fights a Goomba with a 80% chance of winning
bool Mario::regGAttack(){
    int rand1 = rand() % 5;
    if(rand1 != 0){
        return true;
    }
    else{
        return false;
    }
}

//Fights a Koopa with a 65% chance of winning
bool Mario::regKAttack(){
    int rand1 = rand() % 20;
    if(rand1 >= 7){
        return true;
    }
    else{
        return false;
    }
}

//Fights a boss with a 50% chance of winning
bool Mario::bossAttack(){
    int rand1 = rand() % 2;
    if(rand1 == 1){
        return true;
    }
    else{
        return false;
    }
}

//Win condition is if current level is higher than levels possible
bool Mario::winGame(int numLevels){
    if(posLevel >= numLevels){
        return true;
    }
    else {
        return false;
    }
}

//Returns mario's current power level
int Mario::getPL(){
    return numPL;
}