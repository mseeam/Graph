/********************************************************************************
 * File  :   main.cpp                                                           *
 * Author: Mohammad Seeam                                                       *
 * Graph Implementation In C++                                                  *
 * This header structure for all cpp and h files.                               *
 * This file, main.cpp includes only graph.h                                    *
 *******************************************************************************/

#include "graph.h"

//command prompt to compile below
//clear && g++ -std=c++11 main.cpp graph.cpp && ./a.out

int main(int argc, char const *argv[])
{

	int numVertices = 12; 

    Graph G(numVertices);

    Result res;

    //print numVertices
    cout << "Max Graph size: " << numVertices << endl << endl;

    //add vertex 2, success
    res = G.addVertex(2);
    cout << "addVertex(2): " << res.message << endl;
    cout << endl;

    //add vertex 2 again, fail, should return error
    res = G.addVertex(2);
    cout << "addVertex(2): " << res.message << endl;
    cout << endl;

    //add vertex 20, fail, vertex out of range error
    res = G.addVertex(20);
    cout << "addVertex(20): " << res.message << endl;
    cout << endl;

    //add edge (2,4), success
    res = G.addEdge(2,4);
    cout << "addEdge(2,4): " << res.message << endl;
    cout << endl;

    //add edge (20,4), success, but vertex 20 does not exists
    res = G.addEdge(20,4);
    cout << "addEdge(20,4): " << res.message << endl;
    cout << endl;

    //add edge (20,40), fail, vertex 20 and 40 do not exist
    res = G.addEdge(20,40);
    cout << "addEdge(20,40): " << res.message << endl;
    cout << endl;

    //add edge (4,2), success, but edge already exists
    res = G.addEdge(4,2);
    cout << "addEdge(4,2): " << res.message << endl;
    cout << endl;

    //add more edge, success
    res = G.addEdge(2,3);
    res = G.addEdge(2,5);

    //remove vertex 30, fail, vertex out of range error
    res = G.removeVertex(30);
    cout << "removeVertex(30): " << res.message << endl;
    cout << endl;

	//remove vertex 3, success
	res = G.removeVertex(3);
    cout << "removeVertex(3): " << res.message << endl;
    cout << endl;

    //remove vertex 2, success
    res = G.removeVertex(2);
    cout << "removeVertex(2): " << res.message << endl;
    cout << endl;

   	//remove edge (2,4), fail, vertex 2 does not exist
   	res = G.removeEdge(2, 4);
   	cout << "removeEdge(2, 4): " << res.message << endl;
    cout << endl;

	//add vertex 3, success
    res = G.addVertex(3);
    cout << "addVertex(3): " << res.message << endl;
    cout << endl;

    //remove edge (3,5), fail, no edge exists
    res = G.removeEdge(3, 5);
   	cout << "removeEdge(3, 5): " << res.message << endl;
    cout << endl;

   
    //clean list
    cout << "clear graph...cleared" << endl << endl;
    G.clearList();

    //add edges again
	G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(2, 0);
    G.addEdge(2, 3);
    G.addEdge(3, 3);

    //get vertices
    vector<int> vertices = G.getVertices();
    cout << "getVertices(): "; 
    for(int i=0;i<vertices.size(); i++){cout << vertices[i] << " ";}
    cout << endl << endl;

	//get edges
	vector<Tuple> edges = G.getEdges();
	cout << "getEdges(): "; 
	for(int i=0;i<edges.size(); i++){cout << "(" << edges[i].from << "," << edges[i].to << ") ";}
    cout << endl << endl;


	G.printList();
    G.printMatrix();
    G.sizeCheck();

    //run BFS
	vector<int> bsfResult = G.BFS(2);
    cout << "BFS(): "; 
    for(int i=0;i<bsfResult.size(); i++){cout << bsfResult[i] << " ";}
    cout << endl << endl;

	//run DFS
	vector<int> dsfResult = G.DFS(2);
    cout << "DFS(): "; 
    for(int i=0;i<dsfResult.size(); i++){cout << dsfResult[i] << " ";}
    cout << endl << endl;
	
  
    return 0;
}
