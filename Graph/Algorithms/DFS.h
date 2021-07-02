#include "graph.h"
#include <stack>
#include <unordered_map>

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
    Graph<TV, TE> Rgraph;
    stack<string> stack_;
    unordered_map<string, bool> map;
    stack_.push(graph.vertexes[vertex].id);
    map[vertex] = true;
    while(!stack_.empty()){
        string actual = stack_.top();
        auto it = graph.vertexes[actual];
        for (auto itr = it.edges.begin(); itr != it.edges.end(); itr++){
            if (map.find((*itr).vertexes[1].id) == map.end()){
                map[(*itr).vertexes[1].id] = true;
                stack_.push((*itr).vertexes[1].id);
                break;
            }
        }
        if (stack_.top() == actual){
            stack_.pop();
        }
    }
    return Rgraph;
}