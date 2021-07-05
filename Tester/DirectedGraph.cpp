#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "Get the number of edges in a directed graph", "[DirectedGraph][getNumberOfEdges]" ) {
  DirectedGraph<double, int> g = DirectedGraph<double, int>();
  REQUIRE( g.getNumberOfEdges() == 0 );
}

TEST_CASE( "Delete vertex", "[DirectedGraph][ ) {
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

SECTION( " Find " ) {
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
SECTION( "Clear and empty" ) {
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
  REQUIRE(g.getNumberOfEdges()==0);
}


TEST_CASE( "" ) {
  DirectedGraph<double, int> g = DirectedGraph<double, int>();

  g.insertVertex("A", 1);
  g.insertVertex("B", 2);
  g.insertVertex("C", 3);
  g.insertVertex("D", 4);

  g.createEdge("A", "B", 1);
  g.createEdge("C", "A", 2);
  g.createEdge("D", "C", 2);
  g.createEdge("D", "A", 3);

  REQUIRE( g.isDense(0.33)  == true);
}


TEST_CASE( "Check directed graph is strongly connected", "[DirectedGraph][isStronglyConnected]" ) {

  SECTION( "Direected graph is not strongly connected" ) {
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
  
  SECTION( "Directed graph is strongly connected" ) {
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
