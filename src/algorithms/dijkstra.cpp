#include <graph.hpp>
#include <queue>
#include <set>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    //create size variable of the number of edges in the graph
    int size = edges.size();
    //declare integer array for distance
    int distance [size];
    distance[start] = 0;

    //declare integer array for parents
    int parents [size];
    // parent[start] ← -1
    parents[start] = -1;

    //make set of all vertices in graph
    std::set<int> vertices;
    for(int i = 0; i < size; i++){
        vertices.insert(edges[i].v);
        vertices.insert(edges[i].u);
    }

    for(int i = 0; i < size; i++){
        std::cout<<vertices[i];
    }

    // for i from 1 to |V| do
    for(int i = 1; i < size; i++){
        
    }
    // u ← argmin
    // ! ∈ # &'( ) *+ ',- )*+*-.(
    // distance[u]
    // visited[u] ← True
    // Break if v is a destination
    // for each vertex v in the adjacency list of u do
    // if distance[u] + w(u, v) < distance[v] then
    // distance[v] ← distance[u] + w(u, v) and parent[v] ← u

    // Path ← { }
    std::vector<int> Path;

    // u ← destination
    // while u ≠ -1 do
    // Path ← { u } ∪ Path
    // u ← parent[u]
    // end do
    return Path;
}
