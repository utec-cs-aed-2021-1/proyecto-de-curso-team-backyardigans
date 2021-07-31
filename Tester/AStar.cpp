#include "catch.hpp"
#include "Algorithms/AStar.h"
#include "UndirectedGraph.h"

TEST_CASE("Astar::apply") {

    SECTION("Simple scenarios") {

        SECTION("Scenario 1") {
            Graph<double, int>* g1 = new UnDirectedGraph<double, int>();

            g1 -> insertVertex("AR", 1);
            g1 -> insertVertex("BUC", 1);
            g1 -> insertVertex("ZER", 1);
            g1 -> insertVertex("ORA", 1);
            g1 -> insertVertex("TIM", 1);
            g1 -> insertVertex("LUG", 1);
            g1 -> insertVertex("MEH", 1);
            g1 -> insertVertex("DOB", 1);
            g1 -> insertVertex("CRA", 1);
            g1 -> insertVertex("RIM", 1);
            g1 -> insertVertex("SIB", 1);
            g1 -> insertVertex("FAG", 1);
            g1 -> insertVertex("PIT", 1);

            g1 -> createEdge("AR", "ZER", 75);
            g1 -> createEdge("AR", "TIM", 118);
            g1 -> createEdge("AR", "SIB", 140);
            g1 -> createEdge("BUC", "PIT", 101);
            g1 -> createEdge("BUC", "FAG", 211);
            g1 -> createEdge("ZER", "ORA", 71);
            g1 -> createEdge("ORA", "SIB", 151);
            g1 -> createEdge("TIM", "LUG", 111);
            g1 -> createEdge("LUG", "MEH", 70);
            g1 -> createEdge("MEH", "DOB", 242);
            g1 -> createEdge("CRA", "PIT", 138);
            g1 -> createEdge("CRA", "RIM", 138);
            g1 -> createEdge("RIM", "SIB", 80);
            g1 -> createEdge("RIM", "PIT", 97);
            g1 -> createEdge("SIB", "FAG", 99);

            vector<pair<string, int>> h = {
                {"AR", 366},
                {"BUC", 0},
                {"ZER", 374},
                {"ORA", 380},
                {"TIM", 329},
                {"LUG", 244},
                {"MEH", 241},
                {"DOB", 242},
                {"CRA", 160},
                {"RIM", 193},
                {"SIB", 253},
                {"FAG", 178},
                {"PIT", 98}
            };

            Astar<double, int> astar(g1, "AR", "BUC", h);

            DirectedGraph<double, int>* gr = astar.apply();

            cout << "Greedy: "<<endl;
            gr -> display();
        }
    }
}
