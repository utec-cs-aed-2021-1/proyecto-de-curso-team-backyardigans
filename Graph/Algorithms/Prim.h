#include <utility>

#include "graph.h"
#include "UndirectedGraph.h"
#include "helpclass/priorityqueue.h"

template<typename TV, typename TE>
class Prim{

protected:

    UnDirectedGraph<TV, TE>* graph;
    string vertex;

public:

    Prim();
    Prim(UnDirectedGraph<TV, TE>* graph_,string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }

    UnDirectedGraph<TV, TE>* apply(){
        auto* Ud_1= new UnDirectedGraph<TV, TE>();
        priority_<TE> cola;
        unordered_map<string, string> mp; // padres
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



        // push al priority inf,vertice
            //min para pares
        //sobrecargar corchete de la cola, clase priority queue, cuando le paso string me devuelve el pair dentro de la cola
        while(!cola.empty()){
           string min = cola.top().second;
           cola.pop();
           for(auto it=map1[min].edges.begin();it!=map1[min].edges.end();it++){
               if(cola.find(it.vertexes[1].id) and it.weight< cola[it.vertexes[1].id].first){
                mp[it.vertexes[1].id]=min;
                cola[it.vertexes[1].id].first=it.weight;
               }
           }
       }

    return Ud_1;

    }


};