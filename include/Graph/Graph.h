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
public:

    bool has_vertex(const Vertex& v) const {
        return _vertices.count(v) > 0;
    }
    void add_vertex(const Vertex& v) {
        if (has_vertex(v))
            throw std::invalid_argument("Vertex already exists in the graph");
        _vertices.insert(v);
        _edges.emplace(v, std::vector<Edge>{});
    }
    bool remove_vertex(const Vertex& v) {
        if (!has_vertex(v)) return false;
        _vertices.erase(v);
        _edges.erase(v);
        for (auto& kv : _edges) {
            auto& list_edge = kv.second;
            list_edge.erase(std::remove_if(list_edge.begin(), list_edge.end(),
                [v](const Edge& e) { return e.to == v; }), list_edge.end());
        }
        return true;
    }

    void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
        if (!has_vertex(from) || !has_vertex(to))
            throw std::out_of_range("Vertex doesn't exist in the graph");
        _edges[from].push_back({ from, to, d });
    }
    bool remove_edge(const Vertex& from, const Vertex& to) {
        if (!has_vertex(from) || !has_vertex(to))
            return false;
        auto& list = _edges[from];
        auto it = std::remove_if(list.begin(), list.end(),
            [to](const Edge& e) { return e.to == to; });
        if (it != list.end()) {
            list.erase(it, list.end());
            return true;
        }
        return false;
    }
    bool remove_edge(const Edge& e) {
        if (!has_vertex(e.from) || !has_vertex(e.to))
            return false;
        auto& list = _edges[e.from];
        auto it = std::remove(list.begin(), list.end(), e);
        if (it != list.end()) {
            list.erase(it, list.end());
            return true;
        }
        return false;
    }
    bool has_edge(const Vertex& from, const Vertex& to) const {
        if (!has_vertex(from) || !has_vertex(to))
            return false;
        const auto& edges = _edges.at(from);
        return std::find_if(edges.begin(), edges.end(),
            [to](const Edge& e) { return e.to == to; }) != edges.end();
    }
    bool has_edge(const Edge& e) {
        if (!has_vertex(e.from) || !has_vertex(e.to))
            return false;
        const auto& edges = _edges.at(e.from);
        return std::find(edges.begin(), edges.end(), e) != edges.end();
    }

    


};