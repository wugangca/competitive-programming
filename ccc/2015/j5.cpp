#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int start, vector<vector<vector<int>>>& dp) {
  if (n < k) {
    return 0;
  }
  if (k == n) {
    return 1;
  }
  if (k == 1) {
    return 1;
  }

  if (dp[n][k][start] > 0) {
    return dp[n][k][start];
  }
  int total = 0;

  for (int i = start; i <= n / k; i++) {
    total += solve(n - i, k - 1, i, dp);
  }
  dp[n][k][start] = total;
  return total;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(k + 1, vector<int>(n, 0)));
  cout << solve(n, k, 1, dp);
}