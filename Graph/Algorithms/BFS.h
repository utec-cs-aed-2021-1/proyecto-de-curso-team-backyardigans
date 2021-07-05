#include "graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include <queue>
#include <unordered_map>

template<typename TV, typename TE>
class BFS{
protected:
    Graph<TV, TE>* graph;
    string vertex;
public:
    BFS();
    BFS(Graph<TV, TE>* graph_, string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    DirectedGraph<TV, TE>* apply();
};

template<typename TV, typename TE>
DirectedGraph<TV, TE>* BFS<TV, TE>::apply(){
    auto* Rgraph = new DirectedGraph<TV,TE>();
    queue<string> queue_;
    unordered_map<string, bool> map;
    auto map1 = graph->getMap();
    queue_.push(map1[vertex]->id);
    for(auto it=map1.begin();it!=map1.end();it++){
        if(it->first!=vertex){
            map[vertex] = true;
        }
        else{
            map[it->first] = false;
        }
    }
    Rgraph->insertVertex(vertex, map1[vertex]->data);

    while(!queue_.empty()){
        string actual = queue_.front();
        auto it = map1[queue_.front()]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (map[(*itr)->vertexes[1]->id] == false){
                Rgraph->insertVertex((*itr)->vertexes[1]->id, (*itr)->vertexes[1]->data);
                map[(*itr)->vertexes[1]->id] = true;
                queue_.push((*itr)->vertexes[1]->id);
                Rgraph->createEdge(actual, queue_.back(), (*itr)->weight);
            }
        }
        queue_.pop();
    }
    return Rgraph;
}