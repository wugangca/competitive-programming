#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
  if (prices.size() == 0) {
    return 0;
  }
  int n = prices.size();
  vector<vector<vector<int>>> dp(n,
                                 vector<vector<int>>(k + 1, vector<int>(2, 0)));

  for (int j = 1; j <= k; j++) {
    dp[0][j][0] = -prices[0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] = max(dp[i - 1][j - 1][1] - prices[i], dp[i - 1][j][0]);
      dp[i][j][1] = max(dp[i - 1][j][0] + prices[i], dp[i - 1][j][1]);
    }
  }
  return dp[n - 1][k][1];
}