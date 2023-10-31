/// @brief Header file for level
/// @file Level.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef LEVEL_H
#define LEVEL_H

class Level {
    private:
        int m_numLevels;
        int m_gridDimension;
        int m_percentCoins;
        int m_percentNothing;
        int m_percentGoombas;
        int m_percentKoopas;
        int m_percentMushrooms;
        char*** curLevel;
    public:
        Level();
        Level(int numLevels, int gridDimension, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms);
        ~Level();
        void populateLevel(char*** curLevel, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms);
        void printLevel(int numLevel);
        void printMap();
        void addMario(int heroLevel, int heroRow, int heroCol);
        char returnAction(int currLevel, int currRow, int currCol);
        void addNothing(int currLevel, int currRow, int currCol);
        int getRows();
        int getLevels();
};




#endif