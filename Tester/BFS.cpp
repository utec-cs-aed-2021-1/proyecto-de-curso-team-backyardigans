#include "catch.hpp"
#include "Algorithms/BFS.h"

TEST_CASE( "A simple test for BFS" ) {
    REQUIRE( 1 == 1 );
    SECTION( "Edges creation" ) {
        Graph<double, int>* g1 = new UnDirectedGraph<double, int>();
        g1->insertVertex("A", 1);
        g1->insertVertex("B", 1);
        g1->insertVertex("C", 1);
        g1->insertVertex("D", 1);
        g1->insertVertex("E", 1);
        g1->insertVertex("F", 1);
        g1->createEdge("A", "B", 2);
        g1->createEdge("A", "C", 2);
        g1->createEdge("A", "D", 2);
        g1->createEdge("D", "E", 2);
        g1->createEdge("B", "F", 2);
        g1->createEdge("F", "C", 2);
        g1->createEdge("C", "E", 2);
        g1->display();
        BFS<double ,int> bfs(g1, "A");
        DirectedGraph<double , int>* gr = bfs.apply();
        cout << "BFS: "<<endl;
        gr->display();
        cout << endl;
    }
}
