#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1, 0);
  vector<int> sum(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  int high = 0;
  for (int i = 1; i <= n; i++) {
    high = max(high, a[i]);
    dp[i][0] = i * high - sum[i];
    // dp[i][j]: first i groups with j changes
    // dp[i][j]= min of
    //  first 1 group with (j-1) changes + 1 more change,
    //  since we have only 1 change,
    //  change to max(a[2], a[3], ..., a[i])
    //  waste = (i-1)*max - sum(2, i);
    //  first 2 group with (j-1) changes + 1 more change,
    //  since we have only 1 change,
    //  change to max(a[3], a[4], ..., a[i])
    //  waste = (i-2)*max - sum(3, i);
    //  ....
    //  first i-1 group with  (j-1) changes + 1 more change,
    //  since we have only 1 change,
    //  change to max(a[i])
    //  waste = (i-1)*max - sum(i, i);
    for (int j = 1; j <= k; j++) {
      int minWaste = INT_MAX;
      int mx = 0;
      for (int m = i; m > 0; m--) {
        mx = max(mx, a[m]);
        minWaste = min(minWaste, dp[m - 1][j - 1] + mx * (i - m + 1) -
                                     (sum[i] - sum[m - 1]));
      }
      dp[i][j] = minWaste;
    }
  }
  cout << dp[n][k] << endl;

  return 0;
}