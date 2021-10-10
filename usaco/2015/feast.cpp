#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  int t, a, b;
  cin >> t >> a >> b;

  vector<bool> dp(t + 1, false);
  vector<bool> dp1(t + 1, false);
  dp[0] = true;
  for (int i = 1; i <= t; i++) {
    if ((i - a >= 0 && dp[i - a]) || (i - b >= 0 && dp[i - b])) {
      dp[i] = true;
      dp1[i / 2] = true;
    }
  }

  for (int i = 1; i <= t; i++) {
    if (dp1[i]) {
      if (i + a <= t) {
        dp1[i + a] = true;
      }
      if (i + b <= t) {
        dp1[i + b] = true;
      }
    }
  }
  for (int i = t; i >= 0; i--) {
    if (dp[i] || dp1[i]) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}