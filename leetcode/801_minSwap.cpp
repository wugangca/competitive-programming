#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> dp(n, INT_MAX);
    vector<int> dpSwap(n, INT_MAX);
    dp[0] = 0;
    dpSwap[0] = 1;

    for (int i = 1; i < n; i++) {
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        dp[i] = dp[i - 1];
        dpSwap[i] = dpSwap[i - 1] + 1;
      }

      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        dp[i] = min(dp[i], dpSwap[i - 1]);
        dpSwap[i] = min(dpSwap[i], dp[i - 1] + 1);
      }
    }
    return min(dp[n - 1], dpSwap[n - 1]);
  }
};