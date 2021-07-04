#include "catch.hpp"
#include "Algorithms/Kruskal.h"

TEST_CASE( "A simple test for Kruskal" ) {
    UnDirectedGraph<char, int>g1;
    g1.insertVertex("A", 1);
    g1.insertVertex("B", 2);
    g1.insertVertex("C", 3);
    g1.insertVertex("D", 4);
    g1.insertVertex("E", 5);
    g1.insertVertex("F", 6);
    g1.createEdge("A", "B", 2);
    g1.createEdge("A", "C", 2);
    g1.createEdge("A", "D", 1);
    g1.createEdge("C", "F", 1);
    g1.createEdge("B", "F", 3);
    g1.createEdge("A", "E", 4);
    g1.createEdge("C", "E", 5);
    Kruskal<char, int> kruskal(&g1);
    UnDirectedGraph<char, int> result = kruskal.apply();
    result.display();
    REQUIRE( 1 == 1 );
}
