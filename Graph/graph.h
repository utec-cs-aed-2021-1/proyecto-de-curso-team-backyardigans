#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <Structs.h>


template<typename TV, typename TE>
class Graph{
protected:
    unordered_map<string, Vertex<TV, TE>*>  vertexes;
    int nedge=0;
public:

    /**
     *
     * @return The number of vertices in the graph
     *
     */
    int getNumberOfVertices();

    /**
     *
     * @return The number of edges in the graph
     *
     */
    int getNumberOfEdges();

    /**
     *
     * @return The unordenered map of the graph
     *
     */
    unordered_map<string, Vertex<TV, TE>*> getMap();

    /**
     *
     * @brief Add a new vertex to the graph
     *
     * @warning The vertex will not be added if there already exists a
     * vertex with the same id as the one being inserted.
     *
     * @return true if the vertex was added
     * @return false if the vertex wasn't added
     *
     */
    bool insertVertex(string id, TV vertex);

    virtual bool createEdge(string id1, string id2, TE w) = 0;
    virtual bool deleteVertex(string id) = 0;
    virtual bool deleteEdge(string id, string id2) = 0;
    virtual TE &operator()(string start, string end)= 0; // es igual para ambas
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0; // es igual para ambas
    virtual bool isStronglyConnected() throw() = 0;
    bool empty(); // es igual en ambas
    void clear(); // es igual para ambas
    virtual void displayVertex(string id)= 0;
    virtual bool findById(string id) = 0;
    void display();
};

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfVertices() {
  return this->vertexes.size();
}

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfEdges() {
    return this->nedge;
}

template<typename TV, typename TE>
unordered_map<string, Vertex<TV, TE>*> Graph<TV, TE>::getMap() {
    return this->vertexes;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::insertVertex(string id, TV vertex) {
    if ((this -> vertexes).find(id) == (this -> vertexes).end()) {
        auto vertex_ = new Vertex<TV, TE>(vertex, id);
        (this -> vertexes)[id] = vertex_;
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::empty() {
    return (this -> vertexes).size()==0;
}

template<typename TV, typename TE>
void Graph<TV, TE>::clear(){
    auto it = (this -> vertexes).begin();
    while (it != (this -> vertexes).end()){
        (*it).second->edges.clear();
        it++;
    }
    Graph<TV, TE>::nedge = 0;
    (this -> vertexes).clear();
}

template<typename TV, typename TE>
void Graph<TV, TE>::display(){
    if ((this -> vertexes).size() == 0){
        cout << "NOT FOUND"<<endl;
    }
    else {
        cout << endl;
        auto it = (this -> vertexes).begin();
        while (it != (this -> vertexes).end()) {
            cout << "size: " << (it->second)->edges.size() << endl;
            auto edge_it = (it->second)->edges.begin();
            while (edge_it != (it->second)->edges.end()) {
                cout << (it->second)->id <<" (" <<(it->second)->data << ")" ;
                cout <<"---- " <<(*edge_it)->weight <<" ----" ;
                auto data_ = (*edge_it)->vertexes[0] == it->second ? (*edge_it)->vertexes[1] : (*edge_it)->vertexes[0];
                cout << data_->id << data_->data << " (" << data_->id <<")" <<endl;
                edge_it++;
            }
            it++;
        }
        cout << endl;
    }
}


#endif
