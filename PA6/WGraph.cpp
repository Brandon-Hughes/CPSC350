/// @brief Creates a weighted Graph
/// @file WGraph.cpp
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#include "WGraph.h"
#include "PQueue.h"

#include <iostream>
using namespace std;

//default constructor
WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
}

//overloaded constructor
WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  m_mst = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
    m_mst[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();
      m_mst[i][j] = 0.0;
    }
  }
}

//default destructor
WGraph::~WGraph(){
  for(int i = 0; i < m_size; ++i){
    delete[] m_adj[i];
    delete[] m_conn[i];
  }
  delete[] m_conn;
  delete[] m_adj;
  
}

//adds a connection between I and J with a value of w
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

//removes the connection between I and J
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

//checks if i and j are connected
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

//calculates the floyd-warshall algorithm
void WGraph::calcFW(){
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }

  for(int im = 0; im < m_size; ++im){ //transitive closure
    for(int source = 0; source < m_size; ++source){
      for(int sink = 0; sink < m_size; ++sink){
        //every possible pair of source,sink and intermediate node
        if(source==sink){
          continue;
        }
        if(m_conn[source][im] != std::numeric_limits<double>::max() &&
           m_conn[im][sink] != std::numeric_limits<double>::max() &&
           m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
          m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }

      }
    }
  }


}

//calculates the minimum spanning tree
void WGraph::computeMST(){
  PQueue<double>* edges = new PQueue<double>(true);
  m_mstresult = 0.0;
  double temp = 0.0;
  for(int i = 0; i < m_size; ++i){
    for(int j = i+1; j < m_size; ++j){
      edges->add(m_adj[i][j]);
    }
  }
  
  DblList<double>* resultList = new DblList<double>();

  while(edges->getSize() > 0){
    temp = edges->remove();
    int x = findI(temp);
    int y = findJ(temp);
    if(!(resultList->contains(x) && resultList->contains(y))){
      resultList->addBack(x);
      resultList->addBack(y);
      m_mst[x][y] = temp;
      m_mst[y][x] = temp;
      m_mstresult += temp;
    }
  }
}

//returns the minimum spanning tree total
double WGraph::printMSTResult(){
  computeMST();
  return m_mstresult;
}

//prints the Minimum spanning Tree
void WGraph::printMST(){
  for(int i = 0; i < m_size; i++){
    for(int j = 0; j < m_size; j++){
      cout << m_mst[i][j] << " ";
    }
    cout << endl;
  }
}

//prints the Weighted Graph
void WGraph::printADJ(){
  for(int i = 0; i < m_size; i++){
    for(int j = 0; j < m_size; j++){
      cout << m_adj[i][j] << " ";
    }
    cout << endl;
  }
}

//finds the first coordinate
int WGraph::findI(double w){
  for(int i = 0; i < m_size; ++i){
    for(int j = i+1; j < m_size; ++j){
      if ((m_adj[i][j]) == w){
        return i;
      }
    }
  }
}

//finds the second coordinate 
int WGraph::findJ(double w){
  for(int i = 0; i < m_size; ++i){
    for(int j = i+1; j < m_size; ++j){
      if ((m_adj[i][j]) == w){
        return j;
      }
    }
  }
}

//returns the cheapest cost from the floyd warshall
double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j];
}
