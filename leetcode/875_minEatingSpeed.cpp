#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool f(vector<int>& piles, int h, int k) {
    int total = 0;
    for (int pile : piles) {
      total += pile / k;
      if (pile % k > 0) {
        total++;
      }
    }
    return total <= h;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    while (start < end) {
      int mid = (start + end) / 2;
      if (f(piles, h, mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};