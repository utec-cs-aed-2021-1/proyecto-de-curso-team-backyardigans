#include "catch.hpp"
#include "Algorithms/Kruskal.h"

TEST_CASE("Kruskal::apply") {

    SECTION("Simple scenarios") {

        SECTION("Scenario 1") {
            UnDirectedGraph<double, int>g;
            g.insertVertex("A", 1);
            g.insertVertex("B", 2);
            g.insertVertex("C", 3);
            g.insertVertex("D", 10);

            g.createEdge("A", "B", 1);
            g.createEdge("C", "A", 2);
            g.createEdge("D", "C", 2);
            g.createEdge("D", "A", 3);

            Kruskal<double, int> kruskal(&g);
            UnDirectedGraph<double, int> result = kruskal.apply();
            result.display();

        }
        SECTION("Scenario 2") {
            UnDirectedGraph<double, int>g;

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);
            g.insertVertex("C", 3);
            g.insertVertex("D", 4);
            g.insertVertex("E", 5);
            g.insertVertex("F", 9);

            g.createEdge("A", "B", 2);
            g.createEdge("B", "C", 2);
            g.createEdge("C", "F", 8);
            g.createEdge("F", "E", 4);
            g.createEdge("A", "E", 5);
            g.createEdge("A", "D", 1);
            g.createEdge("D", "F", 3);

            Kruskal<double, int> kruskal(&g);
            UnDirectedGraph<double, int> result = kruskal.apply();
            result.display();

        }
    }
}
