/// @brief Taking a single character and changing it to it's proper Robber form
/// @file Model.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "Model.h"

//default constructor
Model::Model(){
  m_return = "";
}

//default destructor
Model::~Model(){

}

//Takes in a single character and coverts it to it's character, o, character
string Model::translateSingleConsonant(char c){
  m_return = "";
  m_return += c;
  m_return += "o";
  m_return += c;
  return m_return;
}

//Takes in a single character and returns the character back
string Model::translateSingleVowel(char c){
  m_return = "";
  m_return += c;
  return m_return;
}
