#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<int> fj(n + 1);

  for (int i = 1; i <= n; i++) {
    char g;
    cin >> g;
    if (g == 'H') {
      fj[i] = 0;
    } else if (g == 'P') {
      fj[i] = 1;
    } else {
      fj[i] = 2;
    }
  }

  //   H P S
  // H 0 0 1
  // P 1 0 0
  // S 0 1 0
  vector<vector<int>> win{{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(k + 1, vector<int>(3, 0)));
  for (int i = 1; i <= n; i++) {
    for (int g = 0; g < 3; g++) {
      dp[i][0][g] = dp[i - 1][0][g] + win[g][fj[i]];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int g = 0; g < 3; g++) {
        dp[i][j][g] = max(dp[i - 1][j][g], max(dp[i - 1][j - 1][(g + 1) % 3],
                                               dp[i - 1][j - 1][(g + 2) % 3])) +
                      win[g][fj[i]];
      }
    }
  }
  cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << endl;
  return 0;
}