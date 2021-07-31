#include "catch.hpp"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

TEST_CASE("Graph::insertVertex") {

    SECTION("Simple scenarios") {

        SECTION("1 vertex") {

            SECTION("Directed graph") {
                DirectedGraph<double, int> dg = DirectedGraph<double, int>();
                dg.insertVertex("A", 1);
                REQUIRE( dg.getNumberOfVertices() == 1 );
            }

            SECTION("Undirected graph") {
                UndirectedGraph<double, int> ug = UndirectedGraph<double, int>();
                ug.insertVertex("A", 1);
                REQUIRE( ug.getNumberOfVertices() == 1 );
            }
        }
    }

    SECTION("Exhaustive scenarios") {

        SECTION("A vertex for each character in the alphabet") {

            SECTION("Directed graph") {
                DirectedGraph<double, int> dg = DirectedGraph<double, int>();

                for(char i='a'; i<='z'; ++i)
                    dg.insertVertex(std::string(1, i), 10);

                REQUIRE( dg.getNumberOfVertices() == ('z' - 'a' + 1) );
            }

            SECTION("Undirected graph") {
                UndirectedGraph<double, int> ug = UndirectedGraph<double, int>();

                for(char i='a'; i<='z'; ++i)
                    ug.insertVertex(std::string(1, i), 10);

                REQUIRE( ug.getNumberOfVertices() == ('z' - 'a' + 1) );
            }
        }
    }
}
