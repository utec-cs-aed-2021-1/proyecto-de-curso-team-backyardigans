#ifndef PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_TESTER_H
#define PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_TESTER_

#include "DirectedGraph.h"
#include "UndirectedGraph.h"
using namespace std;
void test_directed_graph(){

    DirectedGraph<double,int> graph_d1;
    graph_d1 = DirectedGraph<double,int>() ;

    cout<<"*insertVertex(\"A\",1): "<<endl;

    if(graph_d1.insertVertex("A",1)){
        cout<<"vertex A inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"B\",2): "<<endl;

    if(graph_d1.insertVertex("B",2)){
        cout<<"vertex B inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"C\",3): "<<endl;

    if(graph_d1.insertVertex("C",3)){
        cout<<"vertex C inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"D\",4): "<<endl;

    if(graph_d1.insertVertex("D",4)){
        cout<<"vertex D inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*createEdge(\"A\",\"B\", 4): "<<endl;

    if(graph_d1.createEdge("A","B", 1)){
        cout<<"Edge A-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"C\",\"B\", 4): "<<endl;

    if(graph_d1.createEdge("C","B", 1)){
        cout<<"Edge C-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"D\",\"B\", 4): "<<endl;

    if(graph_d1.createEdge("D","B", 4)){
        cout<<"Edge D-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"A\",\"D\", 1): "<<endl;

    if(graph_d1.createEdge("A","D", 1)){
        cout<<"Edge A-D created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*deleteVertex(\"A\"): "<<endl;

    if(graph_d1.deleteVertex("A")){
        cout<<"vertex 'A' has been removed"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*deleteEdge(\"C\",\"B\"): "<<endl;

    if(graph_d1.deleteEdge("C","B")){
        cout<<"Edge 'C-B' has been removed"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*The density of graph is: "<<graph_d1.density()<<endl;

    cout<<"*isDense(0.5): "<<endl;

    if(graph_d1.isDense(0.5)){
        cout<<"The graph is dense"<<endl;
    }
    else{
        cout<<"The graph is not dense"<<endl;
    }

    cout<<"*isConnected(): "<<endl;

    if(graph_d1.isConnected()){
        cout<<"The graph is connected"<<endl;
    }
    else{
        cout<<"The graph is not connected"<<endl;
    }

    cout<<"*isStronglyConnected(): "<<endl;

    if(graph_d1.isStronglyConnected()){
        cout<<"The graph is Strongl and Connected"<<endl;
    }
    else{
        cout<<"The graph is not Strongl and is not Connected"<<endl;
    }

    cout<<"*empty(): "<<endl;

    if(graph_d1.empty()){
        cout<<"The graph is empty"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    graph_d1.displayVertex("B");


    if(graph_d1.findById("E")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*graph_u1:\n";
    graph_d1.display();

    graph_d1.clear();


    if(graph_d1.insertVertex("E",5)and graph_d1.insertVertex("F",6)){
        cout<<"vertices inserted correctly"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    if(graph_d1.createEdge("E","B", 1) and graph_d1.insertVertex("B",2)){
        cout<<"vertices inserted correctly"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

};


void test_undirected_graph(){

    UnDirectedGraph<double,int> graph_u1;
    graph_u1 = UnDirectedGraph<double,int>();

    cout<<"*insertVertex(\"A\",1): "<<endl;

    if(graph_u1.insertVertex("A",1)){
        cout<<"vertex A inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"B\",2): "<<endl;

    if(graph_u1.insertVertex("B",2)){
        cout<<"vertex B inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"C\",3): "<<endl;

    if(graph_u1.insertVertex("C",3)){
        cout<<"vertex C inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*insertVertex(\"D\",4): "<<endl;

    if(graph_u1.insertVertex("D",4)){
        cout<<"vertex D inserted correctly"<<endl;
    }
    else{
        cout<<"vertex has not been inserted"<<endl;
    }

    cout<<"*createEdge(\"A\",\"B\", 4): "<<endl;

    if(graph_u1.createEdge("A","B", 1)){
        cout<<"Edge A-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"C\",\"B\", 4): "<<endl;

    if(graph_u1.createEdge("C","B", 1)){
        cout<<"Edge C-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"D\",\"B\", 4): "<<endl;

    if(graph_u1.createEdge("D","B", 4)){
        cout<<"Edge D-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(\"A\",\"D\", 1): "<<endl;

    if(graph_u1.createEdge("A","D", 1)){
        cout<<"Edge A-D created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*deleteVertex(\"A\"): "<<endl;

    if(graph_u1.deleteVertex("A")){
        cout<<"vertex 'A' has been removed"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*deleteEdge(\"C\",\"B\"): "<<endl;

    if(graph_u1.deleteEdge("C","B")){
        cout<<"Edge 'C-B' has been removed"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*The density of graph is: "<<graph_u1.density()<<endl;

    cout<<"*isDense(0.5): "<<endl;

    if(graph_u1.isDense(0.5)){
        cout<<"The graph is dense"<<endl;
    }
    else{
        cout<<"The graph is not dense"<<endl;
    }

    cout<<"*isConnected(): "<<endl;

    if(graph_u1.isConnected()){
        cout<<"The graph is connected"<<endl;
    }
    else{
        cout<<"The graph is not connected"<<endl;
    }

    cout<<"*isStronglyConnected(): "<<endl;

    if(graph_u1.isStronglyConnected()){
        cout<<"The graph is Strongl and Connected"<<endl;
    }
    else{
        cout<<"The graph is not Strongl and is not Connected"<<endl;
    }

    cout<<"*empty(): "<<endl;

    if(graph_u1.empty()){
        cout<<"The graph is empty"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    graph_u1.displayVertex("B");


    if(graph_u1.findById("E")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"*graph_u1:\n";
    graph_u1.display();

    graph_u1.clear();


    if(graph_u1.insertVertex("E",5)and graph_u1.insertVertex("F",6)){
        cout<<"vertices inserted correctly"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    if(graph_u1.createEdge("E","B", 1) and graph_u1.insertVertex("B",2)){
        cout<<"vertices inserted correctly"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }
    graph_u1.displayVertex("F");

    if(graph_u1.findById("B")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    graph_u1.display();

    graph_u1.clear();

    if(graph_u1.empty()){
        cout<<"The graph is empty"<<endl;
    }
    else{
        cout<<"An error has occurred"<<endl;
    }

    cout<<"graph_u1:\n";
    graph_u1.display();

};                   





#define PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_MAIN_TESTER_H
#endif //PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_MAIN_TESTER_H
