#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <iostream>
#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
private:
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    int nedge;
public:
    bool insertVertex(string id, TV vertex) override;

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id, string id2) override;

    TE &operator()(string start, string end) override;

    float density() override;

    bool isDense(float threshold = 0.5) override;

    bool isConnected() override;

    bool isStronglyConnected() throw() override{};

    bool empty() override;

    void clear() override;

    void displayVertex(string id) override;

    bool findById(string id) override;

    void display() override;

    void findbyId(string id);
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if (vertexes.find(id)==vertexes.end()) {
        auto vertex_ = new Vertex<TV, TE>(vertex, id);
        vertexes[id] = vertex_;
        return true;
    }
    else return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){
    if (vertexes.find(id1) == vertexes.end() || vertexes.find(id2) == vertexes.end() || id1 == id2) return false;
    auto v1 = vertexes[id1];
    auto v2 = vertexes[id2];
    auto edge = new Edge<TV, TE>(v1, v2, w);
    vertexes[id1]->edges.push_back(edge);
    vertexes[id2]->edges.push_back(edge);
    nedge++;
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id){
    if (vertexes.find(id)==vertexes.end()) return false;
    auto v1 = vertexes[id];
    vector<string> vertices;
    auto it = v1->edges.begin();while (it != v1->edges.end()){
        auto v2 = (*it)->vertexes[0] == v1? (*it)->vertexes[1] : (*it)->vertexes[0];
        auto it2 = v2->edges.begin();
        while (*it != *it2) it2++;
        v2->edges.erase(it2);
        it++;
    }
    v1->edges.clear();
    vertexes.erase(id);
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id, string id2){
    if (vertexes.find(id) == vertexes.end() || vertexes.find(id2) == vertexes.end() || id == id2) return false;
    auto v1 = vertexes[id];
    auto v2 = vertexes[id2];
    auto it = v1->edges.begin();
    auto it2 = v2->edges.begin();
    while (it != v1->edges.end()){
        if (((*it)->vertexes[0] == v1 && (*it)->vertexes[1]==v2) || ((*it)->vertexes[0] == v2 && (*it)->vertexes[1] == v1)){
            v1->edges.remove(*it);
            break;
        }
        it++;
    }
    while (it2 != v2->edges.end()){
        if (((*it2)->vertexes[0] == v1 && (*it2)->vertexes[1]==v2) || ((*it2)->vertexes[0] == v2 && (*it2)->vertexes[1] == v1)){
            v2->edges.remove(*it2);
            nedge--;
            break;
        }
        it2++;
    }
    return true;
}
template<typename TV, typename TE>
TE &UnDirectedGraph<TV, TE>::operator()(string start, string end){
    auto v1 = vertexes[start];
    auto v2 = vertexes[end];
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        if ((*it)->vertexes[0]==v1 && (*it)->vertexes[1]==v2 || ((*it)->vertexes[0] == v2 && (*it)->vertexes[1] == v1)){
            return (*it)->weight;
        }
        it++;
    }
    cout << "NOT FOUND"<<endl;
}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    float s_v = vertexes.size();
    return (float)nedge/((s_v)*(s_v-1));
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    if (density()>threshold) return true;
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {
    //Hacer recorrido DFS O BFS, con un size
}
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {
    return vertexes.size()==0;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {
    auto it = vertexes.begin();
    while (it != vertexes.end()){
        (*it).second->edges.clear();
        it++;
    }
    nedge = 0;
    vertexes.clear();
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if (vertexes.find(id) != vertexes.end())
        cout <<id<<": " <<vertexes[id]->data<<endl;
    else cout << "Not found"<<endl;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id){
    if (vertexes.find(id) != vertexes.end())
        return true;
    return false;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display(){
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
