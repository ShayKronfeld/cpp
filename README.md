Graph Algorithms Implementation

id: 322234782

email: kronfeldshay@gmail.com

This project implements various graph algorithms in C++.

Assumptions

    • The weight of 0 represents the absence of an edge between two vertices (typically represented by infinity in other implementations).

Usage

    • To use the implemented algorithms, include the respective header files (Algorithms.h, Graph.h) in your C++ project. Then, instantiate the Algorithms and Graph classes to perform the desired operations on your graph data.

 Method Implementations
 
    • Bellman-Ford Algorithm: Finds the shortest paths from a single source vertex to all other vertices in a weighted graph. Handles negative edge weights and detects negative cycles.
    • Depth-First Search (DFS): Traverses a graph depth-first, visiting all reachable vertices from a given source vertex.
    • Connected Components Detection: Determines if a graph is connected by checking if all vertices are reachable from each other.
    • Negative Cycle Detection: Detects the presence of negative cycles in a graph.
    • Shortest Path Finding: Finds the shortest path between two vertices in a graph.
    • Bipartite Graph Detection: Determines if a given graph is bipartite or not.
    
How to Build

    • To build the project, use a C++ compiler that supports C++11 or later standards. Compile the source files (Algorithms.cpp, Graph.cpp, Test.cpp) and link them together to create an executable.

Testing

    • The project includes a set of test cases (Test.cpp) to verify the correctness of the implemented algorithms. Run the test suite after building the project to ensure that the algorithms function as expected.
