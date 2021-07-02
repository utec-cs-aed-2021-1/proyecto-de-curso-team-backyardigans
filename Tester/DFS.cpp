#include "catch.hpp"
#include "Algorithms/DFS.h"

TEST_CASE( "A simple test for DFS" ) {
    REQUIRE( 1 == 1 );
    Graph<double, int>* g = new UnDirectedGraph<double, int>();
    g->insertVertex("A", 1);
    g->insertVertex("B", 1);
    g->insertVertex("C", 1);
    g->insertVertex("D", 1);
    g->insertVertex("E", 1);
    g->insertVertex("F", 1);
    REQUIRE( g->getNumberOfVertices() == 6);

    SECTION( "Edges creation" ) {
        Graph<double, int>* g1 = new UnDirectedGraph<double, int>();
        g1->insertVertex("A", 1);
        g1->insertVertex("B", 1);
        g1->insertVertex("C", 1);
        g1->insertVertex("D", 1);
        g1->insertVertex("E", 1);
        g1->insertVertex("F", 1);
        g1->createEdge("A", "B", 2);
        g1->createEdge("A", "C", 2);
        g1->createEdge("A", "D", 2);
        g1->createEdge("D", "E", 2);
        g1->createEdge("B", "F", 2);
        g1->createEdge("F", "C", 2);
        g1->createEdge("C", "E", 2);
        g1->display();
        DFS<double ,int> dfs(g1, "A");
        DirectedGraph<double , int>* gr = dfs.apply();
        gr->display();
        REQUIRE( g1->getNumberOfEdges() == 7);
    }
}

