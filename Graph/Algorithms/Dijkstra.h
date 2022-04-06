#include "graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "helpclass/priorityqueue.h"
//Funciona para Directed y Undirected
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
    DirectedGraph<TV, TE> applyd();
    UndirectedGraph<TV, TE> applyu();
};
template<typename TV, typename TE>
DirectedGraph<TV, TE> Dijkstra<TV, TE>::applyd(){
    DirectedGraph<TV, TE> gdijks;
    priority_<TE> cola;
    unordered_map<string, pair<string, TE>> parent;
    unordered_map<string, int> distance;
    auto mp = graph->getMap();
    for(auto it=mp.begin(); it != mp.end(); it++){
        gdijks.insertVertex(it->first, mp[it->first]->data);
        if(it->first!=vertex) {
            distance[it->first] = (int)INFINITY;
            cola.push(it->first);
        }
        else{
            distance[it->first] = 0;
            pair<TE,string> p = {0,vertex};
            cola.push(p);
        }
    }
    while(!cola.is_empty()){
        string min = cola.top().second;
        cola.pop();
        for(auto it=mp[min]->edges.begin(); it != mp[min]->edges.end(); it++){
            if (distance[min] + (*it)->weight < distance[(*it)->vertexes[1]->id] || distance[(*it)->vertexes[1]->id] == INFINITY){
                distance[(*it)->vertexes[1]->id] = distance[min] + (*it)->weight;
                parent[(*it)->vertexes[1]->id] = {min, (*it)->weight};
                cola.actualizar((*it)->vertexes[1]->id, (*it)->weight + distance[min]);
            }
        }
    }
    for(auto it=parent.begin();it!=parent.end();it++) {
        gdijks.createEdge((*it).second.first, (*it).first, (*it).second.second);
    }
    return gdijks;
}

template<typename TV, typename TE>
UndirectedGraph<TV, TE> Dijkstra<TV, TE>::applyu(){
    UndirectedGraph<TV, TE> gdijks;
    priority_<TE> cola;
    unordered_map<string, pair<string, TE>> parent;
    unordered_map<string, int> distance;
    auto mp = graph->getMap();
    for(auto it=mp.begin(); it != mp.end(); it++){
        gdijks.insertVertex(it->first, mp[it->first]->data);
        if(it->first!=vertex) {
            distance[it->first] = (int)INFINITY;
            cola.push(it->first);
        }
        else{
            distance[it->first] = 0;
            pair<TE,string> p = {0,vertex};
            cola.push(p);
        }
    }
    while(!cola.is_empty()){
        string min = cola.top().second;
        cola.pop();
        for(auto it=mp[min]->edges.begin(); it != mp[min]->edges.end(); it++){
            if (distance[min] + (*it)->weight < distance[(*it)->vertexes[1]->id] || distance[(*it)->vertexes[1]->id] == INFINITY){
                distance[(*it)->vertexes[1]->id] = distance[min] + (*it)->weight;
                parent[(*it)->vertexes[1]->id] = {min, (*it)->weight};
                cola.actualizar((*it)->vertexes[1]->id, (*it)->weight + distance[min]);
            }
        }
    }
    for(auto it=parent.begin();it!=parent.end();it++) {
        gdijks.createEdge((*it).second.first, (*it).first, (*it).second.second);
    }
    return gdijks;
}
