## Graph Algorithms Implementation

**id:** 322234782

**email:** kronfeldshay@gmail.com

## Overview
This is library provides an implementation of a Graph class in C++. The graph is represented using an adjacency matrix and supports both weighted and unweighted graphs, provides various algorithms for working with graphs, including depth-first search (DFS), Bellman-Ford algorithm, cycle detection, and bipartite graph checking.

## Assumptions
- All edges are considered directed because the provided adjacency matrix does not distinguish between undirected edges with weight -k and two directed edges with weights -k in opposite directions. Undirected edges can be treated as a special case of directed edges.
- A weight of 0 indicates the absence of an edge between two vertices (usually represented by infinity in other implementations).

## Usage
- Create an instance of the Graph class, either using the default constructor or by providing an adjacency matrix.
- Use the various methods provided by the Algorithms class to perform graph operations, such as checking connectivity, finding shortest paths, detecting cycles, and verifying if the graph is bipartite.

## Method Implementations
 
    • Bellman-Ford Algorithm:This function find the shortest paths from a single source vertex to all other vertices in a weighted graph. 
    This is occure by n-1 times of 'relax' to all the vertices in the graph.
    Each iteration attempts to improve the estimated shortest distances to all vertices by considering all edges. 
    • IsConnected: check strong connection by do DFS and goes over all the vertices.
    If it did not go through all the vertices, the graph is not necessarily connected. Then transposes the edges over and run DFS a second time.
    Only if in both passes of the graph it has passed all the vertices, the graph is connected.
    • hasNegativeCycle: This function `hasNegativeCycle` determines whether a given graph contains a negative cycle.
    It does so by performing the Bellman-Ford algorithm starting from each vertex in the graph (n-1 times) and do again beelman ford and if in this time (the n) the path is not the same, there is a negative cycle.  
    • Shortest Path Finding: Finds the shortest path between two vertices in a graph.
    • Bipartite Graph Detection: Determines if a given graph is bipartite or not.
    

## Testing
- The project includes a set of test cases (Test.cpp) to verify the correctness of the implemented algorithms. Run the test suite after building the project to ensure that the algorithms function as expected.
