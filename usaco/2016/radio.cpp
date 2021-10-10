#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int>& p1, pair<int, int>& p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) +
         (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
  freopen("radio.in", "r", stdin);
  freopen("radio.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  int fx, fy, bx, by;
  cin >> fx >> fy >> bx >> by;

  vector<pair<int, int>> f, b;

  f.push_back({fx, fy});
  b.push_back({bx, by});

  string fPath, bPath;
  cin >> fPath >> bPath;

  for (char ch : fPath) {
    if (ch == 'N') {
      fy++;
    } else if (ch == 'S') {
      fy--;
    } else if (ch == 'E') {
      fx++;
    } else {
      fx--;
    }
    f.push_back({fx, fy});
  }

  for (char ch : bPath) {
    if (ch == 'N') {
      by++;
    } else if (ch == 'S') {
      by--;
    } else if (ch == 'E') {
      bx++;
    } else {
      bx--;
    }
    b.push_back({bx, by});
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + dist(f[i], b[0]);
  }

  for (int j = 1; j <= m; j++) {
    dp[0][j] = dp[0][j - 1] + dist(f[0], b[j]);
  }

  for (int i = 1; i < f.size(); i++) {
    for (int j = 1; j < b.size(); j++) {
      dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + dist(f[i], b[j]);
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}