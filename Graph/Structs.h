#ifndef PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H
#define PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H

#include <utility>
using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

/**
 * @brief Implementation of an edge for a graph
 */

template<typename TV, typename TE>
struct Edge {

    /**
     * @brief The vertices that are incident to this edge
     */

    Vertex<TV, TE>* vertexes[2];

    /**
     * @brief The weight for this edge
     */

    TE weight;
    Edge()= default;

    /**
     * @brief Constructor
     */

    explicit Edge(Vertex<TV, TE>* v1, Vertex<TV, TE>* v2, TE weight_){
        vertexes[0] = v1;
        vertexes[1] = v2;
        weight = weight_;
    }
};

/**
 * @brief Implementation of a vertex for a graph
 */

template<typename TV, typename TE>
struct Vertex {

    /**
     * @brief The data for this vertex
     */

    TV data;

    /**
     * @brief The identifier for this vertex
     */

    string id;

    /**
     * @brief The set of edges that are incident to this vertex
     */

    std::list<Edge<TV, TE>*> edges;
    Vertex()= default;

    /**
     * @brief Constructor
     */

    explicit Vertex(TV data_, string id_){
        data = std::move(data_);
        id = std::move(id_);
    }
};


#endif //PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H
