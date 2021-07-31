#include "catch.hpp"
#include "Algorithms/Dijkstra.h"

TEST_CASE("Dijkstra::apply") {

    SECTION("Simple scenarios"){

        SECTION("Scenario 1"){
            Graph<double, int>* g1 = new UnDirectedGraph<double, int>();

            g1->insertVertex("0", 0);
            g1->insertVertex("1", 1);
            g1->insertVertex("2", 2);
            g1->insertVertex("3", 3);
            g1->insertVertex("4", 4);
            g1->insertVertex("5", 5);
            g1->insertVertex("6", 6);
            g1->insertVertex("7", 7);

            g1->createEdge("0", "1", 9);
            g1->createEdge("0", "2", 5);
            g1->createEdge("1", "2", 4);
            g1->createEdge("1", "5", 4);
            g1->createEdge("1", "3", 6);
            g1->createEdge("3", "5", 3);
            g1->createEdge("3", "7", 1);
            g1->createEdge("2", "6", 6);
            g1->createEdge("2", "4", 5);

            Dijkstra<double ,int> dijs(g1, "1");

            DirectedGraph<double , int> gr = dijs.applyd();

            cout << "Dijkstra: "<<endl;
            //  gr.display();
        }

        SECTION("Escenario 2"){
            Graph<double, int>* g1 = new UnDirectedGraph<double, int>();

            g1->insertVertex("0", 0);
            g1->insertVertex("1", 1);
            g1->insertVertex("2", 2);
            g1->insertVertex("3", 3);
            g1->insertVertex("4", 4);
            g1->insertVertex("5", 5);
            g1->insertVertex("6", 6);
            g1->insertVertex("7", 7);

            g1->createEdge("0", "1", 6);
            g1->createEdge("1", "2", 2);
            g1->createEdge("2", "6", 4);
            g1->createEdge("5", "6", 8);
            g1->createEdge("6", "7", 1);
            g1->createEdge("5", "7", 2);
            g1->createEdge("5", "2", 6);
            g1->createEdge("6", "4", 7);

            Dijkstra<double ,int> dijs(g1, "6");


            UnDirectedGraph<double , int> gr = dijs.applyu();

            cout << "Dijkstra: "<<endl;
            gr.display();
        }
    }

}
