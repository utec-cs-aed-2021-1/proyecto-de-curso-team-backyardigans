#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "A simple test for DirectedGraph", "[DirectedGraph]" ) {
    DirectedGraph<double,int> graph_d1;

    graph_d1 = DirectedGraph<double,int>();

    REQUIRE(graph_d1.insertVertex("A",1)==true);

    REQUIRE(graph_d1.insertVertex("B",2)==true);

    REQUIRE(graph_d1.insertVertex("C",3)==true);

    REQUIRE(graph_d1.insertVertex("D",4)==true);

    REQUIRE(graph_d1.createEdge("A","B", 1)==true);

    REQUIRE(graph_d1.createEdge("C","B", 1)==true);

    REQUIRE(graph_d1.createEdge("D","B", 4) == true);

    cout << endl;
    cout << "Directed Graph: "<<endl;
    graph_d1.display();

    graph_d1.displayVertex("A");
}
