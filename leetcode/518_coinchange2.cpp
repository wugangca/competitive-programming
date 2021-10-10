#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
  vector<int> dp(amount + 1, 0);
  dp[0] = 1;
  for (int coin : coins) {
    for (int i = 1; i <= amount; i++) {
      if (i - coin >= 0) {
        dp[i] += dp[i - coin];
      }
    }
  }
  return dp[amount];
}

int change2(int amount, vector<int>& coins) {
  vector<int> dp(amount + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (i - coin >= 0) {
        dp[i] += dp[i - coin];
      }
    }
  }

  return dp[amount];
}

int main() {
  vector<int> coins{1, 3, 4};
  int amount = 5;
  cout << "Unique: " << change(amount, coins) << endl;
  cout << "All: " << change2(amount, coins) << endl;
}