// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include "graph.h"
#include <climits>

#define INF (INT_MAX/2)

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO

void Graph::dijkstra(int s) {
    MinHeap<int, int> minHeap(n, -1);
    for (int i = 1; i <= n; i++) {
        nodes[i].dist = INF;
        nodes[i].visited = false;
        minHeap.insert(i, INF);
    }
    nodes[s].dist = 0;
    nodes[s].pred = s;
    minHeap.decreaseKey(s,0);

    while (minHeap.getSize() > 0) {
        int u = minHeap.removeMin();
        nodes[u].visited = true;
        for (const auto & edge : nodes[u].adj) {
            int v = edge.dest;
            int w = edge.weight;
            if (!nodes[v].visited && nodes[u].dist + w < nodes[v].dist) {
                nodes[v].dist = nodes[u].dist + w;
                minHeap.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }

    }
}

int Graph::dijkstra_distance(int a, int b) {

    dijkstra(a);
    if (nodes[b].dist == INF) return -1;
    return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {

    dijkstra(a);
    list<int> path;

    if (nodes[b].dist == INF) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].pred;
        path.push_front(v);
    }
    return path;
}
