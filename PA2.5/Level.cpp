/// @brief Builds the map of the game and populates it with chars to simulate a world
/// @file Level.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include <iostream>
#include "Level.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

//Constructor that creates a 3D grid of arrays to simulate a map
Level::Level(int numLevels, int gridDimension, int percentCoins, int percentNothing,int percentGoombas, int percentKoopas, int percentMushrooms) {
    m_numLevels = numLevels;
    m_gridDimension = gridDimension;
    m_percentCoins = percentCoins;
    m_percentNothing = percentNothing;
    m_percentGoombas = percentGoombas;
    m_percentKoopas = percentKoopas;
    m_percentMushrooms = percentMushrooms;
    curLevel = new char**[m_numLevels];
    for (int i = 0; i < numLevels; ++i) {
        curLevel[i] = new char*[m_gridDimension];
        for (int j = 0; j < m_gridDimension; ++j) {
            curLevel[i][j] = new char[m_gridDimension];
        }
    }
    populateLevel(curLevel, m_percentCoins, m_percentNothing, m_percentGoombas, m_percentKoopas, m_percentMushrooms);
}

//Destructor: deletes the array
Level::~Level(){
    for(int i = 0; i < m_numLevels; ++i){
        for(int j = 0; j < m_gridDimension; ++j){
            delete[] curLevel[i][j];
        }
        delete[] curLevel[i];
    }
    delete[] curLevel;
}

//populates the array with characters to represent objects
void Level::populateLevel(char*** curLevel, int percentCoins, int percentNothing,int percentGoombas, int percentKoopas, int percentMushrooms) {
    int m_warpPipes = m_numLevels - 1;

    //filling array with ~'s as temp values to ensure authenticity of randomeness
    for(int levels = 0; levels < m_numLevels; ++levels){
        for (int rows = 0; rows < m_gridDimension; ++rows) {
            for (int cols = 0; cols < m_gridDimension; ++ cols) {
                curLevel[levels][rows][cols] = '~';
            }
        }
    }

    
    for(int levels = 0; levels < m_numLevels; ++levels){
        // these equations convert the percentage to a decimal and then 
        //multiply by the dimension squared to get a number of how many items are needed
        int numCoins = percentCoins * .01 * pow(m_gridDimension, 2);
        int numNothing = percentNothing * .01 * pow(m_gridDimension, 2);
        int numGoombas = percentGoombas * .01 * pow(m_gridDimension, 2);
        int numKoopas = percentKoopas * .01 * pow(m_gridDimension, 2);
        int numMushrooms = percentMushrooms * .01 * pow(m_gridDimension, 2);
        
        //creating coins
        while(numCoins > 0) {
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            if (curLevel[levels][rand1][rand2] == '~') {
                curLevel[levels][rand1][rand2] = 'c';
                numCoins--;
            }
        }
        //creating empty spaces
        while(numNothing > 0) {
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            if (curLevel[levels][rand1][rand2] == '~') {
                curLevel[levels][rand1][rand2] = 'x';
                numNothing--;
            }
        }
        //creating goombas
        while(numGoombas > 0) {
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            if (curLevel[levels][rand1][rand2] == '~') {
                curLevel[levels][rand1][rand2] = 'g';
                numGoombas--;
            }
        }
        //creating koopas
        while(numKoopas > 0) {
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            if (curLevel[levels][rand1][rand2] == '~') {
                curLevel[levels][rand1][rand2] = 'k';
                numKoopas--;
            }
        }
        //creating mushrooms
        while(numMushrooms > 0) {
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            if (curLevel[levels][rand1][rand2] == '~') {
                curLevel[levels][rand1][rand2] = 'm';
                numMushrooms--;
            }
        }

        //creating warp pipe
        if(m_warpPipes != 0){
            int rand1 = rand() % m_gridDimension;
            int rand2 = rand() % m_gridDimension;
            curLevel[levels][rand1][rand2] = 'w';
            m_warpPipes--;
        }
        //creating boss

        int rand1 = rand() % m_gridDimension;
        int rand2 = rand() % m_gridDimension;
        curLevel[levels][rand1][rand2] = 'b';
    }
}

//prints out a single level
void Level::printLevel(int numLevel) {
        for (int rows = 0; rows < m_gridDimension; ++rows) {
            for (int cols = 0; cols < m_gridDimension; ++cols) {
                cout << "[" << curLevel[numLevel][rows][cols] << "]";
            }
            cout << endl;
        }
}

//prints out the entire map
void Level::printMap(){
    for (int i = 0; i < m_numLevels; ++i){
        cout << "Level: " << i << endl;
        printLevel(i);
    }
}

//Add's mario to the level
void Level::addMario(int heroLevel, int heroRow, int heroCol){
    curLevel[heroLevel][heroRow][heroCol] = 'H';

}

//Returns the character at the space in the array chosen
char Level::returnAction(int currLevel, int currRow, int currCol){
    return curLevel[currLevel][currRow][currCol];
}

//Turns' the space in the array to the nothing character
void Level::addNothing(int currLevel, int currRow, int currCol){
    curLevel[currLevel][currRow][currCol] = 'x';
}

//returns the amount of rows/columns total in the grid
int Level::getRows(){
    return m_gridDimension;
}

//returns the amount of levels total in the grid
int Level::getLevels(){
    return m_numLevels;
}