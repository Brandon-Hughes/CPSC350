/// @brief Creates a simulation of a game played by mario with varying inputs
/// @file Simulation.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Simulation.h"
#include "Level.h"
#include "Mario.h"

using namespace std;

//Plays a single run of mario with the inputs given
Simulation::Simulation(int numLevel, int gridDimension, int marioLives, int coinsPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercentage, string outF){
    ofstream writefile(outF);
    psaved = false;
    gameEnd = false;
    Level* map = new Level(numLevel, gridDimension, coinsPercent, nothingPercent, goombaPercent, koopaPercent, mushroomPercentage);
    Mario* hero = new Mario(0, 0, marioLives, 0, 0, 0);
    int rand1 = rand() % map->getRows();
    hero->setRow(rand1);
    hero->setCol(rand1);
    writefile << "Level: " << hero->getLevel() << endl;
    for(int j = 0; j < map->getRows(); ++j){
        for(int k = 0; k < map->getRows(); ++k){
                writefile << "[" << map->returnAction(hero->getLevel(), j, k) << "]";
            }
        writefile << endl;
    }
    writefile << endl;
    int moves = 0;
    while(!(psaved || gameEnd)){
        moves++;
        writefile << "Level Number: " << hero->getLevel() << endl;
        writefile << "Mario's Position: (" <<  hero->getRow() << "," << hero->getCol() << ")" << endl;
        writefile << "Mario's Power Level: " << hero->getPL() << endl;
        char m_currPosAction = map->returnAction(hero->getLevel(), hero->getRow(), hero->getCol());
        if(m_currPosAction == 'c'){
            hero->coinIncrease();
            if(hero->getCoins() >= 20){
                hero->coinTrader();
                writefile << "Mario collected 20 coins and gained a life" << endl;
            }
            writefile << "Mario collected a coin" << endl;
            map->addNothing(hero->getLevel(), hero->getRow(), hero->getCol());
        }
        else if(m_currPosAction == 'g'){
            while(true){
                if (hero->regGAttack()){
                    hero->battleCountIncrease();
                    writefile << "Mario fought a Goomba and won" << endl;
                    map->addNothing(hero->getLevel(), hero->getRow(), hero->getCol());
                    break;
                }
                else{
                    if(hero->getPL() > 0){
                        hero->powerLevelDecrease();
                        hero->battleCountReset();
                        writefile << "Mario fought a Goomba and lost" << endl;
                    }
                    else{
                        hero->battleCountReset();
                        hero->livesDecrease();
                        writefile << "Mario fought a Goomba and lost" << endl;
                        if(hero->getLives() == 0){
                            gameEnd = true;
                            break;
                        }
                    }
                }
            }
        }
        else if(m_currPosAction == 'k'){
            while (true){
                if (hero->regKAttack()){
                    hero->battleCountIncrease();
                    writefile << "Mario fought a Koopa and won" << endl;
                    map->addNothing(hero->getLevel(), hero->getRow(), hero->getCol());
                    break;
                }
                else{
                    if(hero->getPL() > 0){
                        hero->powerLevelDecrease();
                        hero->battleCountReset();
                        writefile << "Mario fought a Koopa and lost" << endl;
                    }
                    else{
                        hero->battleCountReset();
                        hero->livesDecrease();
                        writefile << "Mario fought a Koopa and lost" << endl;
                        if(hero->getLives() == 0){
                            gameEnd = true;
                            break;
                            
                        }
                    }
                }
            }
        }
        else if(m_currPosAction == 'b'){
            while(true){
                if (hero->bossAttack()){
                    writefile << "Mario fought the level boss and won" << endl;
                    if(hero->getLevel() == (map->getLevels()-1)){
                        psaved = true;
                        gameEnd = true;
                        break;
                    }else{
                        hero->levelIncrease();
                        writefile << endl;
                        writefile << "Level: " << hero->getLevel() << endl;
                        for(int j = 0; j < map->getRows(); ++j){
                            for(int k = 0; k < map->getRows(); ++k){
                                writefile << "[" << map->returnAction(hero->getLevel(), j, k) << "]";
                            }
                            writefile << endl;
                        }
                        int rand1 = rand() % map->getRows();
                        hero->setRow(rand1);
                        hero->setCol(rand1);
                        break;
                    }
                    
                }
                else{
                    writefile << "Mario fought the level boss and lost" << endl;
                    if(hero->getPL() > 1){
                        hero->powerLevelDecrease2();
                    }
                    else{
                        hero->livesDecrease();
                        if(hero->getLives() == 0){
                            gameEnd = true;
                            break;
                        }
                    }
                }
            }
        }
        else if(m_currPosAction == 'w'){
            writefile << "Mario Warped" << endl;
            if(hero->getLevel() == (map->getLevels()-1)){
                break;
            }
            hero->levelIncrease();
            writefile << endl;
            writefile << "Level: " << hero->getLevel() << endl;
            for(int j = 0; j < map->getRows(); ++j){
                for(int k = 0; k < map->getRows(); ++k){
                    writefile << "[" << map->returnAction(hero->getLevel(), j, k) << "]";
                }
                writefile << endl;
            }
            int rand1 = rand() % map->getRows();
            hero->setRow(rand1);
            hero->setCol(rand1);
        }
        else if(m_currPosAction == 'm'){
            writefile << "Mario ate a mushroom" << endl;
            hero->powerLevelIncrease();
            map->addNothing(hero->getLevel(), hero->getRow(), hero->getCol());
        }
        else if(m_currPosAction == 'x'){
            writefile << "The position is empty" << endl;
        }
        writefile << "Mario has " << hero->getLives() << " lives left." << endl;
        writefile << "Mario has " << hero->getCoins() << " coins." << endl;
        m_marioPosRow = hero->getRow();
        m_marioPosCol = hero->getCol();
        hero->move(map->getRows(), map->getRows());
        m_marioNewPosRow = hero->getRow();
        m_marioNewPosCol = hero->getCol();
        if(m_marioPosCol == m_marioNewPosCol - 1){
            writefile << "Mario will move up" << endl;
        }
        else if(m_marioPosCol == m_marioNewPosCol + 1){
            writefile << "Mario will move down" << endl;
        }
        else if(m_marioPosRow == m_marioNewPosRow - 1){
            writefile << "Mario will move left" << endl;
        }
        else if(m_marioPosRow == m_marioNewPosRow + 1){
            writefile << "Mario will move right" << endl;
        }
        writefile << endl;
    }
    if(psaved == true){
        writefile << "You saved the princess" << endl;
        writefile << "It took " << moves << " amount of moves" << endl;
    }
    else {
        writefile << "You are a failure" << endl;
        writefile << "It took " << moves << " amount of moves" << endl;
    }
    writefile.close();
    delete map;
    delete hero;
}

//Destructor
Simulation::~Simulation(){
    
}