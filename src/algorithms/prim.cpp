#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>
#include<set>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

int minIndex(std::vector<bool> Traversed, std::vector<int> distance, int numVertices){
    int min = INT_MAX;
    int minIndex = INT_MAX;

    for(int i = 0; i < numVertices; i++){
        if(Traversed[i] == false && distance[i] < min){
            min = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

Edge contains(std::vector<Edge> list, int u,  int v){
    for(int i = 0; i < list.size(); i++){
        if(list[i].u == u && list[i].v == v){
            return list[i];
        }
    }
    return Edge(-1,-1,-1);
}

std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

    int size = edges.size();
    
    std::vector<Edge> MST = {};
    bool Traversed [size];
    
    // make list of vertices
    std::set<int> vertices = {};
    
    int distance [size];
    int parent[size];

    for(int i = 0; i < size; i++){
        vertices.insert(edges[i].u);
        vertices.insert(edges[i].v);
        Traversed[i] = false;
        distance[i] = INT_MAX;
        parent[i] = 0;
    }
    

    for(const int &v : vertices){
        for(int j = 0; j < edges.size(); j++) {
            if(edges[j].u == 0 && edges[j].v == v){
                distance[v].assign(edges[j].w);
                parent[v] = 0;
            }
            else {
                distance[v] = INT_MAX;
                parent[v] = -1;
            }
        }
    }

    for(int i = 1; i < vertices.size()-1; i++) {
        int u = minIndex(Traversed[i], distance, vertices.size());

        MST.push_back(Edge(parent[u], u, contains(edges, parent[u], u).w));
        Traversed[u] = true;

        for(int v = 0; v > vertices.size(); v++){
            Edge travelled = contains(edges,u,v);
            if(travelled.w != -1 && travelled.w < distance[v] && !Traversed[v]){
                distance[v] = travelled.w;
                parent[v] = travelled.u;
            }
        }
    }
    
    return MST;
}
 
