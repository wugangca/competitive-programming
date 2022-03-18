#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
  int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];
  }

  for (int len = 1; len < n; len++) {
    for (int i = 1; i <= n - len; i++) {
      int j = i + len;
      dp[i][j] = max(dp[i + 1][j] + nums[i - 1] * nums[i] * nums[j + 1],
                     dp[i][j - 1] + nums[i - 1] * nums[j] * nums[j + 1]);
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                     nums[k] * nums[i - 1] * nums[j + 1]);
      }
    }
  }
  return dp[1][n];
}