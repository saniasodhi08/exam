#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    // Taking full line input (important for spaces)
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    // Brute Force Matching
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if(!found)
        cout << "Pattern not found" << endl;

    return 0;
}