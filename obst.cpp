#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of keys: ";
    cin >> n;

    int keys[10], freq[10];

    cout << "Enter keys (sorted order):\n";
    for(int i = 0; i < n; i++)
        cin >> keys[i];

    cout << "Enter frequencies:\n";
    for(int i = 0; i < n; i++)
        cin >> freq[i];

    int cost[10][10] = {0};

    // Initialize diagonal
    for(int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for(int L = 2; L <= n; L++) {
        for(int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = 9999;

            int sum = 0;
            for(int k = i; k <= j; k++)
                sum += freq[k];

            for(int r = i; r <= j; r++) {
                int c = sum;
                if(r > i) c += cost[i][r - 1];
                if(r < j) c += cost[r + 1][j];

                if(c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    cout << "\nCost of Optimal BST = " << cost[0][n - 1] << endl;
    
    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    bool found = false;
    for(int i = 0; i < n; i++) {
        if(keys[i] == key) {
            cout << "Key found in symbol table\n";
            found = true;
            break;
        }
    }

    if(!found)
        cout << "Key not found\n";

    return 0;
}