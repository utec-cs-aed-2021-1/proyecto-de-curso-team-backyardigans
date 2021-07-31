#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include "Structs.h"

/// @brief Implementation of a graph
///
/// @tparam TV type of the data stored in each vertex
/// @tparam TE type for the weight of the edges

template<typename TV, typename TE>
class Graph{
protected:

    /// @brief The existing vertices in the graph.

    unordered_map<string, Vertex<TV, TE>*>  vertexes;

    /// @brief The number of existing edges in the graph

    int nedge=0;

public:

    int getNumberOfVertices();

    int getNumberOfEdges();

    unordered_map<string, Vertex<TV, TE>*> getMap();

    bool insertVertex(string id, TV vertex);

    void display();

    bool empty();

    void clear();

    bool findEdge(string start, string end);

    // Abstract methods

    /// @brief Add a new edge to the graph
    ///
    /// @warning The edge will be replace the weight if already exist
    /// a vertex than connect the two ids
    /// @warning The edge will not be added if not exists one or both
    /// ids in the graph
    ///
    /// @return true if the edge was added or was replaced
    /// @return false if one or both vertex dont exist in the graph

    virtual bool createEdge(string id1, string id2, TE w) = 0;

    /// @brief Delete a vertex of the graph
    /// @warning The vertex and all its edges will be deleted,
    /// if it is directed, all the edges that end with that vertex will also be deleted.
    ///
    /// @return true if vertex was successfully deleted
    /// @return false if the vertex dont exist

    virtual bool deleteVertex(string id) = 0;

    /// @brief Deletes a given edge
    ///
    /// @return true if the edge was successfully deleted
    /// @return false if the edge wasn't deleted

    virtual bool deleteEdge(string id, string id2) = 0;

    /// @brief Get an edge given two vertices ids
    ///
    /// @return the edge which was start as the starting vertex and end
    /// as the ending vertex.

    virtual TE &operator()(string start, string end) = 0;

    /// @brief Get the density factor of the graph
    ///
    /// @return the density factor of the graph

    virtual float density() = 0;

    /// @brief Determine whether the graph is dense given a threshold.
    ///
    /// @return true if the graph is dense
    /// @return false if the graph isn't dense

    virtual bool isDense(float threshold = 0.5) = 0;

    /// @brief Print a given vertex

    virtual void displayVertex(string id)= 0;

    /// @brief Find vertex given its id
    ///
    /// @return true if the vertex was found
    /// @return false if the vertex wasn't found

    virtual bool findById(string id) = 0;
};

/// @brief Get the number of vertices in the graph
///
/// @return The number of vertices in the graph

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfVertices() {
  return this->vertexes.size();
}

/// @brief Get the number of edges in the graph
///
/// @return The number of edges in the graph

template<typename TV, typename TE>
int Graph<TV, TE>::getNumberOfEdges() {
    return this->nedge;
}

/// @brief Build a unordered map of the graph
///
/// @return The unordenered map of the graph

template<typename TV, typename TE>
unordered_map<string, Vertex<TV, TE>*> Graph<TV, TE>::getMap() {
    return this->vertexes;
}

/// @brief Add a new vertex to the graph
///
/// @param[in] id The identifier for the vertex in the whole graph
/// @param[in] vertex The data stored in the vertex.
///
/// @warning The vertex will not be added if there already exists a
/// vertex with the same id as the one being inserted.
///
/// @return true if the vertex was added
/// @return false if the vertex wasn't added

template<typename TV, typename TE>
bool Graph<TV, TE>::insertVertex(string id, TV vertex) {
    if ((this -> vertexes).find(id) == (this -> vertexes).end()) {
        auto vertex_ = new Vertex<TV, TE>(vertex, id);
        (this -> vertexes)[id] = vertex_;
        return true;
    }
    return false;
}

/// @brief Deletes a given edge
///
/// @return true if the edge was found
/// @return false if the edge wasn't found

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

/// @brief Determine whether the graph is empty
///
/// @return true if the graph is empty
/// @return false if the graph isn't empty

template<typename TV, typename TE>
bool Graph<TV, TE>::empty() {
    return (this -> vertexes).size()==0;
}

/// @brief Free all used memory by the graph

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

/// @brief Display the whole graph

template<typename TV, typename TE>
void Graph<TV, TE>::display() {
    if (empty())
        cout << "The graph is empty.";

    // Iterate through all vertices.

    auto it = (this -> vertexes).begin();

    while (it != (this -> vertexes).end()) {
        cout << "Vertex: " << it -> second -> id << endl
             << "Number of edges: " << it -> second -> edges.size() << endl;

        // Print all the edges having the vertex as the starting point.

        auto edge_it = (it -> second) -> edges.begin();
        while (edge_it != (it -> second) -> edges.end()) {
            cout << "((id: " << (it -> second) -> id <<") (data: " <<(it -> second) -> data << "))"
                 << " - " << (*edge_it) -> weight <<" - "
                 << "((id: " << (*edge_it) -> vertexes[1] -> id << ") (data: " << (*edge_it)->vertexes[1] ->data << "))" <<endl;
            edge_it++;
        }
        it++;
    }
}

#endif
