#include "graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include <stack>
#include <unordered_map>

template<typename TV, typename TE>
class DFS{
protected:
    Graph<TV, TE>* graph;
    string vertex;
public:
    DFS();
    DFS(Graph<TV, TE>* graph_, string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    DirectedGraph<TV, TE>* apply();
};

template<typename TV, typename TE>
DirectedGraph<TV, TE>* DFS<TV, TE>::apply(){
    auto* Rgraph = new DirectedGraph<TV,TE>();
    stack<string> stack_;
    unordered_map<string, bool> map;
    auto map1 = graph->get_map();
    stack_.push(map1[vertex]->id);
    map[vertex] = true;
    Rgraph->insertVertex(vertex, map1[vertex]->data);
    while(!stack_.empty()){
        string actual = stack_.top();
        auto it = map1[stack_.top()]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (map.find((*itr)->vertexes[1]->id) == map.end()){
                Rgraph->insertVertex((*itr)->vertexes[1]->id, (*itr)->vertexes[1]->data);
                map[(*itr)->vertexes[1]->id] = true;
                stack_.push((*itr)->vertexes[1]->id);
                Rgraph->createEdge(actual, stack_.top(), (*itr)->weight);
                break;
            }
        }
        if (stack_.top() == actual)
            stack_.pop();
    }
    return Rgraph;
}