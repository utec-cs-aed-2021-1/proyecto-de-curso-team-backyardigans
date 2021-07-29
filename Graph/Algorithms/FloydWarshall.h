//
// Created by EDGAR on 18/07/2021.
//

#ifndef GRAPHS_FLOYDWARSHALL_H
#define GRAPHS_FLOYDWARSHALL_H
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"


template<typename TV, typename TE>
class DirectedGraph;

template<typename TV, typename TE>
class FloydWarshall{
protected:
    DirectedGraph<TV, TE>* graph;
    string vertex;
public:
    FloydWarshall(){};
    FloydWarshall(DirectedGraph<TV, TE>* graph_, string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    DirectedGraph<TV, TE>* applyd();
};

template<typename TV, typename TE>
DirectedGraph<TV,TE>* FloydWarshall<TV, TE>::applyd(){
    unordered_map<int, string> recognize;
    auto original_map = graph->getMap();
    auto V = graph->getNumberOfVertices();
    vector<vector<int>> dist;
    auto it = original_map.begin();
    for (int i=1; i<=V; i++){
        recognize[i] = (*it).first;
        it++;
    }
    for (int i = 0; i < V; i++){
        vector<int> v;
        for (int j = 0; j < V; j++){
            if (i==j) v.push_back(0);
            else v.push_back(INFINITY);
        }
        dist.push_back(v);
    }
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
           if (i != j){
               if (graph->findEdge(recognize[i], recognize[j])){
                   dist[i][j] = graph(recognize[i], recognize[j]);
               }
           }
        }
    }
    for (int k=1; k<V; k++){
        for (int j=1; j<V; j++){
            for (int i=1; i<V; i++){
                if (dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }


};




#endif //GRAPHS_FLOYDWARSHALL_H
