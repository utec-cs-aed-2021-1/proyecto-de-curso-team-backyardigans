#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
private:
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
public:
    bool insertVertex(string id, TV vertex) override;

    bool createEdge(string id1, string id2, TE w) override;

    bool deleteVertex(string id) override;

    bool deleteEdge(string id, string id2) override;

    TE &operator()(string start, string end) override{};

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
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    auto vertex_ = new Vertex<TV, TE>(vertex, id);
    vertexes[id] = vertex_;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w){
    auto v1 = vertexes[id1];
    auto v2 = vertexes[id2];
    auto edge = new Edge<TV, TE>(v1, v2, w);
    vertexes[id1]->edges.push_back(edge);
    vertexes[id2]->edges.push_back(edge);
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id){
    auto v1 = vertexes[id];
    vector<string> vertices;
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        auto v2 = (*it)->vertexes[0] == v1? (*it)->vertexes[1] : (*it)->vertexes[0];
        auto it2 = v2->edges.begin();
        while (*it != *it2) it2++;
        v2->edges.erase(it2);
        it++;
    }
    v1->edges.clear();
    vertexes.erase(id);
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id, string id2){
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
            break;
        }
        it2++;
    }
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display(){
    auto it = vertexes.begin();
    while (it != vertexes.end()){
        cout <<"size: " << (it->second)->edges.size() << endl;
        cout <<"V origen: " <<(it->second)->data <<"-"<<(it->second)->id << endl;
        auto edge_it = (it->second)->edges.begin();
        while(edge_it != (it->second)->edges.end()){
            cout << "arista: " <<(*edge_it)->weight << " ";
            auto data_ = (*edge_it)->vertexes[0]==it->second ? (*edge_it)->vertexes[1]: (*edge_it)->vertexes[0];
            cout << "V fin: "<<data_->data <<"-"<<data_->id << endl;
            edge_it++;
        }
        it++;
    }
    cout << endl;
}
#endif