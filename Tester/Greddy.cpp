#include "catch.hpp"
#include "Algorithms/Greedy.h"
#include "UndirectedGraph.h"

TEST_CASE( "GBFS", "[GBFS]" ) {
    SECTION( "Minimal working examples" ) {
        SECTION( "Example 1" ) {
            Graph<double, int>* g1 = new UnDirectedGraph<double, int>();

            g1->insertVertex("A", 1);
            g1->insertVertex("B", 1);
            g1->insertVertex("C", 1);
            g1->insertVertex("D", 1);
            g1->insertVertex("E", 1);
            g1->insertVertex("F", 1);
            g1->insertVertex("G", 1);
            g1->insertVertex("H", 1);

            g1->createEdge("A", "C", 2);
            g1->createEdge("C", "F", 2);
            g1->createEdge("A", "F", 2);
            g1->createEdge("C", "D", 2);
            g1->createEdge("F", "G", 2);
            g1->createEdge("D", "G", 2);
            g1->createEdge("C", "G", 2);
            g1->createEdge("D", "E", 2);
            g1->createEdge("G", "E", 2);
            g1->createEdge("E", "H", 2);
            g1->createEdge("G", "H", 2);
            g1->createEdge("E", "B", 2);
            g1->createEdge("H", "B", 2);

            vector<pair<string, int>>h={{"A",2},{"B",0},{"C",4},{"D",3},{"E",3},{"F",2},{"G",8},{"H",3}};
            Greedy<double ,int> greedy(g1, "A","B",h);
            DirectedGraph<double , int>* gr = greedy.apply();

            cout << "Greedy: "<<endl;
            gr->display();
        }
    }
}

