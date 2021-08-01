//
// Created by LENOVO on 31/07/2021.
//

#ifndef GRAPHS_BELLMANFORD_H
#define GRAPHS_BELLMANFORD_H

#include "DirectedGraph.h"
#define MAX_INFINITY 99999

template<typename TV, typename TE>
class DirectedGraph;

template<typename TV, typename TE>
class BellmanFord{
protected:
    DirectedGraph<TV, TE>* graph;
    string inicial_;
    string final_;
public:
    BellmanFord()= default;;
    BellmanFord(DirectedGraph<TV, TE>* graph_, string inicial, string final){
        graph = graph_;
        inicial_ = std::move(inicial);
        final_ = std::move(final);
    }
    DirectedGraph<TV, TE>* applyd();
};

template<typename TV, typename TE>
DirectedGraph<TV,TE>* BellmanFord<TV, TE>::applyd(){
    auto* BFgraph = new DirectedGraph<TV,TE>();
    unordered_map<string, pair<TE, string>> etiquetas;
    vector<vector<string>> orden;
    string camino;
    bool end;
    unordered_map<string, TE> pesos;
    int V = graph->getNumberOfVertices();
    auto original_map = graph->getMap();
    auto it = original_map.begin();
    while (it != original_map.end()){
        if ( (*it).first == inicial_) etiquetas[(*it).first] = {0, ""};
        else etiquetas[(*it).first] = {MAX_INFINITY, ""};
        BFgraph->insertVertex((*it).first, (*it).second->data);
        for (auto ite = ((*it).second)->edges.begin(); ite != ((*it).second)->edges.end(); ite++){
            camino = (*it).first + (*ite)->vertexes[1]->id;
            orden.push_back({(*it).first,(*ite)->vertexes[1]->id});
            pesos[camino] = (*ite)->weight;
        }
        it++;
    }
    for (int i=0; i<V-1; i++){
        end = true;
        for (auto ite: orden){
            if (etiquetas[ite[0]].first != MAX_INFINITY) {
                auto sum = etiquetas[ite[0]].first + pesos[ite[0] + ite[1]];
                if (sum < etiquetas[ite[1]].first) {
                    etiquetas[ite[1]] = {sum, ite[0]};
                    end = false;
                }
            }
        }
        if (end) break;
    }
    cout << "End table: "<< endl;
    auto itr = etiquetas.begin();
    while (itr != etiquetas.end()){
        cout  << (*itr).first << " : "<< (*itr).second.first << "," << (*itr).second.second << endl;
        itr++;
    }
    pair<TE, string> nuevo;
    string actual = etiquetas[final_].second;
    BFgraph->createEdge(actual, final_, etiquetas[final_].first);
    while(actual != inicial_){
        nuevo = etiquetas[actual];
        BFgraph->createEdge(nuevo.second, actual, etiquetas[actual].first);
        actual = nuevo.second;
    }
    return BFgraph;
}
#endif
