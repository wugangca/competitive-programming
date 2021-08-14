#include <bits/stdc++.h>
using namespace std;

int main() {
  int count[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
                   2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

  int key[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
                 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

  while (true) {
    string s;
    cin >> s;
    if (s == "halt") {
      break;
    }
    int previous = 1;
    int total = 0;
    for (size_t i = 0; i < s.length(); i++) {
      int index = s[i] - 'a';
      if (key[index] == previous) {
        total += 2;
      }
      total += count[index];
      previous = key[index];
    }
    cout << total << endl;
  }
}