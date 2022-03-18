#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  if (s1.length() != s2.length()) {
    cout << "No";
    return 0;
  }

  vector<int> count1(26, 0);
  vector<int> count2(26, 0);

  for (char c : s1) {
    count1[c - 'a']++;
  }

  for (char c : s2) {
    count2[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (count1[i] != count2[i]) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";
}