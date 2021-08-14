#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& open,
         int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (open[v] && !visited[v]) {
      dfs(adj, visited, open, v);
    }
  }
}

int main() {
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bool> open(n + 1, true);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    vector<bool> visited(n + 1, false);
    int u = 1;
    while (!open[u] && u <= n) {
      u++;
    }
    dfs(adj, visited, open, u);
    bool connected = true;
    for (int j = 1; j <= n; j++) {
      if (visited[j] != open[j]) {
        connected = false;
        break;
      }
    }
    if (connected) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    cin >> u;
    open[u] = false;
  }

  return 0;
}