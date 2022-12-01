#include <graph.hpp>
#include <queue>
#include <graph.hpp>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    
    G.distance(start) = 0;
    std::vector<int> path = {};
    int v = start;

    
    for(int i = 0; i < G.n; i++) {
        int min = 10000;
        for(int j = 0; j < G.n; j++) {
            if(G.distance(j) < min && !G.isVisited(j)) {
                min = j;
                v = j;
            }
        }
        G.setVisited(v);
        if(v == destination)
            break;

        for(int i = 0; i < G.e[v].size(); i++) {
            int neighbor = G.e[v][i].v;
            int cost = G.e[v][i].w + G.distance(v);
            if(cost < G.distance(neighbor)) {
                G.distance(neighbor) = cost;
                G.setTrace(neighbor, v);
            }
        }
    }

    while(v != -1) {
        path.emplace(path.begin(), v);
        v = G.trace(v);
    }

    return path;
}