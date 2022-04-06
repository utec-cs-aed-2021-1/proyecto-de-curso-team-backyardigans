#include <utility>
#include "graph.h"
#include "UndirectedGraph.h"
#include "helpclass/priorityqueue.h"

template<typename TV, typename TE>
class Prim{

protected:

    UndirectedGraph<TV, TE>* graph;
    string vertex;

public:

    Prim(UndirectedGraph<TV, TE>* graph_,string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    Prim(const UndirectedGraph<TV, TE>* graph_, string vertex_) {
        graph = graph_;
        vertex = std::move(vertex_);
    }
    UndirectedGraph<TV, TE> apply(){
        UndirectedGraph<TV, TE> gprim;
        priority_<TE> cola;
        unordered_map<string, pair<string, TE>> mp; // padres
        auto map1 = graph->getMap(); //vertices del grafo pasado
        for(auto it=map1.begin();it!=map1.end();it++){
            gprim.insertVertex(it->first, map1[it->first]->data);
            if(it->first!=vertex) cola.push(it->first);
            else{
                pair<TE,string> p = {0,vertex};
                cola.push(p);
            }
        }
        while(!cola.is_empty()){
           string min = cola.top().second;
           cola.pop();
           for(auto it=map1[min]->edges.begin();it!=map1[min]->edges.end();it++){
               if(cola.find((*it)->vertexes[1]->id) && (*it)->weight< cola[(*it)->vertexes[1]->id].first) {
                   mp[(*it)->vertexes[1]->id] = {min, (*it)->weight};
                   cola.actualizar((*it)->vertexes[1]->id, (*it)->weight);
               }
           }
        }
        for(auto it=mp.begin();it!=mp.end();it++) gprim.createEdge((*it).first, (*it).second.first, (*it).second.second);
    return gprim;
    }
};
