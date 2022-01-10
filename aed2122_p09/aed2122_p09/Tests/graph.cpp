// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    int num = 0;
    cout << v << " "; // show node order
    nodes[v].visited = true;
    num++;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            num += dfs(w);
    }
    return num;
}

void Graph::dfs(int v, list<int> &order) {
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w, order);
    }
    order.insert(order.begin(), v);
}

bool Graph::dfsCycle(int v) {
    nodes[v].color = "gray";

    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].color == "white")
            dfsCycle(w);
        if (nodes[w].color == "gray")
            return true;
    }
    nodes[v].color = "black";
    return false;
}

// Depth-First Search: example implementation
int Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    int maxDistance = 0;
    nodes[v]. visited = true;
    nodes[v].distance = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                maxDistance = nodes[u].distance + 1;
            }
        }
    }
    return maxDistance;
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO
int Graph::outDegree(int v) {
    if (v < 1 || v >= nodes.size()) return -1;

    return nodes[v].adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    list<int> order;
    int res = 0;
    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            dfs(i, order);
            res++;
        }
    }
    return res;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    list<int> order;
    int max = 0;
    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            int res = dfs(i);
            if (max < res) max = res;
        }

    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    for (int i = 1; i < nodes.size(); i++) {
        if (!nodes[i].visited) {
            dfs(i, order);
        }
    }

    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO
int Graph::distance(int a, int b) {
    bfs(a);
    if (a != b && !nodes[b].visited) return -1;
    return nodes[b].distance;
}

// ..............................
// b) Diametro
// TODO
int Graph::diameter() {
    if (connectedComponents() > 1) return -1;

    return bfs(1);
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    for (auto & node : nodes) {
        node.color = "white";
    }
    bool res = false;
    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i].color == "white") {
            res = dfsCycle(i);
            if (res) break;
        }
    }
    return res;
}
