#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>

std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    //create size variable of the number of edges in the graph
    int size = edges.size();
    // Sort list of edges in the increasing order of edge’s weight
    sort(edges, 0, size - 1);
    // MST ← { }
    //create a vector of edges to store the MST
    std::vector<Edge> MST = {};
    DisjointSet djs(size);
    // for each edge e in sorted list of edges do
    for(int i = 0; i < size; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        if(!djs.isOnSameSet(u,v)){
            MST.push_back(edges[i]);
            djs.join(u,v);
        }
    }
    return MST;
}