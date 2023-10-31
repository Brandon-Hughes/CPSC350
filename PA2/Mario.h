// mario file
#ifndef MARIO_H 
#define MARIO_H

using namespace std;

class Mario{
  private:
    int numCoins;
    int numPL;
    int numLives; // V
    int posRow;
    int posCol;
    int posLevel;
  public:
    Mario();
    Mario(int coins, int power, int lives, int curRow, int curCol, int curLevel);
    virtual ~Mario();
    int getRow();
    int getCol();
    int getLevel();
    int getCoins();
    int getLives();
    void setRow(int newRow);
    void setCol(int newCol);
    void levelIncrease();
    void coinIncrease();
    void coinTrader();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};
#endif
