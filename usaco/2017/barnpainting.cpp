#include <bits/stdc++.h>
using namespace std;

int MOD = 100000000
7;

int solve(int node, int color, vector<vector<int>> &adj, vector<int> &colors,
          vector<vector<int>> &dp, int parent) {
  if (dp[node][color] >= 0) {
    return dp[node][color];
  }
  if (colors[node] > 0 && colors[node] != color) {
    return 0;
  }
  for (int v : adj[node]) {
    if (colors[v] == color) {
      return 0;
    }
  }

  long long ans = 1;
  for (int v : adj[node]) {
    if (v == parent) {
      continue;
    }
    long long ways = 0;
    for (int c = 1; c <= 3; c++) {
      if (c == color) {
        continue;
      }
      ways += solve(v, c, adj, colors, dp, node);
      ways %= MOD;
    }
    ans *= ways;
    ans %= MOD;
  }
  dp[node][color] = ans;
  return ans;
}

int main() {
  freopen("barnpainting.in", "r", stdin);
  freopen("barnpainting.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n + 1, vector<int>());

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> colors(n + 1, 0);

  for (int i = 0; i < k; i++) {
    int b, c;
    cin >> b >> c;
    colors[b] = c;
  }

  vector<vector<int>> dp(n + 1, vector<int>(4, -1));
  int ans = solve(1, 1, adj, colors, dp, 0);

  vector<vector<int>> dp1(n + 1, vector<int>(4, -1));
  ans += solve(1, 2, adj, colors, dp1, 0);

  vector<vector<int>> dp2(n + 1, vector<int>(4, -1));
  ans += solve(1, 3, adj, colors, dp2, 0);

  cout << ans % MOD << endl;
}