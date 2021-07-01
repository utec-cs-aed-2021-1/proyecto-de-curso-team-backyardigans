//
// Created by EDGAR on 29/06/2021.
//

#ifndef PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_TESTER_H
#define PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_TESTER_H
#include <iostream>
#include "UndirectedGraph.h"
using namespace std;
void test_undirected_graph(){

    UnDirectedGraph<double,int> graph_u1;
    graph_u1 = UnDirectedGraph<double,int>();

    graph_u1.insertVertex("A",1);
    graph_u1.insertVertex("B",2);
    graph_u1.insertVertex("C",3);
    graph_u1.insertVertex("D",4);

    graph_u1.createEdge("A","B", 1);
    graph_u1.createEdge("C","B", 2);
    graph_u1.createEdge("D","B", 4);
    graph_u1.createEdge("A","D", 1);

    graph_u1.display();

    graph_u1.deleteVertex("A");

    graph_u1.display();

    graph_u1.deleteEdge("C","B");


    graph_u1.display();

    cout << graph_u1.density();

    cout << graph_u1.isDense(0.5);

    graph_u1.isConnected();

    graph_u1.isStronglyConnected();

    graph_u1.empty();

    graph_u1.displayVertex("B");

    graph_u1.findById("E");

    cout<<"graph_u1_lleno:\n";
    graph_u1.display();

    graph_u1.clear();

    cout<<"graph_u1_vacio:\n";
    graph_u1.display();

};



#endif //PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_TESTER_H
