#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int>& p1, pair<int, int>& p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) +
         (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
  freopen("checklist.in", "r", stdin);
  freopen("checklist.out", "w", stdout);
  int H, G;
  cin >> H >> G;
  int MAX_DIST = 2000000001;

  vector<pair<int, int>> h(H + 1);

  vector<pair<int, int>> g(G + 1);

  int x, y;
  for (int i = 1; i <= H; i++) {
    cin >> x >> y;
    h[i] = {x, y};
  }
  h[0] = h[1];

  for (int i = 1; i <= G; i++) {
    cin >> x >> y;
    g[i] = {x, y};
  }
  g[0] = g[1];

  vector<vector<vector<int>>> dp(
      H + 1, vector<vector<int>>(G + 1, vector<int>(2, MAX_DIST)));

  dp[0][0][0] = 0;
  for (int i = 1; i <= H; i++) {
    dp[i][0][0] = dp[i - 1][0][0] + dist(h[i - 1], h[i]);
    dp[i][0][1] = MAX_DIST;
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= G; j++) {
      int up0 = dp[i - 1][j][0] + dist(h[i - 1], h[i]);
      int up1 = dp[i - 1][j][1] + dist(g[j], h[i]);
      dp[i][j][0] = min(up0, up1);

      int left0 = dp[i][j - 1][0] + dist(h[i], g[j]);
      int left1 = dp[i][j - 1][1] + dist(g[j - 1], g[j]);
      dp[i][j][1] = min(left0, left1);
    }
  }

  cout << dp[H][G][0] << endl;
  return 0;
}