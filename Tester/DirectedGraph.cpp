#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE("DirectedGraph::getNumberOfEdges") {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();
    REQUIRE(g.getNumberOfEdges() == 0);
}

TEST_CASE("DirectedGraph::deleteVertex") {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);

    g.createEdge("A", "B", 1);
    g.createEdge("C", "A", 2);
    g.createEdge("D", "C", 2);
    g.createEdge("D", "A", 3);

    REQUIRE(g.deleteVertex("D") == true);
    REQUIRE(g.getNumberOfEdges() == 2);
}

TEST_CASE("DirectedGraph::findById") {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);

    g.createEdge("A", "B", 1);
    g.createEdge("C", "A", 2);
    g.createEdge("D", "C", 2);
    g.createEdge("D", "A", 3);

    g.deleteVertex("D");

    REQUIRE(g.findById("D") == false);
}

TEST_CASE("DirectedGraph::clear") {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);

    g.createEdge("A", "B", 1);
    g.createEdge("C", "A", 2);
    g.createEdge("D", "C", 2);
    g.createEdge("D", "A", 3);

    g.clear();

    REQUIRE(g.empty() == true);
    REQUIRE(g.getNumberOfEdges() == 0);
}

TEST_CASE("DirectedGraph::createEdge") {

    SECTION("Simple scenarios") {

        SECTION("1 edge") {
            DirectedGraph<double, int> g = DirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);

            g.createEdge("A", "B", 1);

            REQUIRE(g.getNumberOfEdges() == 1);
        }

        SECTION("2 edges") {
            DirectedGraph<double, int> g = DirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);

            g.createEdge("A", "B", 1);
            g.createEdge("B", "A", 1);

            REQUIRE(g.getNumberOfEdges() == 2);
        }
    }

    SECTION("Special scenarios") {

        SECTION("Insert existing edge") {
            DirectedGraph<double, int> g = DirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);

            g.createEdge("A", "B", 1);
            g.createEdge("A", "B", 1);

            REQUIRE(g.getNumberOfEdges() == 1);
        }
    }
}

TEST_CASE("DirectedGraph::isDense") {

    SECTION("Simple scenarios") {

        SECTION("must return true") {

            SECTION("Scenario 1") {
                DirectedGraph<double, int> g = DirectedGraph<double, int>();

                g.insertVertex("A", 1);
                g.insertVertex("B", 2);
                g.insertVertex("C", 3);
                g.insertVertex("D", 4);

                g.createEdge("A", "B", 1);
                g.createEdge("C", "A", 2);
                g.createEdge("D", "C", 2);
                g.createEdge("D", "A", 3);

                REQUIRE(g.isDense(0.33)  == true);
            }
        }
    }
}

TEST_CASE("DirectedGraph::isStronglyConnected") {

    SECTION("Simple scenarios") {

        SECTION("must return true") {

            SECTION("Scenario 1") {
                DirectedGraph<double, int> g = DirectedGraph<double, int>();

                g.insertVertex("A", 1);
                g.insertVertex("B", 2);
                g.insertVertex("C", 3);
                g.insertVertex("D", 4);

                g.createEdge("A", "B", 1);
                g.createEdge("B", "C", 2);
                g.createEdge("C", "D", 2);
                g.createEdge("D", "A", 3);

                REQUIRE(g.isStronglyConnected() == true);
            }
        }

        SECTION("must return false") {

            SECTION("Scenario 1") {
                DirectedGraph<double, int> g = DirectedGraph<double, int>();

                g.insertVertex("A", 1);
                g.insertVertex("B", 2);
                g.insertVertex("C", 3);
                g.insertVertex("D", 4);

                g.createEdge("A", "B", 1);
                g.createEdge("C", "A", 2);
                g.createEdge("D", "C", 2);
                g.createEdge("D", "A", 3);

                REQUIRE(g.isStronglyConnected() == false);
            }

            SECTION("Scenario 2") {
                DirectedGraph<double, int> g = DirectedGraph<double, int>();

                g.insertVertex("A", 1);
                g.insertVertex("B", 2);
                g.insertVertex("C", 3);
                g.insertVertex("D", 4);
                g.insertVertex("E", 5);
                g.insertVertex("F", 6);

                g.createEdge("A", "B", 1);
                g.createEdge("A", "F", 2);
                g.createEdge("A", "C", 2);
                g.createEdge("F", "B", 3);
                g.createEdge("F", "C", 1);
                g.createEdge("B", "C", 2);
                g.createEdge("E", "B", 2);
                g.createEdge("E", "C", 3);
                g.createEdge("F", "E", 1);
                g.createEdge("E", "D", 2);
                g.createEdge("D", "C", 2);

                REQUIRE(g.isStronglyConnected() == false);
            }
        }
    }
}
