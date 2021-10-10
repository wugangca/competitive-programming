#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
  vector<int> dp(amount + 1, -1);
  dp[0] = 0;
  for (int i = 0; i <= amount; i++) {
    if (dp[i] >= 0) {
      for (int coin : coins) {
        if (i <= amount - coin) {
          if (dp[i + coin] < 0 || dp[i + coin] > dp[i] + 1) {
            dp[i + coin] = dp[i] + 1;
          }
        }
      }
    }
  }
  return dp[amount];
}