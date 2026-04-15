#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> graph;

    graph["Delhi"] = {"Mumbai", "Jaipur"};
    graph["Mumbai"] = {"Delhi"};
    graph["Jaipur"] = {"Delhi"};

    for(auto x:graph) {
        cout<<x.first<<" -> ";
        for(auto y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }
}