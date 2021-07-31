#include "catch.hpp"
#include "Algorithms/FloydWarshall.h"

TEST_CASE("FloydWarshall::applyd") {

    SECTION("Simple scenarios") {

        SECTION("Scenario 1") {
            Graph<double, int>* g1 = new UnDirectedGraph<double, int>();

            g1->insertVertex("1", 1);
            g1->insertVertex("2", 1);
            g1->insertVertex("3", 1);
            g1->insertVertex("4", 1);

            g1->createEdge("1", "2", 4);
            g1->createEdge("4", "2", -1);
            g1->createEdge("3", "4", 2);
            g1->createEdge("1", "3", -2);
            g1->createEdge("2", "3", 3);

            FloydWarshall<double ,int> fw (g1, "1");
            DirectedGraph<double , int>* gr = fw.applyd();

            cout << "Fw: "<<endl;
            gr->display();
        }
    }
}
