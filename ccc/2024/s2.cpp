#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        vector<int> count(26, 0);
        for (char c: s) {
            count[c-'a']++;
        }

        bool h1 = (count[s[0] - 'a'] > 1);

        bool good = true;
        for (int i = 1; i < n; i++) {
            bool h2 = (count[s[i]-'a'] > 1);
            if (h1 == h2) {
                good = false;
                break;
            }
            h1 = h2;
        }
        if (good) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
}