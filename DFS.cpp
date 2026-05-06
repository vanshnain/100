#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(V, false);

    cout << "DFS: ";
    dfs(0, adj, visited);   // starting from node 0

    return 0;
}
// 5 4
//0 1
//0 2
//1 3
//2 4
