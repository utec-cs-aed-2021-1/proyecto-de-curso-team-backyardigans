#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>
#include <Structs.h>


template<typename TV, typename TE>
class Graph{
protected:
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    int nedge=0;
public:
    int getNumberOfVertices();
    bool insertVertex(string id, TV vertex);
    virtual bool createEdge(string id1, string id2, TE w) = 0;
    virtual bool deleteVertex(string id) = 0;
    virtual bool deleteEdge(string id, string id2) = 0;
    virtual TE &operator()(string start, string end)= 0;
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0;
    virtual bool isConnected()= 0;
    virtual bool isStronglyConnected() throw() = 0;
    virtual bool empty() = 0;
    virtual void clear()= 0;
      
    virtual void displayVertex(string id)= 0;
    virtual bool findById(string id) = 0;
    virtual void display() = 0;
};

/**
 *
 * @return The number of vertices in the graph
 *
 */

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfVertices() {
  return vertexes.size();
}

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

template<typename TV, typename TE>
bool Graph<TV, TE>::insertVertex(string id, TV vertex) {
    if ((this -> vertexes).find(id) == (this -> vertexes).end()) {
        auto vertex_ = new Vertex<TV, TE>(vertex, id);
        (this -> vertexes)[id] = vertex_;
        return true;
    }
    else return false;
}

#endif
