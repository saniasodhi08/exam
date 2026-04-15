#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    int start;
    cout << "Enter source node: ";
    cin >> start;

    int dist[10], visited[10]={0};

    for(int i=0;i<n;i++)
        dist[i]=999;

    dist[start]=0;

    for(int i=0;i<n;i++) {
        int u=-1;
        for(int j=0;j<n;j++)
            if(!visited[j] && (u==-1 || dist[j]<dist[u]))
                u=j;

        visited[u]=1;

        for(int v=0;v<n;v++)
            if(graph[u][v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
    }

    cout<<"Shortest distances:\n";
    for(int i=0;i<n;i++)
        cout<<"To "<<i<<" = "<<dist[i]<<endl;
}