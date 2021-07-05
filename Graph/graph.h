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

    /**
     *
     * @brief Add a new edge to the graph
     *
     * @warning The edge will be replace the weight if already exist
     * a vertex than connect the two ids
     * @warning The edge will not be added if not exists one or both
     * ids in the graph
     *
     * @return true if the edge was added or was replaced
     * @return false if one or both vertex dont exist in the graph
     *
     */

    virtual bool createEdge(string id1, string id2, TE w) = 0;

    /**
     *
     * @brief Delete a vertex of the graph
     * @warning The vertex and all its edges will be deleted,
     * if it is directed, all the edges that end with that vertex will also be deleted.
     *
     * @return true if vertex was successfully deleted
     * @return false if the vertex dont exist
     */

    virtual bool deleteVertex(string id) = 0;
    virtual bool deleteEdge(string id, string id2) = 0;
    virtual TE &operator()(string start, string end) = 0;
    bool findEdge(string start, string end);
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0;
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
bool Graph<TV, TE>::findEdge(string start, string end) {
    auto v1 = (this -> vertexes)[start];
    auto v2 = (this -> vertexes)[end];
    auto it = v1->edges.begin();
    while (it != v1->edges.end()){
        if ((*it)->vertexes[1]==v2)
            return true;
        it++;
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
            cout << "Number of edges: " << (it->second)->edges.size() <<" -  " <<(it->second)->id << endl;
            auto edge_it = (it->second)->edges.begin();
            while (edge_it != (it->second)->edges.end()) {
                cout << (it->second)->id <<" (" <<(it->second)->data << ")";
                cout <<"---- " <<(*edge_it)->weight <<" ----";
                auto data_ = (*edge_it)->vertexes[0] == it->second ? (*edge_it)->vertexes[1] : (*edge_it)->vertexes[0];
                cout << data_->id << " (" << data_->data <<")" <<endl;
                edge_it++;
            }
            it++;
        }
        cout << endl;
    }
}


#endif
