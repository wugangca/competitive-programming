#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 1));
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    grid[r - 1][c - 1] = 0;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    dp[0][i] = grid[0][i];
    dp[i][0] = grid[i][0];
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (grid[i][j] == 1) {
        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }
  cout << ans;
}