/// @brief Header file for a weighted Graph
/// @file WGraph.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>

//an unweighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public:
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();
  void computeMST();
  void printMST();
  void printADJ();
  double printMSTResult();

private:
  double** m_adj;
  double** m_conn;
  double** m_mst;
  double m_mstresult;
  unsigned int m_size; //nodes in WGraph (fixed)
  int findI(double w);
  int findJ(double w);

};






#endif
