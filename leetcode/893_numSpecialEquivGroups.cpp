#include <bits/stdc++.h>
using namespace std;
int numSpecialEquivGroups(vector<string>& words) {
  if (words.size() == 0) {
    return 0;
  }
  int len = words[0].size();
  set<string> s;
  for (string word : words) {
    string odd = "", even = "";
    for (int i = 0; i < len; i++) {
      if (i % 2 == 0) {
        even += word[i];
      } else {
        odd += word[i];
      }
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    s.insert(odd + even);
  }
  return s.size();
}