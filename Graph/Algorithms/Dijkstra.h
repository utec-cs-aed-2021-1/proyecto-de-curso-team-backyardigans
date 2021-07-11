#include "graph.h"
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"
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
    DirectedGraph<TV, TE>* apply();
};


template<typename TV, typename TE>
DirectedGraph<TV, TE>* Dijkstra<TV, TE>::apply(){
    DirectedGraph<TV, TE> gdijks;
    priority_<TE> cola;
    unordered_map<string, pair<string, TE>> parent;
    unordered_map<string, int> distance;

    auto mp = graph->getMap(); //vertices del grafo pasado
    for(auto it=mp.begin(); it != mp.end(); it++){
        gdijks.insertVertex(it->first, mp[it->first]->data);
        if(it->first!=vertex) cola.push(it->first);
        else{
            pair<TE,string> p = {0,vertex};
            cola.push(p);
        }
    }
    while(!cola.is_empty()){
        string min = cola.top().second;
        cola.pop();
        for(auto it=mp[min]->edges.begin(); it != mp[min]->edges.end(); it++){
            if (distance[min] + (*it)->weight < distance[(*it)->vertexes[1]->id]){
                distance[(*it)->vertexes[1]->id] = distance[min] + (*it)->weight;
                mp[(*it)->vertexes[1]->id] = {min, (*it)->weight};
                cola.actualizar((*it)->vertexes[1]->id, (*it)->weight + distance[min]);
            }
        }
    }
    for(auto it=parent.begin();it!=parent.end();it++) gdijks.createEdge((*it).first, (*it).second.first, (*it).second.second);
    return gdijks;
}