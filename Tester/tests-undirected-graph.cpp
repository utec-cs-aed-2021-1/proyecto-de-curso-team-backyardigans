#include "catch.hpp"
#include "UndirectedGraph.h"

TEST_CASE( "Inserting vertices in an undirected graph", "[UnDirectedGraph]" ) {

  SECTION( "Minimal tests" ) {

    SECTION( "No vertices" ){

      UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
      REQUIRE( g.getNumberOfVertices() == 0 );
      
    }
    
    SECTION( "A single vertex" ){

      UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
      g.insertVertex("A", 1);
      REQUIRE( g.getNumberOfVertices() == 1 );
      
    }
    
    SECTION( "All characters in the alphabet" ){
      
      UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
      for(char i='a'; i<='z'; ++i)
	g.insertVertex(i, 10);
      
      REQUIRE( g.getNumberOfVertices() == ('z' - 'a' + 1) );
      
    }
    
  }
  
}
