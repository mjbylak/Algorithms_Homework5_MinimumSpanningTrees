#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    // distance[start] ← 0
    // parent[start] ← -1
    // for i from 1 to |V| do
    // u ← argmin
    // ! ∈ # &'( ) *+ ',- )*+*-.(
    // distance[u]
    // visited[u] ← True
    // Break if v is a destination
    // for each vertex v in the adjacency list of u do
    // if distance[u] + w(u, v) < distance[v] then
    // distance[v] ← distance[u] + w(u, v) and parent[v] ← u
    // end if
    // end do
    // end do
    // Path ← { }
    // u ← destination
    // while u ≠ -1 do
    // Path ← { u } ∪ Path
    // u ← parent[u]
    // end do
    // return Path 
}
