#include <bits/stdc++.h>
using namespace std;
vector<int> selfDividingNumbers(int left, int right) {
  vector<int> ans;
  for (int i = left; i <= right; i++) {
    bool self = true;
    string s = to_string(i);
    for (int j = 0; j < s.length(); j++) {
      int n = s[j] - '0';
      if (n == 0 || i % n != 0) {
        self = false;
        break;
      }
    }
    if (self) {
      ans.push_back(i);
    }
  }
  return ans;
}