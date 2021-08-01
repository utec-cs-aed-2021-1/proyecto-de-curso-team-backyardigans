//
// Created by EDGAR on 18/07/2021.
//

#ifndef GRAPHS_FLOYDWARSHALL_H
#define GRAPHS_FLOYDWARSHALL_H
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"
#define MAX_INFINITY 99999

template<typename TV, typename TE>
class DirectedGraph;

template<typename TV, typename TE>
class FloydWarshall{
protected:
    DirectedGraph<TV, TE>* graph;
public:
    FloydWarshall(){};
    FloydWarshall(DirectedGraph<TV, TE>* graph_){
        graph = graph_;
    }
    DirectedGraph<TV, TE> applyd();
};

template<typename TV, typename TE>
DirectedGraph<TV,TE> FloydWarshall<TV, TE>::applyd(){
    DirectedGraph<TV, TE> gfloyd;
    unordered_map<int, string> recognize;
    auto original_map = graph->getMap();
    auto V = graph->getNumberOfVertices();
    vector<vector<TE>> dist;
    vector<vector<int>> recorr;
    unordered_map<string, bool> connected;
    auto it = original_map.begin();
    for (int i=1; i<=V; i++){
        gfloyd.insertVertex((*it).first, (*it).second->data);
        recognize[i] = (*it).first;
        cout <<"value_original: "<<(*it).first  << " -matrix_value: "<<i << endl;
        it++;
    }
    for (int i = 0; i <= V; i++){
        vector<TE> d;
        vector<int> r;
        for (int j = 0; j <= V; j++){
            if (i==j) {
                d.push_back(0);
                r.push_back(0);
            }
            else {
                d.push_back(MAX_INFINITY);
                r.push_back(j);
            }
        }
        recorr.push_back(r);
        dist.push_back(d);
    }
    for (int i = 1; i <= V; i++){
        for (int j = 1; j <= V; j++){
           if (i != j){
               if (graph->findEdge(recognize[i], recognize[j])){
                   dist[i][j] = graph->weight_edge(recognize[i], recognize[j]);
               }
           }
        }
    }
    for (int k=1; k<=V; k++){
        for (int i=1; i<=V; i++){
            for (int j=1; j<=V; j++){
                if (dist[i][k] != MAX_INFINITY && dist[k][j] != MAX_INFINITY) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        recorr[i][j] = k;
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    for (int i=1; i<=V; i++){
        for (int j=1; j<=V; j++){
            if ( (i != j) & (dist[i][j] != INFINITY)){
                if (recorr[i][j] == j){
                    gfloyd.createEdge(recognize[i], recognize[j], dist[i][j]);
                }
            }
        }
    }
    cout << "matrix_dist" << endl;
    for (int i = 1; i <= V; i++){
        for (int j = 1; j <= V; j++){
            cout <<dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "matrix_rec" << endl;
    for (int i = 1; i <= V; i++){
        for (int j = 1; j <= V; j++){
            cout <<recorr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return gfloyd;
};




#endif //GRAPHS_FLOYDWARSHALL_H
