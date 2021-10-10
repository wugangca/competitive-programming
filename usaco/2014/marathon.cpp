#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("marathon.in", "r", stdin);
  freopen("marathon.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<int> x(n + 1, 0);
  vector<int> y(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  dp[0][0] = 0;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = j + 1; l < n && i + l - j - 1 <= k; l++) {
        int nextI = i + (l - j - 1);
        int nextJ = l;
      
      }
    }
  }
  return 0;
}