#include "catch.hpp"
#include <math.h>
#include "UndirectedGraph.h"

TEST_CASE("UndirectedGraph (constructor)") {

    SECTION("Special scenarios") {

        SECTION("An empty undirected graph") {
            UndirectedGraph<double, int> ug = UndirectedGraph<double, int>();
            REQUIRE( ug.getNumberOfVertices() == 0 );
            REQUIRE( ug.getNumberOfEdges() == 0 );
        }
    }
}

TEST_CASE("UndirectedGraph::getNumberOfEdges") {
    UndirectedGraph<double, int> g = UndirectedGraph<double, int>();
    REQUIRE( g.getNumberOfEdges() == 0 );
}

TEST_CASE("UndirectedGraph::createEdge") {
    UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

    SECTION("A graph with a single vertex") {
        g.insertVertex("A", 1);
        g.insertVertex("B", 1);

        g.createEdge("A", "B", 1);

        REQUIRE( g.getNumberOfEdges() == 1 );
    }

    SECTION("A graph with a single vertex which was added multiple times") {
        g.insertVertex("A", 1);
        g.insertVertex("B", 1);

        for(int i=0; i<10; i++)
            g.createEdge("A", "B", 1);

        REQUIRE( g.getNumberOfEdges() == 1 );
    }
}

TEST_CASE("UndirectedGraph::deleteVertex") {
    UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);
    g.insertVertex("E", 5);

    g.createEdge("A", "B", 1);
    g.createEdge("B", "C", 2);
    g.createEdge("B", "E", 2);
    g.createEdge("B", "D", 3);
    g.createEdge("A", "E", 1);
    g.createEdge("D", "C", 2);
    g.createEdge("E", "D", 2);

    g.deleteVertex("D");

    REQUIRE( g.getNumberOfEdges() == 4 );
}

TEST_CASE("UndirectedGraph::findById") {
    UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);
    g.insertVertex("E", 5);


    g.createEdge("A", "B", 1);
    g.createEdge("B", "C", 2);
    g.createEdge("B", "E", 2);
    g.createEdge("B", "D", 3);
    g.createEdge("A", "E", 1);
    g.createEdge("D", "C", 2);
    g.createEdge("E", "D", 2);

    g.deleteVertex("D");

    REQUIRE( g.findById("D") == false);
    g.display();
}

TEST_CASE("UndirectedGraph::empty") {
    UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);
    g.insertVertex("E", 5);


    g.createEdge("A", "B", 1);
    g.createEdge("B", "C", 2);
    g.createEdge("B", "E", 2);
    g.createEdge("B", "D", 3);
    g.createEdge("A", "E", 1);
    g.createEdge("D", "C", 2);
    g.createEdge("E", "D", 2);

    REQUIRE( g.empty() == false );
    g.clear();
    REQUIRE( g.empty() == true );
}

TEST_CASE("UndirectedGraph::isConnected") {

    SECTION("must return false") {

        SECTION("Escenario 1") {
            UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);
            g.insertVertex("C", 3);
            g.insertVertex("D", 4);
            g.insertVertex("E", 5);

            g.createEdge("A", "B", 1);
            g.createEdge("B", "C", 2);
            g.createEdge("B", "E", 2);
            g.createEdge("B", "D", 3);
            g.createEdge("A", "E", 1);
            g.createEdge("D", "C", 2);
            g.createEdge("E", "D", 2);

            g.deleteEdge("A","B");
            g.deleteEdge("A","E");

            REQUIRE( g.isConnected() == false );

        }
    }
}

TEST_CASE("UndirectedGraph::isDense")  {

    SECTION("must return true") {

        SECTION("Escenario 1") {
            UndirectedGraph<double, int> g = UndirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 2);
            g.insertVertex("C", 3);
            g.insertVertex("D", 4);
            g.insertVertex("E", 5);

            g.createEdge("A", "B", 1);
            g.createEdge("B", "C", 2);
            g.createEdge("B", "E", 2);
            g.createEdge("B", "D", 3);
            g.createEdge("A", "E", 1);
            g.createEdge("D", "C", 2);
            g.createEdge("E", "D", 2);

            REQUIRE(g.isDense() == true);
        }
    }
}
