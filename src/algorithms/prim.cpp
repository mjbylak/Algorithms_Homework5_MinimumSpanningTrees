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

int minIndex(bool Traversed [], int distance [], int numVertices){
    int min = INT_MAX;
    int minIndex = 0;

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

    //find the number of edges in the graph so the entire graph can be traversed
    int size = edges.size();
    
    //create a vector of edges to store the MST
    std::vector<Edge> MST = {};
    //boolean array of which vertices has been visited
    bool Traversed [size];
    
    //make distance array for keeping track of cost and parent array of previous nodes
    int distance [size];
    int parent[size];

    //check nearby vertices and add them 
    for(int i = 0; i < size; i++){
        //set adjacent vertices to appropriate distances 
        if(edges[i].u == edges[0].v){
            Traversed[i] = false;
            distance[i] = edges[i].w;
            parent[i] = edges[0].v;
        }
        else{
        //otherwise set weights to infinite because they're not reachable
            Traversed[i] = false;
            distance[i] = INT_MAX;
            parent[i] = -1;
        }
    }

    //for all edges, find the minimum distance to the next vertex
    for(int i = 0; i < size; i++){
        int min = minIndex(Traversed, distance, size);
        Edge edge = contains(edges, parent[min], min);
        if(edge.u != -1){
            MST.push_back(edge);
        }
        Traversed[min] = true;
        for(int j = 0; j < size; j++){
            Edge edge2 = contains(edges, min, j);
            if(Traversed[j] == false && edge2.u != -1 && distance[j] > edge2.w){
                distance[j] = edge2.w;
                parent[j] = edge2.u;
            }
        }
    }
        
    return MST;
}
 
