#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (d > n) return -1;
    vector<vector<int>> dp(n, vector<int>(d, INT_MAX));

    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (jobDifficulty[i] > mx) {
        mx = jobDifficulty[i];
      }
      dp[i][0] = mx;
    }
    for (int j = 1; j < d; j++) {
      for (int i = j; i < n; i++) {
        mx = 0;
        for (int k = i - 1; k >= j - 1; k--) {
          if (jobDifficulty[k + 1] > mx) {
            mx = jobDifficulty[k + 1];
          }
          dp[i][j] = min(dp[i][j], dp[k][j - 1] + mx);
        }
      }
    }
    return dp[n - 1][d - 1];
  }
};