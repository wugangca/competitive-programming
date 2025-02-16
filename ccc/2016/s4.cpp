/*
1. dp[i][j] = true/false: v[i]...v[j] can be merged into 1 rice ball, i <= j
2. dp[i][i] = true: for single rice ball
   dp[i][i-1] = true: for two pointer method special case
3. ans = max (sum(i, j), if dp[i][j] is true)
4. Use prefix sum arrry to calculate sum(i,j)
5. for each pair (i, j), use two pointer method calculate dp[i][j]
6. (k1 = i, k2 = j), find sum1 == sum2, then check dp[i][k1], dp[k1+1][k2-1],
dp[k2][j]
7. dp should be calculated by intervals (bigger interval dp values are based on
smaller interval dp values). interval = 0. dp[i][i] = true interval = 1, 2, 3,
..., n-1 -> j = i+1, i+2,..., i+n-1
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> prefixSum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    prefixSum[i + 1] = prefixSum[i] + v[i];
  }
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
    if (i > 0) {
      dp[i][i - 1] = true;
    }
  }

  for (int interval = 1; interval < n; interval++) {
    for (int i = 0; i < n - interval; i++) {
      int j = i + interval;
      int k1 = i;
      int k2 = j;
      int sum1 = v[i];
      int sum2 = v[j];
      bool canMerge = false;
      while (k1 <= k2) {
        if (sum1 == sum2) {
          if (dp[i][k1] && dp[k1 + 1][k2 - 1] && dp[k2][j]) {
            canMerge = true;
            break;
          }
          k1++;
          k2--;
          sum1 += v[k1];
          sum2 += v[k2];
        } else if (sum1 < sum2) {
          k1++;
          sum1 += v[k1];
        } else {
          k2--;
          sum2 += v[k2];
        }
      }
      dp[i][j] = canMerge;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (dp[i][j]) {
        ans = max(ans, prefixSum[j + 1] - prefixSum[i]);
      }
    }
  }

  cout << ans << endl;
  return 0;
}