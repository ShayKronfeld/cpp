/*
NAME: shay kronfeld
ID: 322234782
EMAIL: kronfeldshay@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");

     vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");

}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}. ");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0"); 
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test hasNegativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 3, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 7}, 
        {0, 0, 0, 0, 5}, 
        {0, 0, 0, 0, 0}}; 
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::hasNegativeCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, -1, 0, 7},
        {-1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::hasNegativeCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 0, 5, 0},
        {0, 8, 0, 6, 0},
        {0, 0, 0, 1, 0},
        {0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::hasNegativeCycle(g) == false); 

    vector<vector<int>> graph4 = {
        {0, 0, 0, -5, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {-5, 7, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::hasNegativeCycle(g) == true); 
}

TEST_CASE("Test all the checks in the graph"){

        ariel::Graph g;
 vector<vector<int>> graph = {
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true); 
    CHECK(ariel::Algorithms::hasNegativeCycle(g) == false); 
    CHECK(ariel::Algorithms::isBipartite(g) == "0"); 
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->3->1->0"); 
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->3->1"); 
}

