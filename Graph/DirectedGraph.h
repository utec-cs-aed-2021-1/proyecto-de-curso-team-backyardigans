#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <iostream>
#include "graph.h"
#include <vector>
#include "Structs.h"
#include "Algorithms/BFS.h"
#include <cmath>

template<typename TV, typename TE>
class BFS;

/// @brief Implementation of a directed graph

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

    /// @brief Check whether the graph is strongly connected or not.
    ///
    /// @return true if the graph is strongly connected
    /// @return false if the graph isn't strongly connected

    bool isStronglyConnected();
    void displayVertex(string id) override;
    bool findById(string id) override;
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){

    // If any of the vertices, with the given ids, doesn't exist or
    // the ids are the same, then return false.

    if ((this -> vertexes).find(id1)==(this -> vertexes).end()
        || (this -> vertexes).find(id2) == (this -> vertexes).end()
        || id1 == id2)
        return false;

    // Get the pointer to the vertices

    auto v1 = (this -> vertexes)[id1];
    auto v2 = (this -> vertexes)[id2];

    // If an edge between the vertices exist, update the weight.

    auto it = v1->edges.begin();

    while (it != v1 -> edges.end()) {
        if ((*it) -> vertexes[1] == v2) {
            (*it) -> weight = w;
            return true;
        }
        it++;
    }

    // If an edge between the vertices doesn't exist, create it.

    auto edge = new Edge<TV, TE>(v1, v2, w);
    (this -> vertexes)[id1]->edges.push_back(edge);
    Graph<TV, TE>::nedge++;
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(string id){
    if ((this -> vertexes).find(id)==(this -> vertexes).end()) return false;
    for (auto it =(this -> vertexes).begin(); it != (this -> vertexes).end() ;it++)
        for (auto it2 = (*it).second->edges.begin(); it2 != (*it).second->edges.end() ;it2++){
            if ((*it2)->vertexes[1]->id == id){
                (*it).second->edges.remove(*it2);
                (this->nedge)--;
                break;
            }
        }
    (this->nedge)-=(this->vertexes)[id]->edges.size();
    (this -> vertexes)[id]->edges.clear();
    (this -> vertexes).erase(id);
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(string id, string id2){
    if ((this -> vertexes).find(id)==(this -> vertexes).end() || (this -> vertexes).find(id2)==(this -> vertexes).end()) return false;
    auto v1 = (this -> vertexes)[id];
    for (auto it = v1->edges.begin(); it != v1->edges.end();it++)
        if ((*it)->vertexes[1]->id == id2 || (*it)->vertexes[0]->id == id2){
            v1->edges.remove(*it);
            (this->nedge)--;
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
    throw std::runtime_error("The edge hasn't been found.");
}

template<typename TV, typename TE>
float DirectedGraph<TV, TE>::density() {
    float s_v = (this -> vertexes).size();
    return (float)(Graph<TV, TE>::nedge/((s_v)*(s_v-1)));
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isDense(float threshold){
    if (density()>threshold) return true;
    return false;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::displayVertex(string id){
    if ((this -> vertexes).find(id) != (this -> vertexes).end()){
        cout <<id<<": " <<(this -> vertexes)[id]->data<<endl;
        for (auto it = (this->vertexes)[id]->edges.begin(); it != (this->vertexes)[id]->edges.end();it++){
            cout <<"peso: " <<(*it)->weight <<"connecto to: "<<(*it)->vertexes[1]->id<<endl;
        }
    }
    else cout << "Not found"<<endl;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::findById(string id){
    if ((this -> vertexes).find(id) != (this -> vertexes).end())
        return true;
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isStronglyConnected(){
    if(this -> getNumberOfVertices() == 0)
        return true;
    auto it = (this -> vertexes).begin();
    BFS<TV, TE> bfs(this, (*it).first);
    DirectedGraph<TV, TE>* dg = bfs.apply();

    //  If every node is not found

    if(dg -> getNumberOfVertices() != this -> getNumberOfVertices())
        return false;

    DirectedGraph<TV, TE>* dg2 = this;
    unordered_map<string, bool> map;
    for(auto& vertex: (dg2 -> vertexes)){
        map[vertex.first] = false;
    }
    vector<pair<pair<string, string>,TE>> save_room;
    for(auto& vertex: (dg2 -> vertexes)) { // RECORRIENDO LOS VERTICES
        for(auto edge = vertex.second->edges.begin(); edge != vertex.second->edges.end(); edge++) {
            auto v0 = (*edge)->vertexes[0]->id;
            auto v1 = (*edge)->vertexes[1]->id;
            auto peso = (*edge)->weight;
            save_room.push_back({{v0, v1}, peso});
        }
    }
    for (auto it: save_room){
        dg2 -> deleteEdge((it).first.first, (it).first.second);
        dg2 -> createEdge((it).first.second, (it).first.first, (it).second);
    }


        /*if (map[s1]==false){
            map[s0] = true;
            dg2 -> deleteEdge(v0-> id, v1-> id); // BORRAMOS LA ARISTA
            dg2 -> createEdge(s1, s0, w); // CREAMOS UNA ARISTA INVERTIDA
        }*/
    BFS<TV, TE> bfs2(dg2, (*it).first);
    DirectedGraph<TV, TE>* dg3 = bfs2.apply();

    // If every node is found
    if(dg3 -> getNumberOfVertices() == this -> getNumberOfVertices())
        return true;
    return false;
}

#endif
