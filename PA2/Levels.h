/// @brief Header file for Translator
/// @file Translator.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef LEVELS_H 
#define LEVELS_H

using namespace std;

class Levels{
  private:
    char*** map;
    int L;
    int N;
  public:
    Levels();
    Levels(int numFloors, int numRC);
    virtual ~Levels();
    void printMap();
    void printLevel(int levelNum);
};
#endif
