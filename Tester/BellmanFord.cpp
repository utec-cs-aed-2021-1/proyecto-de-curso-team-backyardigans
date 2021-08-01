//
// Created by LENOVO on 31/07/2021.
//

#include "catch.hpp"
#include "Algorithms/BellmanFord.h"
TEST_CASE("BellmanFord::applyd") {

    SECTION("Simple scenarios") {

        SECTION("Scenario 1") {
            DirectedGraph<double, int>* g1 = new DirectedGraph<double, int>();

            g1->insertVertex("A", 1);
            g1->insertVertex("B", 1);
            g1->insertVertex("C", 1);
            g1->insertVertex("D", 1);

            g1->createEdge("A", "B", 3);
            g1->createEdge("A", "D", 6);
            g1->createEdge("B", "C", 2);
            g1->createEdge("D", "B", -4);
            g1->createEdge("C", "D", 3);

            BellmanFord<double ,int> fw(g1, "A", "C");
            DirectedGraph<double , int>* gr = fw.applyd();

            cout << "Bf: "<<endl;
            gr->display();
        }
    }
}