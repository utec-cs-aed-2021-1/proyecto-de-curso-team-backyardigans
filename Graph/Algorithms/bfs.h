
#include "graph.h"
#include <stack>
#include <unordered_map>
#include <utility>
template<typename TV, typename TE>
class DFS{
private:
    Graph<TV, TE> graph;
    string vertex;
public:
    DFS();
    DFS(Graph<TV, TE> graph_, string vertex_){
        graph = graph_;
        vertex = std::move(vertex_);
    }
    Graph<TV, TE> apply();
};

template<typename TV, typename TE>
Graph<TV, TE> DFS<TV, TE>::apply(){
    stack<Vertex<TV, TE>> stack_;
    unordered_map<string, bool> map;
    stack_.push(graph.hash[vertex]);
    map[vertex] = graph.hash[vertex];
    while(!stack_.empty()){

    }
}