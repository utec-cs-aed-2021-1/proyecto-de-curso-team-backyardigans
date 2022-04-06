#ifndef GRAPHS_GREEDY_H
#define GRAPHS_GREEDY_H
#include <utility>
#include <list>
#include "graph.h"
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"

template<typename TV, typename TE>
class DirectedGraph;


template<typename TV, typename TE>
class Greedy{
protected:
    Graph<TV, TE>* graph;
    string vertexi;
    string vertexf;
    vector<pair<string, TE>>heuristica;

public:
    Greedy();
    Greedy(Graph<TV, TE>* graph_, string vertexi_, string vertexf_,vector<pair<string, TE>>heuristica_){
        graph=graph_;
        vertexi = std::move(vertexi_);
        vertexf = std::move(vertexf_);
        heuristica=heuristica_;
    }
    DirectedGraph<TV, TE>* apply();
};

template<typename TV, typename TE>
DirectedGraph<TV, TE>* Greedy<TV, TE>::apply(){
    auto* Rgraph = new DirectedGraph<TV,TE>();
    priority_<int> pq;
    unordered_map<string, bool> visited;
    unordered_map<string, pair<string,TE>>parents;
    unordered_map<string, int> heuristic;

    auto originalmap = graph->getMap();
    visited[vertexi]=true;
    for(int i=0;i<heuristica.size();i++){
        heuristic[heuristica[i].first]=heuristica[i].second;
    }
    pq.push({0,vertexi});
    Rgraph->insertVertex(vertexi, originalmap[vertexi]->data);

    while(!pq.is_empty()){
        string actual = pq.top().second;
        if(actual==vertexf) break;
        pq.pop();
        auto it = originalmap[actual]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (visited[(*itr)->vertexes[1]->id] == false){
                parents[(*itr)->vertexes[1]->id]={actual,(*itr)->weight};
                visited[(*itr)->vertexes[1]->id] = true;
                pq.push({heuristic[(*itr)->vertexes[1]->id],(*itr)->vertexes[1]->id});

            }

        }
        Rgraph->insertVertex(pq.top().second,originalmap[pq.top().second]->data);
        Rgraph->createEdge(parents[pq.top().second].first, pq.top().second, parents[pq.top().second].second);
    }
    return Rgraph;
}





#endif //GRAPHS_GREEDY_H
