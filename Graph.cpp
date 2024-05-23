/*
NAME: shay kronfeld
ID: 322234782
EMAIL: kronfeldshay@gmail.com
*/

#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

namespace ariel {
    // Empty constructor
    Graph::Graph() : numberOfVertices(0), numberOfEdge(0), isWeighted(false) {}

    // Constructor
    Graph:: Graph(const vector<vector<int>>& matrix) {
        loadGraph(matrix);
    }


    // Load graph from an adjacency matrix
    void Graph::loadGraph(const vector<vector<int>>& matrix) {
    numberOfVertices=0;
    numberOfEdge=0;
    isWeighted=false;


    // If the matrices are not the same size
    for (const auto& row : matrix) { 
        if (row.size() != matrix.size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix");
        }
    }

    for (int i=0; i<matrix.size(); i++){
        if (matrix[i][i]!=0){
            throw invalid_argument("Invalid graph: The diagonal has a value other than 0");
        }
    }
    
    
    adjacencyMatrix = matrix;
    numberOfVertices= matrix.size();
    
        for (size_t i=0; i< matrix.size(); i++){
                for (size_t j=0; j< matrix.size(); j++){
                
                    if (matrix[i][j]!=0) // check if there is edge
                        numberOfEdge++; 

                    if (matrix[i][j]!=0 && matrix[i][j]!=1) // check if the graph is weighted
                        isWeighted= true;

                }
        }

    }

    // Print the graph
    void Graph::printGraph() const {
       cout << "Graph with " << numberOfVertices << " vertices and " << numberOfEdge << " edges." << endl;
    }

    // Get the number of vertices in the graph
    size_t Graph::getNumberOfVertices() const {
            return numberOfVertices;
        }

    // Get the number of edges in the graph
    size_t Graph::getNumberOfEdge() const {
            return numberOfEdge;
        }

    //  Get cell in the adjacency matrix
    int Graph::getCellInAdjacencyMatrix(size_t i, size_t j) const {
        return adjacencyMatrix[i][j];
    }

    // Function to get the adjacency matrix
    const vector<vector<int>>& Graph::getAdjMatrix() const {
        return adjacencyMatrix;
    }

     vector<size_t> Graph::getNeighbors(size_t vertex) const {
            vector<size_t> neighbors;
            if (vertex < 0 || vertex >= adjacencyMatrix.size()) {
                return neighbors; // Return empty vector if vertex is out of bounds
            }
            for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
                if (adjacencyMatrix[vertex][i] != 0) {
                    neighbors.push_back(i); // Add neighbor to the vector if there is an edge
                }
            }
            return neighbors;
        }
}


