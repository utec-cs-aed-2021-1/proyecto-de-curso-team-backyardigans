#include <utility>

#include "graph.h"
#include "UndirectedGraph.h"
#include "helpclass/priorityqueue.h"
#include "helpclass/dsarray.h"

template<typename TV, typename TE>
class Kruskal{

protected:

    UnDirectedGraph<TV, TE>* graph;

public:
    Kruskal();
    Kruskal(UnDirectedGraph<TV, TE>* graph_){
        graph = graph_;
    }


    UnDirectedGraph<TV, TE>* apply(){
        auto* Ud_1= new UnDirectedGraph<TV, TE>();
        priority_<TE> cola;
        auto map1 = graph->getMap();
        unordered_map<string, bool> map2;
        for(auto it=map1.begin();it!=map1.end();it++){
            for(auto ite=(*it.second)->edges.begin();ite!=(*it.second)->edges.end();ite++){
                string iu1 =(*ite)->vertexes[0]->id;
                string iu2 =(*ite)->vertexes[1]->id;
                if(map2.find(iu1+iu2)==map2.end() || map2.find(iu2+iu1)==map2.end()){
                    pair<TE,string>p={(*ite)->weigth,iu1+iu2};
                    map2[iu1+iu2]=true;
                    cola.push(p);
                }
            }
        }
        for(auto it=map1.begin();it!=map1.end();it++){

        }




        return Ud_1;
    }
};


