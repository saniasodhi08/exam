#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> A, B;
    int n, m, x;

    cout << "Enter size of Set A: ";
    cin >> n;
    cout << "Enter elements of Set A:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        A.insert(x);
    }

    cout << "\nEnter size of Set B: ";
    cin >> m;
    cout << "Enter elements of Set B:\n";
    for(int i = 0; i < m; i++) {
        cin >> x;
        B.insert(x);
    }
    cout << "\nUnion: ";
    for(int val : A) cout << val << " ";
    for(int val : B)
        if(!A.count(val))
            cout << val << " ";

    cout << "\nIntersection: ";
    for(int val : A)
        if(B.count(val))
            cout << val << " ";

    cout << "\nDifference (A - B): ";
    for(int val : A)
        if(!B.count(val))
            cout << val << " ";
            
    cout << "\nDifference (B - A): ";
    for(int val : B)
        if(!A.count(val))
            cout << val << " ";

    cout << endl;
    return 0;
}