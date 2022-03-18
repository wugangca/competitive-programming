#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0) {
    return "";
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

  int ans = 1;
  string r = s.substr(0, 1);
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  for (int i = 0; i < n - 1; i++) {
    dp[i][i + 1] = (s[i] == s[i + 1]);
    if (dp[i][i + 1]) {
      ans = 2;
      r = s.substr(i, 2);
    }
  }

  for (int len = 2; len < n; len++) {
    for (int i = 0; i < n - len; i++) {
      int j = i + len;
      dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
      if (dp[i][j] && len + 1 > ans) {
        ans = len + 1;
        r = s.substr(i, len + 1);
      }
    }
  }

  return r;
}
