/// @brief main file that takes two command line arguments and uses them as a game input and game output to 
/// @file main.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char** argv){
    ifstream readfile(argv[1]);
    string line;
    int L;
    int N;
    int V;
    int coinP;
    int nothingP;
    int goombaP;
    int koopaP;
    int mushroomP;
    if(readfile.is_open())
    {
        getline(readfile, line);
        L = stoi(line);
        getline(readfile, line);
        N = stoi(line);
        getline(readfile, line);
        V = stoi(line);
        getline(readfile, line);
        coinP = stoi(line);
        getline(readfile, line);
        nothingP = stoi(line);
        getline(readfile, line);
        goombaP = stoi(line);
        getline(readfile, line);
        koopaP = stoi(line);
        getline(readfile, line);
        mushroomP = stoi(line);
    }
    readfile.close();
    if((coinP+nothingP+goombaP+koopaP+mushroomP) == 100){
        Simulation* s1 = new Simulation(L, N, V, coinP, nothingP, goombaP, koopaP, mushroomP, argv[2]);
        delete s1;
    }
    else{
        cout << "Unable to accept input as your percentages (Coins, Nothing, Goomba, Koopa, Mushroom) do not add up to 100" << endl;
    }
    
    return 0;
}
