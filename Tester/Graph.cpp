#include "catch.hpp"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

TEST_CASE( "Inserting vertices in a graph", "[Graph]" ) {
  
    SECTION( "Minimal tests" ) {
        DirectedGraph<double, int> dg = DirectedGraph<double, int>();
        UnDirectedGraph<double, int> ug = UnDirectedGraph<double, int>();
        
        SECTION( "No vertices" ) {
            
            SECTION( "Directed graph" ) {
                REQUIRE( dg.getNumberOfVertices() == 0 );
            }

            SECTION( "Undirected graph" ) {
                REQUIRE( ug.getNumberOfVertices() == 0 );
            }
        }

        SECTION( "1 vertex" ) {
            
            SECTION( "Directed graph" ) {
                dg.insertVertex("A", 1);
                REQUIRE( dg.getNumberOfVertices() == 1 );
            }

            SECTION( "Undirected graph" ) {
                ug.insertVertex("A", 1);
                REQUIRE( ug.getNumberOfVertices() == 1 );
            }
        }
    }

    SECTION( "Exhaustive tests" ) {
        DirectedGraph<double, int> dg = DirectedGraph<double, int>();
        UnDirectedGraph<double, int> ug = UnDirectedGraph<double, int>();
        
        SECTION( "A vertex for each character in the alphabet" ) {

            SECTION( "Directed  graph" ) {
                for(char i='a'; i<='z'; ++i)
                    dg.insertVertex(std::string(1, i), 10);
                REQUIRE( dg.getNumberOfVertices() == ('z' - 'a' + 1) );
            }

            SECTION( "Undirected  graph" ) {
                for(char i='a'; i<='z'; ++i)
                    ug.insertVertex(std::string(1, i), 10);
                REQUIRE( ug.getNumberOfVertices() == ('z' - 'a' + 1) );
            }
        }
    }
}
