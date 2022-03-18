#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    int pLen = pattern.length();
    for (string q : queries) {
      int i = 0;
      int j = 0;
      int len1 = q.length();

      while (i < len1 && j < pLen) {
        if (q[i] == pattern[j]) {
          i++;
          j++;
        } else if (q[i] >= 'a' && q[i] <= 'z') {
          i++;
        } else {
          break;
        }
      }
      if (j < pLen) {
        ans.push_back(false);
        continue;
      }
      while (i < len1) {
        if (q[i] >= 'a' && q[i] <= 'z') {
          i++;
        } else {
          break;
        }
      }
      if (i < len1) {
        ans.push_back(false);
      } else {
        ans.push_back(true);
      }
    }
    return ans;
  }
};