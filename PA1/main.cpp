/// @brief main file that takes two command line arguments and converts the text in the first to a proper html translation
/// @file main.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "FileProcessor.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  FileProcessor* fp1 = new FileProcessor();
  fp1->processFile(argv[1], argv[2]);
  delete fp1;
  cout << "Complete" << endl;
  return 0;

}
