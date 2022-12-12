/********************************************************************************
 * File  :   graph.h                                                            *
 * Author: Mohammad Seeam                                                       *
 * Graph Implementation In C++                                                  *
 * This header structure for all cpp and h files.                               *
 * This file, graph.h includes only data.h                                      *
 * Class representing an undirected, unweighted graph                            *
 *******************************************************************************/

#include <vector>
#include <queue>
#include "data.h"

using namespace std;

class Graph {

    private:
        int numVertices; 
        std::vector<std::vector<int>> adjList;
        std::vector<int> vertices; 
        void DFS_helper(int, std::vector<std::vector<int>>&, std::vector<bool>&, std::vector<int>&);

    public:
        Graph(int);
        Result addVertex(int);
        Result addEdge(int, int);     
        Result removeVertex(int);
        Result removeEdge(int, int);
        std::vector<int> getVertices();
        std::vector<Tuple> getEdges();
        void printList();
        void printMatrix();
        void clearList();
        void sizeCheck();
        std::vector<int> BFS(int);
        std::vector<int> DFS(int);
};