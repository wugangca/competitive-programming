#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    map<int, int> m;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      m[num]++;
      while (!m.empty() && m.rbegin()->first - m.begin()->first > limit) {
        int n = nums[start];
        auto itr = m.find(n);
        itr->second--;
        if (itr->second == 0) {
          m.erase(itr);
        }
        start++;
      }
      ans = max(ans, i - start + 1);
    }
    return ans;
  }

  int longestSubarray1(vector<int>& nums, int limit) {
    deque<int> maxQ;
    deque<int> minQ;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      while (!maxQ.empty() && num > nums[maxQ.back()]) {
        maxQ.pop_back();
      }
      maxQ.push_back(i);
      while (!minQ.empty() && num < nums[minQ.back()]) {
        minQ.pop_back();
      }
      minQ.push_back(i);
      while (!maxQ.empty() && !minQ.empty() &&
             nums[maxQ.front()] - nums[minQ.front()] > limit) {
        if (maxQ.front() == start) {
          maxQ.pop_front();
        } else if (minQ.front() == start) {
          minQ.pop_front();
        }
        start++;
      }
      int len = i - start + 1;
      if (len > ans) {
        ans = len;
      }
    }
    return ans;
  }
};