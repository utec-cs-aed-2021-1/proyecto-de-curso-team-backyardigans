#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include <iostream>
#include "graph.h"
#include "Structs.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
public:
    DirectedGraph(){}

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id, string id2) override;

    TE &operator()(string start, string end) override;
    float density() override;
    bool isDense(float threshold = 0.5) override;
    bool isConnected() override{};
    bool isStronglyConnected() throw() override{};
    bool empty() override;
    void clear() override;
    void displayVertex(string id) override;
    bool findById(string id) override;
    void display() override;

};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){
    if ((this -> vertexes).find(id1)==(this -> vertexes).end() || (this -> vertexes).find(id2) == (this -> vertexes).end() || id1 == id2) return false;
    auto v1 = (this -> vertexes)[id1];
    auto v2 = (this -> vertexes)[id2];
    auto edge = new Edge<TV, TE>(v1, v2, w);
    (this -> vertexes)[id1]->edges.push_back(edge);
    Graph<TV, TE>::nedge++;
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id){
    if ((this -> vertexes).find(id)==(this -> vertexes).end()) return false;
        (this -> vertexes)[id]->edges.clear();
    for (auto &it: (this -> vertexes))
        for (auto it2 = it.second->edges.begin(); it2 != it.second->edges.end() ;it2++)
            if ((*it2)->vertexes[1]->id == id){
                it.second->edges.remove(*it2);
                break;
            }
    (this -> vertexes).erase(id);
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string id, string id2){
    if ((this -> vertexes).find(id)==(this -> vertexes).end() || (this -> vertexes).find(id2)==(this -> vertexes).end()) return false;
    auto v1 = (this -> vertexes)[id];
    for (auto it = v1->edges.begin(); it != v1->edges.end();it++)
        if ((*it)->vertexes[1]->id == id2){
            v1->edges.remove(*it);
            return true;
        }
    return false;
}

template<typename TV, typename TE>
TE &DirectedGraph<TV, TE>::operator()(string start, string end){
    auto v1 = (this -> vertexes)[start];
    auto v2 = (this -> vertexes)[end];
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
float DirectedGraph<TV, TE>::density() {
    float s_v = (this -> vertexes).size();
    return (float)Graph<TV, TE>::nedge/((s_v)*(s_v-1));
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isDense(float threshold){
    if (density()>threshold) return true;
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::empty(){
    return (this -> vertexes).size()==0;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::clear(){
    auto it = (this -> vertexes).begin();
    while (it != (this -> vertexes).end()){
        (*it).second->edges.clear();
        it++;
    }
    Graph<TV, TE>::nedge = 0;
    (this -> vertexes).clear();
}
template<typename TV, typename TE>
void DirectedGraph<TV, TE>::displayVertex(string id){
    if ((this -> vertexes).find(id) != (this -> vertexes).end())
        cout <<id<<": " <<(this -> vertexes)[id]->data<<endl;
    else cout << "Not found"<<endl;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::findById(string id){
    if ((this -> vertexes).find(id) != (this -> vertexes).end())
        return true;
    return false;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display(){
    if ((this -> vertexes).size() == 0){
        cout << "NOT FOUND"<<endl;
    }
    else {
        auto it = (this -> vertexes).begin();
        while (it != (this -> vertexes).end()) {
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
