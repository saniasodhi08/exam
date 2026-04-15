#include <iostream>
using namespace std;

int parent[10];

int find(int i){
    while(parent[i]) i = parent[i];
    return i;
}

void uni(int i,int j){
    parent[j] = i;
}

int main(){
    int n;
    cout<<"Enter vertices: ";
    cin>>n;

    int cost[10][10];
    cout<<"Enter cost matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];

    int mincost = 0;

    for(int k=0;k<n-1;k++){
        int min=999,a,b;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j]<min && cost[i][j]!=0){
                    min=cost[i][j]; a=i; b=j;
                }

        int u=find(a), v=find(b);

        if(u!=v){
            cout<<"Edge: "<<a<<"-"<<b<<endl;
            mincost+=min;
            uni(u,v);
        }

        cost[a][b]=cost[b][a]=999;
    }

    cout<<"Minimum cost="<<mincost;
}