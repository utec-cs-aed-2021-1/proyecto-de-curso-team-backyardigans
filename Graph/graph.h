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

    /**
     *
     * @return The number of vertices in the graph
     *
     */

    int getNumberOfVertices();
    
    virtual bool insertVertex(string id, TV vertex) = 0;
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

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfVertices() {
  return vertexes.size();
}

#endif
