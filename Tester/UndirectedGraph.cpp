#include "catch.hpp"
#include <math.h>
#include "UndirectedGraph.h"

TEST_CASE( "No edges in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
    REQUIRE( g.getNumberOfEdges() == 0 );
}

TEST_CASE( "1 edge in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 1);

    g.createEdge("A", "B", 1);

    REQUIRE( g.getNumberOfEdges() == 1 );
}

TEST_CASE( "create equal edges in Undirected " ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 1);

    for(int i=0; i<10; i++)
        g.createEdge("A", "B", 1);

    REQUIRE( g.getNumberOfEdges() == 1 );
}

TEST_CASE( " Delete vertex in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

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

TEST_CASE( " Find  in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

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

TEST_CASE( "Clear and empty in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

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

    g.clear();

    REQUIRE( g.empty() == true );

}

TEST_CASE( "Is connected in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

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

TEST_CASE( "density in Undirected" ) {
    UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

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

    REQUIRE(g.isDense(g.density()) == false);
}

