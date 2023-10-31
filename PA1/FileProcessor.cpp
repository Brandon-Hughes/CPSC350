/// @brief Converts a .txt file to a .html file with it's original text, and it's Robber Language translation
/// @file FileProcessor.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "FileProcessor.h"
#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <fstream>

//default constructor
FileProcessor::FileProcessor(){
}

//default destructor
FileProcessor::~FileProcessor(){

}

//takes in an input file and output file
//Converts a .txt file to a .html file with it's original text
// and it's robber language text.
void FileProcessor::processFile(string inF, string outF){
    Translator* t2 = new Translator();
    ifstream readfile(inF);
    //cout << "Read file created" << endl;
    ofstream writefile(outF);
    //cout << "Write file created" << endl;
    string line;
    if(readfile.is_open())
    {
        writefile << "<!DOCTYPE html>" << endl;
        writefile << "<html>" << endl;
        writefile << "<head></head>" << endl;
        writefile << "<body>" << endl;
        writefile << "<b>" << endl;
        while(getline(readfile, line))
        {
            writefile << line << "<br>" << endl;
        }
        writefile << "</b>" << endl;
        readfile.clear();
        readfile.seekg(0);
        writefile << "<br><br><br>" << endl;
        writefile << "<i>" << endl;
        while(getline(readfile, line))
        {
            writefile << t2->translateEnglishSentence(line) << "<br>" << endl;
        }
        writefile << "</i>" << endl;
        writefile << "</body>" << endl;
        writefile << "</html>";
        writefile.close();
        //cout << "Write file closed" << endl;
    }
    else {
        cout << "File is invalid.";
    }
    readfile.close();
    //cout << "Read File closed" << endl;
    delete t2;

}
