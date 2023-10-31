/// @brief Header file for Simulation
/// @file Simulation.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
using namespace std;

class Simulation{
    private:
        int m_levelNum;
        int m_marioPosRow;
        int m_marioPosCol;
        int m_marioNewPosRow;
        int m_marioNewPosCol;
        char m_newPosAction;
        char m_currPosAction;
        bool psaved;
        bool gameEnd;
    public:
        Simulation(int numLevel, int gridDimension, int marioLives, int coinsPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercentage, string outF);
        ~Simulation(); 
        //Simulation(input file, output file);
};

#endif