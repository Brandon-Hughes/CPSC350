/// @brief Header file for Mario
/// @file Mario.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef MARIO_H
#define MARIO_H

class Mario {
    private:
        int numCoins;
        int numPL;
        int numLives; // V
        int posRow;
        int posCol;
        int posLevel;
        int battleCount;
    public:
        Mario();
        ~Mario();
        Mario(int coins, int power, int lives, int curRow, int curCol, int curLevel);
        int getRow();
        int getCol();
        int getLevel();
        int getCoins();
        int getLives();
        int getPL();
        void setRow(int newRow);
        void setCol(int newCol);
        void levelIncrease();
        void levelDecrease();
        void livesDecrease();
        void powerLevelIncrease();
        void powerLevelDecrease();
        void powerLevelDecrease2();
        void battleCountIncrease();
        void battleCountReset();
        void coinIncrease();
        void coinTrader();
        void move(int mapRow, int mapCol);
        bool regGAttack();
        bool regKAttack();
        bool bossAttack();
        bool winGame(int numLevels);

};





#endif