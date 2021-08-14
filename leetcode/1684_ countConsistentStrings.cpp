#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
  vector<bool> allow(256, false);

  for (char c : allowed) {
    allow[c] = true;
  }
  int count = 0;
  for (string word : words) {
    int consistent = 1;
    for (char c : word) {
      if (!allow[c]) {
        consistent = 0;
        break;
      }
    }
    count += consistent;
  }

  return count;
}

int main() {
  string allowed = "ab";
  vector<string> words{"ad", "bd", "aaab", "baa", "badab"};

  cout << countConsistentStrings(allowed, words);
}
