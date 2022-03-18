#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
  vector<int> counter(26, 0);
  for (char ch : s) {
    counter[ch - 'a']++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (counter[s[i] - 'a'] == 1) {
      return i;
    }
  }
  return -1;
}