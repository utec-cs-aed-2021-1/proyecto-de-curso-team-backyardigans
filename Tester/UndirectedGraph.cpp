#include "catch.hpp"
#include "UndirectedGraph.h"
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
        SECTION( "create equal edges " ) {
            UnDirectedGraph<double, int> g = UnDirectedGraph<double, int>();

            g.insertVertex("A", 1);
            g.insertVertex("B", 1);

            for(int i=0; i<10; i++)
                g.createEdge("A", "B", 1);

            REQUIRE( g.getNumberOfEdges() == 1 );
        }
        SECTION( " Delete vertex" ) {
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
        SECTION( " Find " ) {
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
        }
        SECTION( "Clear and empty" ) {
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
            REQUIRE(g.getNumberOfEdges()==0);
        }

        SECTION( "Is connected" ) {
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

        SECTION( "density" ) {
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

            REQUIRE( g.density() == 0.7 );
        }
    }
}
