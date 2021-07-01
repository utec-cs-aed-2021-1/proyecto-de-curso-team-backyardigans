#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"
#include "Structs.h"
template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
private:
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
public:
    DirectedGraph(){}

    bool insertVertex(string id, TV vertex) override;

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id, string id2       ) override;

    TE &operator()(string start, string end) override{};
    float density() override{};
    bool isDense(float threshold = 0.5) override{};
    bool isConnected() override{};
    bool isStronglyConnected() throw() override{};
    bool empty() override{};
    void clear() override{};
    void displayVertex(string id) override{};
    bool findById(string id) override{};
    void display() override{};
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    auto vertex_ = new Vertex<TV, TE>(vertex);
    vertexes[id] = vertex_;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){
    auto v1 = vertexes[id1];
    auto v2 = vertexes[id2];
    auto edge = new Edge<TV, TE>(v1, v2, w);
    vertexes[id1]->edges.push_back(edge);
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id){
    auto v1 = vertexes[id];
    vector<string> vertices;
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        auto v2 = (*it)->vertexes[0] == v1? (*it)->vertexes[1] : (*it)->vertexes[0];
        auto it2 = v2->edges.begin();
        while (it != it2) it2++;
        v2->edges.erase(it2);
        it++;
    }
    it = v1->edges.begin();
    while (it != v1->edges.end()){
        v1->edges.erase(it);
        it++;
    }
    vertexes.erase(id);
}
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string id, string id2){

}

#endif