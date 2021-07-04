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

    Prim(UnDirectedGraph<TV, TE>* graph_,string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    Prim(const UnDirectedGraph<TV, TE>* graph_, string vertex_) {
        graph = graph_;
        vertex = std::move(vertex_);
    }

    UnDirectedGraph<TV, TE> apply(){
        UnDirectedGraph<TV, TE> Ud_1;
        priority_<TE> cola;
        unordered_map<string, pair<string, TE>> mp; // padres
        auto map1 = graph->getMap(); //vertices del grafo pasado
        for(auto it=map1.begin();it!=map1.end();it++){
            Ud_1.insertVertex(it->first, map1[it->first]->data);
            if(it->first!=vertex){
                cola.push(it->first);
            }
            else{
                pair<TE,string> p = {0,vertex};
                cola.push(p);
            }
        }
        while(!cola.is_empty()){
           string min = cola.top().second;
           cout << "MIN: "<< min<<endl;
           cola.pop();

           for(auto it=map1[min]->edges.begin();it!=map1[min]->edges.end();it++){
               if (cola.find((*it)->vertexes[1]->id)){
                   cout << "MINTEST: "<<min << " YES"<<endl;
               }
               else {
                   cout << "MINTEST: "<<min << " NO "<< (*it)->vertexes[1]->id <<endl;
               }
               if(cola.find((*it)->vertexes[1]->id) && (*it)->weight< cola[(*it)->vertexes[1]->id].first) {
                   mp[(*it)->vertexes[1]->id] = {min, (*it)->weight};
                   cout <<"actual: "<< min <<" to "<<(*it)->vertexes[1]->id <<"- peso before delete: " << cola[(*it)->vertexes[1]->id].first << endl;
                   cola[(*it)->vertexes[1]->id].first = (*it)->weight;
                   cout << "peso then delete " << cola[(*it)->vertexes[1]->id].first << endl;
               }
           }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            cout << (*it).first << " - " << (*it).second.first <<" - "<<(*it).second.second;
            Ud_1.createEdge((*it).first, (*it).second.first, (*it).second.second);
        }
    return Ud_1;
    }
};