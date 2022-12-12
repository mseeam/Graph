/********************************************************************************
 * File  :   graph.cpp                                                          *
 * Author: Mohammad Seeam                                                       *
 * Graph Implementation In C++                                                  *
 * This header structure for all cpp and h files.                               *
 * This file, graph.cpp includes only graph.h                                   *
 *******************************************************************************/

#include "graph.h"
#include <algorithm>

using namespace std;

//deletes an element by index from a vector
void delete_element(vector<int>& temp, int target) {
     temp.erase(temp.begin()+target);
}

void delete_value(vector<int>& temp, int target){
    temp.erase(std::remove(temp.begin(), temp.end(), target), temp.end());
}

//checks if a vector contains an elem
bool vectorContainsElement(vector<int>& vec, int target){
    bool res = std::find(vec.begin(), vec.end(), target) != vec.end();

    return res;
}

// Constructor
Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    this->adjList.resize(numVertices);
}

//add an edge to the graph
Result Graph::addEdge(int u, int v) {

    Result res;

    //first add the vertexes in the graph
    Result uExists = addVertex(u);
    Result vExists = addVertex(v);

    bool vAddedInUList = false;
    bool uAddedInVList = false;

    if(uExists.success && vExists.success){

        //check u's list if v already added
        vAddedInUList = vectorContainsElement(adjList[u], v);
        if(!vAddedInUList){
            adjList[u].push_back(v);
            vAddedInUList=true;
        }

        //check v's list if u already added
        uAddedInVList = vectorContainsElement(adjList[v], u);
        if(!uAddedInVList){
            adjList[v].push_back(u);
            uAddedInVList=true;
        }
    }

    //if all good
    if(uExists.success && vExists.success && vAddedInUList && uAddedInVList){
        res.success=true;
        res.message="SUCCESS";
    }else{
        res.success=false;
        res.message = "FAILED";
        if(!uExists.success){res.message = res.message + "\n" + " " + uExists.message;}
        if(!vExists.success){res.message = res.message + "\n" + " " + vExists.message;}
    }

    return res;

}

Result Graph::addVertex(int v) {

    Result res;

    if(v>numVertices){
        res.message = "FAILED";
        res.message = res.message + "\n" + " " + "Vertex " + std::to_string(v) + " exceeds max possible node range [0, " + std::to_string(numVertices) + "]";  
        res.success = false; 
    }else{
       //check first if exists
        if(!vectorContainsElement(vertices, v)){
            vertices.push_back(v);
            res.message="SUCCESS";
        }else{
            res.message = "SUCCESS";
            res.message = res.message + "\n" + " " + "Vertex " + std::to_string(v) + " already existed";
        }

        //whether added now or previously added, return true
        res.success = true;
    }

    return res;
}

Result Graph::removeVertex(int v) {

    Result res;

    //first check if vertex exists
    if(!vectorContainsElement(vertices, v)){
        res.success=false;
        res.message="FAILED";
        res.message = res.message + "\n" + " " + "Vertex " + std::to_string(v) + " does not exist";
    }else{
        for(int i=0; i< numVertices; i++){
            if(v==i){
                //this is the vector of the node itself
                //clear the whole vector
                //size becomes 0
                adjList[v].clear();
            }else{
                //delete v from other vertices vectors
                for(int j=0;j<adjList[i].size();j++){
                    if(adjList[i][j]==v){
                        //delete_element(adjList[i], j);
                        delete_value(adjList[i], v);
                    }
                }
            }
        }

        //delete the vertex from vertices vector
        delete_value(vertices, v);
        res.success=true;
        res.message="SUCCESS";
    }

    return res;
}

Result Graph::removeEdge(int u, int v) {

    Result res;

    //check if node u and v exists
    bool uExists=vectorContainsElement(vertices, u);
    bool vExists=vectorContainsElement(vertices, v);

    //check if u and v has a link between them
    bool U_Vlink = vectorContainsElement(adjList[u], v);
    bool V_Ulink = vectorContainsElement(adjList[v], u);
    
    if(!uExists || !vExists){
        res.success=false;
        res.message="FAILED";
        res.message = res.message + "\n" + " " + "One or both vertices (" + std::to_string(u) + "," + std::to_string(v) + ") do not exist";
    }else if(!U_Vlink && !V_Ulink){
        res.success=false;
        res.message="FAILED";
        res.message = res.message + "\n" + " " + "Edge does not exist between vertices (" + std::to_string(u) + "," + std::to_string(v) + ")";
    }else{
        delete_value(adjList[v], u);
        delete_value(adjList[u], v); 
        res.success=true;
        res.message="SUCCESS";
    }

    return res;
    
}

// Function to clear the adjacency list
void Graph::clearList() {
    for (int i = 0; i < numVertices; i++) {
        adjList[i].clear();
    }

    vertices.clear();
}

// Function to get the vertices in the graph
vector<int> Graph::getVertices() {
    return vertices;
}

// Function to get the edges in the graph
vector<Tuple> Graph::getEdges() {
    vector<Tuple> edges;
    for (int i = 0; i < numVertices; i++) {
        if(vectorContainsElement(vertices, i)){
            int v = i;
            for(int j=0; j< adjList[v].size(); j++){
                Tuple t;
                t.from=v;
                t.to= adjList[v][j];
                edges.push_back(t);
            }
        }
    }
    return edges;
}

void Graph::printList() {
    cout << "===printList===" << endl;
    for(int i=0;i<numVertices; i++){
        if(adjList[i].size()!=0){
            cout << i << "==>";
            for(int j=0;j<adjList[i].size();j++){
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }else{
            cout << i << "==>" << endl;
        }
    }
    cout << "===printList===" << endl << endl;
}

void Graph::printMatrix(){
    cout << "===printMatrix===" << endl;
    
    for(int i=0;i<numVertices; i++){
        if(adjList[i].size()==0){
            //cout << i << "|";
            for(int j=0; j<numVertices; j++){
                cout << "0" << " ";
            }
            cout << endl;
        }else{
            for(int j=0; j<numVertices; j++){
                if(vectorContainsElement(adjList[i], j)){
                    cout << "1" << " ";
                }else{
                    cout << "0" << " ";
                }
            }
            cout << endl;
        }
    }
    cout << "===printMatrix===" << endl << endl;
}

void Graph::sizeCheck(){
    cout << "===sizeCheck===" << endl;
    for(int i=0; i<numVertices; i++){
        cout << "Size " << i << "==> " << adjList[i].size() << endl;
    }
    cout << "===sizeCheck===" << endl << endl;
}

// Function to perform a breath first search
std::vector<int> Graph::BFS(int start){
    vector<int> res;
    vector<bool> visited(numVertices, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        res.push_back(current);
        for (auto i: adjList[current]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return res;
    
}

std::vector<int> Graph::DFS(int start)
{   
    vector<int> res;
    vector<bool> visited(numVertices, false);

    DFS_helper(start, adjList, visited, res);

    return res;
}


void Graph::DFS_helper(int start, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, std::vector<int>& res){
    // Mark the current node as visited
    visited[start] = true;

    res.push_back(start);

    // Explore the adjacent nodes of the current node
    for (int i = 0; i < adjList[start].size(); i++)
    {
        int adjacent = adjList[start][i];
        if (!visited[adjacent])
        {
            DFS_helper(adjacent, adjList, visited, res);
        }
    }
}


