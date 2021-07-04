#include "catch.hpp"
#include "Algorithms/Kruskal.h"

TEST_CASE( "A simple test for Kruskal" ) {
    SECTION("Grafo_1"){
        UnDirectedGraph<char, int>g;
        g.insertVertex("A", 1);
        g.insertVertex("B", 2);
        g.insertVertex("C", 3);
        g.insertVertex("D", 4);

        g.createEdge("A", "B", 1);
        g.createEdge("C", "A", 2);
        g.createEdge("D", "C", 2);
        g.createEdge("D", "A", 3);

        Kruskal<char, int> kruskal(&g);
        UnDirectedGraph<char, int> result = kruskal.apply();
        result.display();

    }
    SECTION("Grafo_2"){
        UnDirectedGraph<char, int>g;
        g.insertVertex("A", 1);
        g.insertVertex("B", 2);
        g.insertVertex("C", 3);
        g.insertVertex("D", 4);
        g.insertVertex("E", 5);
        g.insertVertex("F", 6);

        g.createEdge("A", "B", 2);
        g.createEdge("B", "C", 2);
        g.createEdge("C", "F", 8);
        g.createEdge("F", "E", 4);
        g.createEdge("A", "E", 5);
        g.createEdge("A", "D", 1);
        g.createEdge("D", "F", 3);

        Kruskal<char, int> kruskal(&g);
        UnDirectedGraph<char, int> result = kruskal.apply();
        result.display();

    }

}
