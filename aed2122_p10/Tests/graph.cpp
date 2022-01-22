// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight, src});

    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// Exercicio 3: Algoritmo de Prim
// ----------------------------------------------------------
// TODO

int Graph::prim(int r) {

    int res = 0;

    MinHeap<int, int> minHeap(nodes.size() - 1, -1);

    for (auto &node : nodes) {
        node.parent = 0;
        node.distance = INT_MAX;
    }

    nodes[r].distance = 0;

    for (int i = 1; i <= nodes.size() - 1; i++) {
        minHeap.insert(i, nodes[i].distance);
    }

    while (minHeap.getSize() != 0) {
        int u = minHeap.removeMin();
        for (auto it = nodes[u].adj.begin(); it != nodes[u].adj.end(); it++) {

            if (minHeap.hasKey(it->dest) && it->weight < nodes[it->dest].distance) {
                nodes[it->dest].distance = it->weight;
                minHeap.decreaseKey(it->dest, it->weight);
                nodes[it->dest].parent = u;
            }
        }
    }

    for (int i = 1; i <= nodes.size() - 1; i++) {
        res += nodes[i].distance;
    }

    return res;
}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
// TODO
int Graph::kruskal() {
    DisjointSets<int> t;
    int res = 0;
    list<Edge> edges;
    for (int i = 1; i <= nodes.size() - 1; i++) {
        t.makeSet(i);
        for (auto edge : nodes[i].adj) {
            if (edge.origin != 0) edges.push_back(edge);
        }
    }
    edges.sort([](const Edge & e1, const Edge & e2) -> bool {
       return e1.weight < e2.weight;
    });

    for (auto edge : edges) {
        if (t.find(edge.origin) != t.find(edge.dest)) {
            t.unite(t.find(edge.origin), t.find(edge.dest));
            res += edge.weight;
            t.unite(edge.origin, edge.dest);
        }
    }
    return res;
}
