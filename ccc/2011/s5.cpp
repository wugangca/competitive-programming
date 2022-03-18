#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int on;
    cin >> on;
    prefix[i] = prefix[i - 1] + on;
  }

   vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
  // for (int i = 0; i <= n; i++) {
  //   dp[i][i] = 0;
  // }

  for (int len = 0; len < n; len++) {
    for (int i = 1; i <= n - len; i++) {
      int j = i + len;
      if (len <= 3) {
        int onCount = prefix[j] - prefix[i - 1];

        dp[i][j] = len + 1 - onCount;

      } else {
        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
      }
    }
  }
  cout << dp[1][n];
}