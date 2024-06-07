#pragma once
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stdexcept>
#include <queue>
#include <functional>
#include <iterator>

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex from;
        Vertex to;
        Distance distance;
    };

private:
    std::unordered_set<Vertex> _vertices;
    std::unordered_map<Vertex, std::vector<Edge>> _edges;

    std::unordered_set<Vertex> vertices() const {
        return _vertices;
    }
    std::vector<Edge> edges(const Vertex& vertex) {
        return _edges[vertex];
    }



};