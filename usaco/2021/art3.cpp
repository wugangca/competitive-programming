#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 305));

  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }

  for (int len = 1; len < n; len++) {
    for (int i = 0; i < n - len; i++) {
      int j = i + len;
      if (v[i] == v[j]) {
        dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
      } else {
        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
      }
    }
  }

  cout << dp[0][n - 1];
  return 0;
}