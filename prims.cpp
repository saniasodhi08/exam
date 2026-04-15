#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter cost matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> cost[i][j];

    int visited[10] = {0};
    visited[0] = 1;

    int mincost = 0;

    for(int k=0;k<n-1;k++) {
        int min = 999, a = -1, b = -1;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j] && visited[i] && !visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        cout << "Edge: " << a << "-" << b << endl;
        visited[b] = 1;
        mincost += min;
    }

    cout << "Minimum cost = " << mincost;
}