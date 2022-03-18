//need min priority queue as we pop out the min element when queue size > k
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  struct Num {
    int num, freq;
    friend bool operator<(const Num& n1, const Num& n2) {
      return n1.freq > n2.freq;
    }
  };
  static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
  }
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    for (int num : nums) {
      m[num]++;
    }

    priority_queue<Num> pq;
    for (pair<int, int> p : m) {
      pq.push({p.first, p.second});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top().num);
      pq.pop();
    }
    return ans;
  }
};