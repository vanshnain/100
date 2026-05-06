#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<bool> vis(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});
    int cost = 0;

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int w = p.first;
        int u = p.second;

        if (vis[u]) continue;

        vis[u] = true;
        cost += w;

        for (auto x : adj[u]) {
            if (!vis[x.first]) {
                pq.push({x.second, x.first});
            }
        }
    }

    cout << "Cost of MST: " << cost;
}
// input 4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
