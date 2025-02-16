#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("248.in", "r", stdin);
  // freopen("248.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, -1));

  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i][i] = v[i];
    ans = max(ans, dp[i][i]);
  }

  for (int len = 1; len < n; len++) {
    for (int i = 0; i < n - len; i++) {
      int j = i + len;
      for (int k = i; k < j; k++) {
        if (dp[i][k] == dp[k + 1][j]) {
          dp[i][j] = max(dp[i][j], dp[i][k] + 1);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}

