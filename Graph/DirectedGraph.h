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

    bool deleteEdge(string id, string id2) override;

    TE &operator()(string start, string end) override;
    float density() override{};
    bool isDense(float threshold = 0.5) override{};
    bool isConnected() override{};
    bool isStronglyConnected() throw() override{};
    bool empty() override{};
    void clear() override{};
    void displayVertex(string id) override{};
    bool findById(string id) override{};
    void display() override;
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    auto vertex_ = new Vertex<TV, TE>(vertex, id);
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
    if (vertexes.find(id)==vertexes.end()) return false;
        vertexes[id]->edges.clear();
    for (auto &it: vertexes)
        for (auto it2 = it.second->edges.begin(); it2 != it.second->edges.end() ;it2++)
            if ((*it2)->vertexes[1]->id == id){
                it.second->edges.remove(*it2);
                break;
            }
    vertexes.erase(id);
    return true;
}
template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string id, string id2){
    if (vertexes.find(id)==vertexes.end() || vertexes.find(id2)==vertexes.end()) return false;
    auto v1 = vertexes[id];
    for (auto it = v1.edges.begin(); it != it.edges.end();it++)
        if ((*it)->vertexes[1]->id == id2){
            v1.edges.remove(*it);
            return true;
        }
    return false;
}

template<typename TV, typename TE>
TE &DirectedGraph<TV, TE>::operator()(string start, string end){
    auto v1 = vertexes[start];
    auto v2 = vertexes[end];
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        if ((*it)->vertexes[0]==v1 && (*it)->vertexes[1]==v2){
            return (*it)->weight;
        }
        it++;
    }
    cout << "NOT FOUND"<<endl;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display(){
    if (vertexes.size() == 0){
        cout << "NOT FOUND"<<endl;
    }
    else {
        auto it = vertexes.begin();
        while (it != vertexes.end()) {
            cout << "size: " << (it->second)->edges.size() << endl;
            cout << "V origen: " << (it->second)->data << "-" << (it->second)->id << endl;
            auto edge_it = (it->second)->edges.begin();
            while (edge_it != (it->second)->edges.end()) {
                cout << "arista: " << (*edge_it)->weight << " ";
                auto data_ = (*edge_it)->vertexes[0] == it->second ? (*edge_it)->vertexes[1] : (*edge_it)->vertexes[0];
                cout << "V fin: " << data_->data << "-" << data_->id << endl;
                edge_it++;
            }
            it++;
        }
        cout << endl;
    }
}

#endif