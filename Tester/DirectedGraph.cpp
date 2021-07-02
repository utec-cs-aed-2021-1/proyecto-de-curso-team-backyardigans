#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "Inserting vertices in a directed graph", "[DirectedGraph]" ) {
  
    SECTION( "Minimal tests" ) {
        DirectedGraph<double, int> g = DirectedGraph<double, int>();
        
        SECTION( "No vertices" ) {
            REQUIRE( g.getNumberOfVertices() == 0 );
        }
        
    }
}
