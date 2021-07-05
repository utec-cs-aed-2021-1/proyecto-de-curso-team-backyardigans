#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "A simple test for DirectedGraph", "[DirectedGraph]" ) {

    SECTION("Minimal Tests"){
        SECTION( "No edges" ) {
            DirectedGraph<double, int> g = DirectedGraph<double, int>();
            REQUIRE( g.getNumberOfEdges() == 0 );
        }
        SECTION( " Delete vertex" ) {
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


        SECTION( "Is Strongly Connected" ) {
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
        SECTION( "Is Strongly Connected" ) {
            DirectedGraph<double, int> g = DirectedGraph<double, int>();
//ga
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

        SECTION( "density" ) {
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


    }

}
