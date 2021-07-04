#include <utility>

//
// Created by EDGAR on 29/06/2021.
//

#ifndef PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H
#define PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
    Edge()= default;
    explicit Edge(Vertex<TV, TE>* v1, Vertex<TV, TE>* v2, TE weight_){
        vertexes[0] = v1;
        vertexes[1] = v2;
        weight = weight_;
    }
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    string id;
    std::list<Edge<TV, TE>*> edges;
    Vertex()= default;
    explicit Vertex(TV data_, string id_){
        data = std::move(data_);
        id = std::move(id_);
    }
};


#endif //PROYECTO_DE_CURSO_TEAM_BACKYARDIGANS_STRUCTS_H
