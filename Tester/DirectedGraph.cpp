#include "catch.hpp"
#include "DirectedGraph.h"

TEST_CASE( "A simple test for DirectedGraph", "[DirectedGraph]" ) {
    REQUIRE( 1 == 1 );
    DirectedGraph<double,int> graph_d1;
    graph_d1 = DirectedGraph<double,int>() ;
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

    cout<<"*createEdge(A,B, 1): "<<endl;

    if(graph_d1.createEdge("A","B", 1)){
        cout<<"Edge A-B created correctly "<<endl;
    }
    else{
        cout<<"Edge has not been created"<<endl;
    }

    cout<<"*createEdge(C,B, 1): "<<endl;

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

    cout << "directed"<<endl;
    graph_d1.display();
}
