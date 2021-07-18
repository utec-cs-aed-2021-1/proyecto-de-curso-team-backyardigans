#include <utility>
#include <list>
#include "graph.h"
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"

template<typename TV, typename TE>
class DirectedGraph;

template<typename TV, typename TE>
class Astar{
protected:
    Graph<TV, TE>* graph;
    string vertexi;
    string vertexf;
    vector<pair<string, TE>>heuristica;

public:
    Astar();
    Astar(Graph<TV, TE>* graph_, string vertexi_, string vertexf_,vector<pair<string, TE>>heuristica_){
        graph=graph_;
        vertexi = std::move(vertexi_);
        vertexf = std::move(vertexf_);
        heuristica=heuristica_;
    }
    DirectedGraph<TV, TE>* apply();
};

template<typename TV, typename TE>
DirectedGraph<TV, TE>* Astar<TV, TE>::apply(){
    auto* Rgraph = new DirectedGraph<TV,TE>();
    priority_<int> pq;
    unordered_map<string, bool> visited;
    unordered_map<string, pair<string,TE>> parents;
    unordered_map<string, int> heuristic;
    unordered_map<string, TE> sum;
    auto original_map = graph->getMap();
    visited[vertexi]=true;
    for(int i=0;i<heuristica.size();i++){
        sum[heuristica[i].first] = 0;
        heuristic[heuristica[i].first]=heuristica[i].second;
    }
    pq.push({0,vertexi});
    Rgraph->insertVertex(vertexi, original_map[vertexi]->data);

    while(!pq.is_empty()){
        string actual = pq.top().second;
        if(actual==vertexf) break;
        pq.pop();
        auto it = original_map[actual]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (visited[(*itr)->vertexes[1]->id] == false){
                string str = (*itr)->vertexes[1]->id;
                parents[str]={actual,(*itr)->weight};
                visited[str] = true;
                sum[str] += (sum[actual] + (*itr)->weight);
                cout << "str: "<< str << " sum: " << sum[   str] <<endl;
                pq.push({(TE)heuristic[str] + sum[str] , str});
            }
        }
        Rgraph->insertVertex(pq.top().second, original_map[pq.top().second]->data);
        Rgraph->createEdge(parents[pq.top().second].first, pq.top().second, parents[pq.top().second].second);
    }
    return Rgraph;
}
