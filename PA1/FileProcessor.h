/// @brief Header file for FileProcessor
/// @file FileProcessor.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
using namespace std;

class FileProcessor{
  public:
    FileProcessor();
    virtual ~FileProcessor();
    void processFile(string inF, string outF);
    
};
#endif
