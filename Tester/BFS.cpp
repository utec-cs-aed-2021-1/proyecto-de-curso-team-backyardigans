#include "catch.hpp"
#include "Algorithms/BFS.h"
#include "UndirectedGraph.h"

TEST_CASE("BFS::apply") {

    SECTION("Simple scenarios") {

        SECTION("Scenario 1") {

            Graph<double, int>* g1 = new UndirectedGraph<double, int>();

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

            BFS<double ,int> bfs(g1, "A");
            DirectedGraph<double , int>* gr = bfs.apply();

            cout << "BFS: "<<endl;
            g1->display();
        }

        SECTION("Escenario 2") {
            Graph<double, int>* g1 = new UndirectedGraph<double, int>();

            g1->insertVertex("A", 1);
            g1->insertVertex("B", 1);
            g1->insertVertex("C", 1);
            g1->insertVertex("D", 1);

            g1->createEdge("A", "C", 4);
            g1->createEdge("C", "D", 3);
            g1->createEdge("A", "D", 10);

            BFS<double ,int> bfs(g1, "C");
            DirectedGraph<double , int>* gr = bfs.apply();

            cout << "BFS: "<<endl;
            gr->display();
        }
    }
}
