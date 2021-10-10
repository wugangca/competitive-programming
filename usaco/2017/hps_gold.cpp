#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<char> g(n + 1);
  vector<int> sumH(n + 1, 0);
  vector<int> sumP(n + 1, 0);
  vector<int> sumS(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    char g;
    cin >> g;
    sumH[i] = sumH[i - 1];
    sumP[i] = sumP[i - 1];
    sumS[i] = sumS[i - 1];
    if (g == 'H') {
      sumH[i]++;
    } else if (g == 'P') {
      sumP[i]++;
    } else {
      sumS[i]++;
    }
  }

  vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(sumH[i], max(sumP[i], sumS[i]));
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int m = 1; m < i; m++) {
        // the max of h,p, s between [m+1, i-1]
        int h = sumH[i - 1] - sumH[m - 1];
        int p = sumP[i - 1] - sumP[m - 1];
        int s = sumS[i - 1] - sumS[m - 1];
        int maxHPS = max(h, max(p, s));
        dp[i][j] = max(dp[i][j], dp[m][j - 1] + maxHPS);
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}