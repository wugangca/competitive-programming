
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  static bool compare(const pair<string, int>& p1,
                      const pair<string, int>& p2) {
    if (p1.second == p2.second) {
      return p1.first < p2.first;
    } else {
      return p1.second > p2.second;
    }
  }

  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> freq;
    for (string word : words) {
      freq[word]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>,
                   decltype(&compare)>
        q(compare);
    for (pair<string, int> p : freq) {
      q.push(p);
      if (q.size() > k) {
        q.pop();
      }
    }
    vector<string> ans(k, "");
    for (int i = k - 1; i >= 0; i--) {
      ans[i] = q.top().first;
      q.pop();
    }
    return ans;
  }
};