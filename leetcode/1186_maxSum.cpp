#include <bits/stdc++.h>
using namespace std;
int maximumSum(vector<int>& arr) {
  // dp[i][0], no deletion
  // dp[i][1], one deletion
  int ans = arr[0];
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = arr[0];
  dp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }
  return ans;
}