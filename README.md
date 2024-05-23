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
 
- Bellman-Ford Algorithm: This function finds the shortest paths from a single source vertex to all other vertices in a weighted graph. It does this by performing 'relaxation' on all edges (n-1) times, where n is the number of vertices. Each iteration attempts to improve the estimated shortest distances to all vertices by considering all edges.
 
- IsConnected: This function checks if the graph is strongly connected by performing a Depth-First Search (DFS) from an arbitrary vertex. If the DFS does not visit all vertices, the graph is not strongly connected. The graph's edges are then transposed, and a second DFS is performed. If all vertices are visited in both passes, the graph is strongly connected.
 
- hasNegativeCycle: This function determines whether the graph contains a negative cycle by using the Bellman-Ford algorithm. It runs the Bellman-Ford algorithm from each vertex (n-1) times and then performs one more iteration. If any distance can be further relaxed during this final iteration, it indicates the presence of a negative cycle.

- ShortestPath: This function finds the shortest path between two vertices in a graph. It executes the Bellman-Ford algorithm from the start vertex to obtain distances and parent information. Starting from the target vertex, it backtracks using the parent array to construct the path to the start vertex. If a vertex reaches a sentinel value, it indicates no path exists, and the function returns "-1". The constructed path is then reversed to get the correct order of vertices and converted to a string with vertices separated by "->".

- isContainsCycle: This function checks if the graph contains a cycle by performing a Depth-First Search (DFS) traversal from each vertex. During the traversal, it tracks visited vertices and maintains a stack to detect back edges. The presence of back edges indicates a cycle.

- isBipartite: This function determines if the graph is bipartite by performing a Depth-First Search (DFS) traversal from each vertex. During the traversal, it assigns colors to vertices such that adjacent vertices have different colors. If a vertex is encountered with the same color as its neighbor, the graph is not bipartite. If the traversal completes without conflicts in coloring, the function concludes the graph is bipartite and returns a string indicating the sets A and B along with their respective vertices.
     

## Testing
- The project includes a set of test cases (Test.cpp) to verify the correctness of the implemented algorithms. Run the test suite after building the project to ensure that the algorithms function as expected.
