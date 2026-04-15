#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> spanish, german;
    int n, m, x;

    // Input Spanish speakers
    cout << "Enter number of Spanish speaking attendees: ";
    cin >> n;
    cout << "Enter their IDs:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        spanish.insert(x);
    }

    // Input German speakers
    cout << "\nEnter number of German speaking attendees: ";
    cin >> m;
    cout << "Enter their IDs:\n";
    for(int i = 0; i < m; i++) {
        cin >> x;
        german.insert(x);
    }

    // Union
    cout << "\nUnion (All attendees): ";
    for(int x : spanish) cout << x << " ";
    for(int x : german)
        if(!spanish.count(x))
            cout << x << " ";

    // Intersection
    cout << "\nIntersection (Both languages): ";
    for(int x : spanish)
        if(german.count(x))
            cout << x << " ";

    // Difference (Spanish - German)
    cout << "\nDifference (Only Spanish): ";
    for(int x : spanish)
        if(!german.count(x))
            cout << x << " ";

    cout << endl;
    return 0;
}