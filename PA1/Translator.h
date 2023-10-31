/// @brief Header file for Translator
/// @file Translator.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef TRANSLATOR_H 
#define TRANSLATOR_H

#include <string>
using namespace std;

class Translator{
  private:
    string m_returnt1;
    string m_returnt2;
  public:
    Translator();
    virtual ~Translator();
    string translateEnglishWord(string s);
    string translateEnglishSentence(string s);
};
#endif
