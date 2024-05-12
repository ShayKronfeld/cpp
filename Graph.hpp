/*
NAME: shay kronfeld
ID: 322234782
EMAIL: kronfeldshay@gmail.com
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept>

using namespace std;

namespace ariel {
    class Graph {
    private:
        vector<vector<int>> adjacencyMatrix; // Adjacency matrix representation of the graph
        size_t numberOfVertices; // Number of vertices in the graph
        size_t numberOfEdge; // Number of edges in the graph
        bool isDirected; // Directed or undirected graph
        bool isWeighted; // Weighted or unweighted graph

    public:
        Graph(); // Default constructor
        Graph(const vector<vector<int>>& matrix); // New constructor to get adjacency matrix

        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph() const;
        size_t getNumberOfVertices() const;
        size_t getNumberOfEdge() const;
        int getCellInAdjacencyMatrix(size_t i, size_t j) const;
        const vector<vector<int>>& getAdjMatrix() const;
        vector<size_t> getNeighbors(size_t vertex) const;

        };

}
#endif // GRAPH_H