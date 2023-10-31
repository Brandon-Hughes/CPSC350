/*
    int numCoins;
    int numPL;
    int numLives; // V
    int posRow;
    int posCol;
    int posLevel;
*/
#include "Mario.h"
#include <iostream>

Mario::Mario(){
    numCoins = 0;
    numPL = 0;
    numLives = 5;
    posRow = 0;
    posCol = 0;
    posLevel = 0;
}
Mario::Mario(int coins, int power, int lives, int curRow, int curCol, int curLevel){
    numCoins = coins;
    numPL = power;
    numLives = lives;
    posRow = curRow;
    posCol = curCol;
    posLevel = curLevel;
}
Mario::~Mario(){

}
int Mario::getRow(){
    return posRow;
}
int Mario::getCol(){
    return posCol;
}
int Mario::getLevel(){
    return posLevel;
}
int Mario::getCoins(){
    return numCoins;
}
int Mario::getLives(){
    return numLives;
}
void Mario::setRow(int newRow){
    posRow = newRow;
}
void Mario::setCol(int newCol){
    posCol = newCol;
}
void Mario::levelIncrease(){
    posLevel++;
}

void Mario::coinIncrease(){
    numCoins++;
}

void Mario::coinTrader(){
    if(numCoins >= 20){
        numCoins -= 20;
        numLives++;
        cout << "You have gained a life for 20 coins" << endl;
    }
    else{
        cout << "You don't have enough coins for a life" << endl;
    }
}

void Mario::moveLeft(){
    posRow--;
}
void Mario::moveRight(){
    posRow++;
}
void Mario::moveUp(){
    posCol++;
}
void Mario::moveDown(){
    posCol--;
}