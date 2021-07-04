#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <iostream>
#include <stack>
#include "graph.h"

/**
 *
 * @brief Implementation of an undirected graph
 *
 */

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
public:
    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id, string id2) override;

    TE &operator()(string start, string end) override;

    float density() override;

    /**
     *
     * @return true if the graph is dense
     * @return false if the graph isn't dense
     *
     */

    bool isDense(float threshold = 0.5) override;

    /**
     *
     * @return true if the graph is connected
     * @return false if the graph isn't connected
     *
     */
    
    bool isConnected();

    /**
     *
     * @return true if the graph is strongly connected
     * @return false if the graph isn't strongly connected
     *
     */

    bool isStronglyConnected() throw() override{};

    void displayVertex(string id) override;

    bool findById(string id) override;
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){
    if ((this -> vertexes).find(id1) == (this -> vertexes).end() || (this -> vertexes).find(id2) == (this -> vertexes).end() || id1 == id2) return false;
    auto v1 = (this -> vertexes)[id1];
    auto v2 = (this -> vertexes)[id2];
    if (Graph<TV, TE>::findEdge(id1, id2)){
        auto it = v1->edges.begin();
        while (it != v1->edges.end()){
            if ((*it)->vertexes[1]==v2)
                (*it)->weight = w;
            it++;
        }
    }
    else{
        auto edge = new Edge<TV, TE>(v1, v2, w);
        auto edge_ = new Edge<TV, TE>(v2, v1, w);
        (this -> vertexes)[id1]->edges.push_back(edge);
        (this -> vertexes)[id2]->edges.push_back(edge_);
        Graph<TV, TE>::nedge++;
        return true;
    }
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id){
    if ((this -> vertexes).find(id)==(this -> vertexes).end()) return false;
    auto v1 = (this -> vertexes)[id];
    vector<string> vertices;
    auto it = v1->edges.begin();while (it != v1->edges.end()){
        auto v2 = (*it)->vertexes[0] == v1? (*it)->vertexes[1] : (*it)->vertexes[0];
        auto it2 = v2->edges.begin();
        while (*it != *it2) it2++;
        v2->edges.erase(it2);
        Graph<TV, TE>::nedge++;
        it++;
    }
    v1->edges.clear();
    (this -> vertexes).erase(id);
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id, string id2){
    if ((this -> vertexes).find(id) == (this -> vertexes).end() || (this -> vertexes).find(id2) == (this -> vertexes).end() || id == id2) return false;
    auto v1 = (this -> vertexes)[id];
    auto v2 = (this -> vertexes)[id2];
    auto it = v1->edges.begin();
    auto it2 = v2->edges.begin();
    while (it != v1->edges.end()){
        if (((*it)->vertexes[0] == v1 && (*it)->vertexes[1]==v2) || ((*it)->vertexes[0] == v2 && (*it)->vertexes[1] == v1)){
            v1->edges.remove(*it);
            Graph<TV, TE>::nedge++;
            break;
        }
        it++;
    }
    while (it2 != v2->edges.end()){
        if (((*it2)->vertexes[0] == v1 && (*it2)->vertexes[1]==v2) || ((*it2)->vertexes[0] == v2 && (*it2)->vertexes[1] == v1)){
            v2->edges.remove(*it2);
            Graph<TV, TE>::nedge++;
            break;
        }
        it2++;
    }
    return true;
}
template<typename TV, typename TE>
TE &UnDirectedGraph<TV, TE>::operator()(string start, string end){
    auto v1 = (this -> vertexes)[start];
    auto v2 = (this -> vertexes)[end];
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        if ((*it)->vertexes[0]==v1 && (*it)->vertexes[1]==v2)
            return (*it)->weight;
        it++;
    }
}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    float s_v = (this -> vertexes).size();
    return 2*(float)Graph<TV, TE>::nedge/((s_v)*(s_v-1));
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    if (density()>threshold) return true;
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {
    //Hacer recorrido DFS O BFS, con un size
    stack<string> stack_;
    int aux = 0;
    unordered_map<string, bool> map;
    auto it = (this->vertexes).begin();
    stack_.push((this->vertexes)[it.first]->id);
    map[it.first] = true;
    while(!stack_.empty()){
        string actual = stack_.top();
        auto it = (this->vertexes)[stack_.top()]->edges;
        for (auto itr = it.begin(); itr != it.end(); itr++){
            if (map.find((*itr)->vertexes[1]->id) == map.end()){
                aux++;
                map[(*itr)->vertexes[1]->id] = true;
                stack_.push((*itr)->vertexes[1]->id);
                break;
            }
        }
        if (stack_.top() == actual)
            stack_.pop();
    }
    if (aux == (this->vertexes))
        return true;
    return false;
}


template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if ((this -> vertexes).find(id) != (this -> vertexes).end()){
        cout <<id<<": " <<(this -> vertexes)[id]->data<<endl;
        for (auto it = (this->vertexes)[id]->edges.begin(); it != (this->vertexes)[id]->edges.end();it++){
            cout <<"peso: " <<(*it)->weight <<"  connecto to: "<<(*it)->vertexes[1]->id<<endl;
        }
    }
    else cout << "Not found"<<endl;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id){
    if ((this -> vertexes).find(id) != (this -> vertexes).end())
        return true;
    return false;
}


#endif
