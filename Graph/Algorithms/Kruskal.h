#include <utility>

#include "graph.h"
#include "UndirectedGraph.h"
#include "helpclass/priorityqueue.h"
#include "helpclass/dsarray.h"
#include "vector"

template<typename TV, typename TE>
class Kruskal{

protected:

    UnDirectedGraph<TV, TE>* graph;
    vector<TE> v;
public:
    Kruskal();
    Kruskal(UnDirectedGraph<TV, TE>* graph_,vector<TE> v_){
        graph = graph_;
        v=v_;
    }


    UnDirectedGraph<TV, TE>* apply(){
        auto* Ud_1= new UnDirectedGraph<TV, TE>();
        priority_<TE> cola;
        auto map1 = graph->getMap(); // map vert
        unordered_map<string, bool> map2;
        unordered_map<string, int> mapx;//map pos
        int aux= 0;
        for(auto it=map1.begin();it!=map1.end();it++){
            mapx[it->first]=aux++;
            v.push_back(it->first);
            Ud_1->insertVertex(it->first,map1[it->first]->data);
            for(auto ite=(*it.second)->edges.begin();ite!=(*it.second)->edges.end();ite++) {
                string iu1 = (*ite)->vertexes[0]->id;
                string iu2 = (*ite)->vertexes[1]->id;
                if (map2.find(iu1 + iu2) == map2.end() || map2.find(iu2 + iu1) == map2.end()) {
                    pair<TE, string> p = {(*ite)->weigth, iu1 + iu2};
                    map2[iu1 + iu2] = true;
                    cola.push(p);
                }

            }
        }

        auto d = new DisjoinSet<TE>(v);
        d->Makeset();
        while(!cola.is_empty()){
            string u=cola.top().second;

            string u1= to_string(u[0]);
            string u2=to_string(u[1]);

            if(d->Find(mapx[u1])!=d->Find(mapx[u2])){
                d->Union(mapx[u1],mapx[u2]);
                Ud_1->createEdge(u1,u2,cola.top().first);
            }
            cola.pop();
        }

        return Ud_1;
    }
};


