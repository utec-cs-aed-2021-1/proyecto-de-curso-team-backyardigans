#include "catch.hpp"
#include "Algorithms/Prim.h"

TEST_CASE( "A simple test for Prim" ) {

    SECTION("Grafo_1"){
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
        Prim<char, int> prim(&g1, "A");
        UnDirectedGraph<char, int> result = prim.apply();
        result.display();

    }

    SECTION("Grafo_2") {
        UnDirectedGraph<char, int>g1;
        g1.insertVertex("A", 1);
        g1.insertVertex("B", 2);
        g1.insertVertex("C", 3);
        g1.insertVertex("D", 4);
        g1.insertVertex("E", 5);
        g1.insertVertex("F", 6);
        g1.createEdge("A", "B", 6);
        g1.createEdge("A", "D", 5);
        g1.createEdge("A", "C", 1);
        g1.createEdge("B", "E", 3);
        g1.createEdge("C", "E", 6);
        g1.createEdge("C", "F", 4);
        g1.createEdge("D", "F", 2);
        g1.createEdge("E", "F", 6);
        g1.createEdge("B", "C", 5);
        g1.createEdge("D", "C", 5);

        Prim<char, int> prim(&g1, "F");
        UnDirectedGraph<char, int> result = prim.apply();
        result.display();


    }
}
