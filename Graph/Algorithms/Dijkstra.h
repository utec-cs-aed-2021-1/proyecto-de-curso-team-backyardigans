#include "graph.h"
#include "DirectedGraph.h"
template<typename TV, typename TE>
class Dijkstra{
protected:
    Graph<TV, TE>* graph;
    string vertex;
public:
    Dijkstra(){};
    Dijkstra(Graph<TV, TE>* graph_, string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    DirectedGraph<TV, TE>* apply(){};
};
/*
template<typename TV, typename TE>

DirectedGraph<TV, TE>* Dijkstra<TV, TE>::apply(){
    auto* Rgraph = new DirectedGraph<TV,TE>();
    unordered_map<string, bool> visited;
    auto map1 = graph->getMap(); //vertices del grafo pasado
    for(auto it=map1.begin();it!=map1.end();it++){
        if(it->first!=vertex){
            pair<TE,string>p={INFINITY,it->first};
            cola.push(p);
        }
        else{
            pair<TE,string> p = {0,vertex};
            cola.push(p);
        }
    }

    return Rgraph;
}*/