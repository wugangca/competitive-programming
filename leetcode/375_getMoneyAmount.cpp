#include <bits/stdc++.h>
using namespace std;
int getMoneyAmount(int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int len = 1; len < n; len++) {
    for (int i = 1; i <= n - len; i++) {
      int j = i + len;
      dp[i][j] = j + dp[i][j - 1];
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
      }
    }
  }
  return dp[1][n];
}