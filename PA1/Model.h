/// @brief Header file for Model
/// @file Model.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef MODEL_H
#define MODEL_H

#include <string>
using namespace std;

class Model{
  private:
    string m_return;
  public:
    Model();
    virtual ~Model();
    string translateSingleConsonant(char c);
    string translateSingleVowel(char c);
};

#endif
