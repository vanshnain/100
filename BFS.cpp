#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int V,E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges:\n";
    for(int i=0;i<E;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(V,false);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    cout << "BFS: ";
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
//input 5 4
//0 1
//0 2
//1 3
//2 4
