#include "catch.hpp"
#include "UndirectedGraph.h"
#include "Algorithms/DFS.h"

TEST_CASE( "Inserting vertices in an undirected graph", "[UnDirectedGraph]" ) {
  
    SECTION( "Minimal tests" ) {
        UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
        SECTION( "No vertices" ) {
            REQUIRE( g.getNumberOfVertices() == 0 );
        }
    
        SECTION( "A single vertex" ) {
            g.insertVertex("A", 1);
            REQUIRE( g.getNumberOfVertices() == 1 );
        }
	
        SECTION( "All characters in the alphabet" ) {
            for(char i='a'; i<='z'; ++i)
                g.insertVertex(std::string(1, i), 10);
            REQUIRE( g.getNumberOfVertices() == ('z' - 'a' + 1) );
        }
    }
}

TEST_CASE( "Inserting edges in an undirected graph", "[UnDirectedGraph]" ) {
  
    SECTION( "Minimal tests" ) {
    
        SECTION( "No edges" ) {
            UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();
            REQUIRE( g.getNumberOfEdges() == 0 );
        }
    
        SECTION( "1 edge" ) {
            UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 1);

            g.createEdge("A", "B", 1);
            
            REQUIRE( g.getNumberOfEdges() == 1 );
        }

        SECTION( "10 edges" ) {
            UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 1);

            for(int i=0; i<10; i++)
                g.createEdge("A", "B", 1);
            
            REQUIRE( g.getNumberOfEdges() == 10 );
        }
        
    }
}
