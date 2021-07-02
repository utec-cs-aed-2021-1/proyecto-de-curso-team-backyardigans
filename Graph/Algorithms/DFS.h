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
    cout << "gaa"<<endl;
    unordered_map<string, bool> map;
    auto map1 = graph->get_map();
    stack_.push(map1[vertex]->id);
    map[vertex] = true;

    while(!stack_.empty()){
        string actual = stack_.top();
        auto data_ = map1[vertex]->data;
        Rgraph->insertVertex(actual, data_);
        auto it = graph->get_map()[vertex]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (map.find((*itr)->vertexes[1]->id) == map.end()){
                Rgraph->insertVertex((*itr)->vertexes[1]->id, (*itr)->vertexes[1]->data);
                map[(*itr)->vertexes[1]->id] = true;
                stack_.push((*itr)->vertexes[1]->id);
                Rgraph->createEdge(actual, stack_.top(), (*itr)->weight);
                break;
            }
        }
        if (stack_.top() == actual){
            stack_.pop();
        }
    }
    Rgraph->display();
    return Rgraph;
}