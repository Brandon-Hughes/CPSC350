/// @brief Takes a single word/sentence and changes it to it's respect Robber
/// @file Translator.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "Levels.h"
#include <iostream>

Levels::Levels(){
    map = new char**[5];
    for(int i = 0; i < 5; ++i){
        map[i] = new char*[5];
            for(int j = 0; j < 5; ++j){
                map[i][j] = new char[5];
            }
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            for(int k = 0; k < 5; ++k){
                map[i][j][k] = '~';
            }
        }
    }
    L = 5;
    N = 5;
}

Levels::Levels(int numLevels, int numRC){
    map = new char**[numLevels];
    for(int i = 0; i < numLevels; ++i){
        map[i] = new char*[numRC];
            for(int j = 0; j < numRC; ++j){
                map[i][j] = new char[numRC];
                for(int k = 0; k < numRC; ++k){
                }
            }
    }
    for(int i = 0; i < numLevels; ++i){
        for(int j = 0; j < numRC; ++j){
            for(int k = 0; k < numRC; ++k){
                map[i][j][k] = '~';
            }
        }
    }
    L = numLevels;
    N = numRC;
}

Levels::~Levels(){
    for(int i = 0; i < L; ++i){
        for(int j = 0; j < N; ++j){
            delete[] map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}

void Levels::printMap(){
    for(int i = 0; i < L; ++i){
        cout << "Level: " << i << endl;
        for(int j = 0; j < N; ++j){
            for (int k = 0; k < N; ++k){
                cout << "[" << map[i][j][k] << "]";
            }
            cout << endl;
        }
    }

}

void Levels::printLevel(int levelNum){
    cout << "Level: " << levelNum << endl;
    for(int j = 0; j < N; ++j){
        for(int k = 0; k < N; ++k){
            cout << "[" << map[levelNum][j][k] << "]";
        }
        cout << endl;
    }
}
