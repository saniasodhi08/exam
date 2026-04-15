#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<int> adj[n];

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";

        for(int x : adj[v]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}