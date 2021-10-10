#include <bits/stdc++.h>
using namespace std;
int lastStoneWeightII(vector<int>& stones) {
  int total = accumulate(stones.begin(), stones.end(), 0);
  int n = stones.size();
  vector<vector<bool> > dp(n + 1, vector<bool>(total + 1, false));

  // dp[n+1][half+1]
  // dp[i][sum]: can reach sum with first i numbers

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  for (int i = 1; i <= n; i++) {
    int num = stones[i - 1];
    for (int sum = 1; sum <= total; sum++) {
      dp[i][sum] = dp[i - 1][sum] | ((sum >= num) && dp[i - 1][sum - num]);
    }
  }

  for (int sum = total / 2; sum >= 0; sum--) {
    if (dp[n][sum]) {
      return total - 2 * sum;
    }
  }
  return 0;
}