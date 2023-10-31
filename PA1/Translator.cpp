/// @brief Takes a single word/sentence and changes it to it's respect Robber
/// @file Translator.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "Translator.h"
#include "Model.h"

//default constructor
Translator::Translator(){
  m_returnt1 = "";
  m_returnt2 = "";
}

//default destructor
Translator::~Translator(){

}

//Takes in character and returns true if it's a consonant or false if it's not
bool isConsonant(char c){
  if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h'
     || c == 'j' || c == 'k' || c == 'l'  || c == 'm'  || c == 'n'  || c == 'p' 
      || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w'
       || c == 'x' || c == 'y' || c == 'z' || c == 'B' || c == 'C' || c == 'D' 
       || c == 'F' || c == 'G' || c == 'H' || c == 'J' || c == 'K' || c == 'L'  
        || c == 'M'  || c == 'N'  || c == 'P' || c == 'Q' || c == 'R' || c == 'S' 
        || c == 'T' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z'){
          return true;
        }
  else{
    return false;
  }
}


//Iterates over a single word, if it's a consonant it'll Robber it if it's a vowel/punction
//it does nothing
string Translator::translateEnglishWord(string s){
  Model* m1 = new Model();
  m_returnt1 = "";
  for(char c: s){
    if(isConsonant(c)){
      m_returnt1 += m1->translateSingleConsonant(c);
    }
    else{
      m_returnt1 += m1->translateSingleVowel(c);
    }
  }
  delete m1;
  return m_returnt1;
}

//Iterates over a sentance, if it's a consonant it'll Robber it if it's a vowel/punction
//it does nothing
string Translator::translateEnglishSentence(string s){
  m_returnt2 = "";
  m_returnt2 += translateEnglishWord(s);
  return m_returnt2;
}
