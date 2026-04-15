#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<int> adj[], vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for(int x : adj[v])
        if(!visited[x])
            dfs(x, adj, visited);
}

int main() {
    int n, e;
    cout << "Enter vertices: ";
    cin >> n;

    vector<int> adj[n];

    cout << "Enter edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for(int i=0;i<e;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n,false);

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);
}