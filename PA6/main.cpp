/// @brief main program for project assignment 6
/// @file main.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "WGraph.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){

    //gets input of file
    ifstream readfile(argv[1]);
    string line;
    int m_lines = 0;

    //calculates how many columns are in the file 
    while(getline(readfile, line)){
        m_lines++;
    }
    readfile.clear();
    readfile.seekg(0);
    WGraph myGraph(m_lines);

    //fills in the wgraph
    int atCurrSpace = 0;
    int atNextSpace = 0;
    readfile.clear();
    readfile.seekg(0);
    getline(readfile, line);
    for(int i = 0; i < m_lines; ++i){
        for(int j = 0; j < m_lines; ++j){
                atNextSpace = line.find(' ', atCurrSpace);
                string c = line.substr(atCurrSpace, atNextSpace);
                double pHeight = stod(c);
                atCurrSpace = atNextSpace+1;
                myGraph.addEdge(i, j, pHeight);
        }
        getline(readfile, line);
        atCurrSpace = 0;
    }
    


//print wgraph
cout << "Current Matrix: " << endl;
myGraph.printADJ();
//create mst
cout << endl;
myGraph.computeMST();
//print mst value
cout << "Matrix's MST: " << myGraph.printMSTResult() << endl;

//print mst
cout << endl;
cout << "MST Matrix: " << endl;
myGraph.printMST();

return 0;
}
