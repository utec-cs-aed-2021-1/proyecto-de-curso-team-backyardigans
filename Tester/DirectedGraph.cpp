#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "Get the number of edges in a directed graph", "[DirectedGraph][getNumberOfEdges]" ) {
  DirectedGraph<double, int> g = DirectedGraph<double, int>();
  REQUIRE( g.getNumberOfEdges() == 0 );
}

TEST_CASE( "Delete vertex in directed graph", "[DirectedGraph][deleteVertex]" ) {
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
  REQUIRE( g.getNumberOfEdges() == 2 );
}

TEST_CASE( "Find vertex by id in directed graph", "[DirectedGraph][findById]" ) {
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

  REQUIRE( g.findById("D") == false);
}

TEST_CASE( "Check emptiness of directed graph", "[DirectedGraph][empty]" ) {
  DirectedGraph<double, int> g = DirectedGraph<double, int>();

  SECTION("Empty graph") {
    REQUIRE( g.empty() == true );
  }
  
  SECTION("Not empty graph") {
    g.insertVertex("A", 1);
    REQUIRE( g.empty() == false );
  }
}

TEST_CASE( "Clear directed graph", "[DirectedGraph][clear]" ) {
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

  REQUIRE( g.empty() == true );
  REQUIRE( g.getNumberOfEdges() == 0 );
}

TEST_CASE( "Check directed graph is dense", "[DirectedGraph][isDense]" ) {
  DirectedGraph<double, int> g = DirectedGraph<double, int>();

  g.insertVertex("A", 1);
  g.insertVertex("B", 2);
  g.insertVertex("C", 3);
  g.insertVertex("D", 4);

  g.createEdge("A", "B", 1);
  g.createEdge("C", "A", 2);
  g.createEdge("D", "C", 2);
  g.createEdge("D", "A", 3);

  REQUIRE( g.isDense(0.33)  == true );
}


TEST_CASE( "Check directed graph is strongly connected", "[DirectedGraph][isStronglyConnected]" ) {

  SECTION( "Not strongly connected" ) {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();

    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);

    g.createEdge("A", "B", 1);
    g.createEdge("C", "A", 2);
    g.createEdge("D", "C", 2);
    g.createEdge("D", "A", 3);

    REQUIRE( g.isStronglyConnected() == false );
  }
  
  SECTION( "Strongly connected" ) {
    DirectedGraph<double, int> g = DirectedGraph<double, int>();
	    
    g.insertVertex("A", 1);
    g.insertVertex("B", 2);
    g.insertVertex("C", 3);
    g.insertVertex("D", 4);

    g.createEdge("A", "B", 1);
    g.createEdge("B", "C", 2);
    g.createEdge("C", "D", 2);
    g.createEdge("D", "A", 3);

    REQUIRE( g.isStronglyConnected() == true);
  }
  
}
