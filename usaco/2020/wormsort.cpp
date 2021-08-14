#include <bits/stdc++.h>

using namespace std;
struct Edge {
  int u, v, w;
};

bool dfs(vector<vector<Edge>>& adj, vector<int>& visited, int u, int group,
         int w) {
  visited[u] = group;
  for (Edge edge : adj[u]) {
    if (edge.w >= w && visited[edge.v] == 0) {
      dfs(adj, visited, edge.v, group, w);
    }
  }
  return false;
}

bool f(vector<vector<Edge>>& adj, vector<int>& p, int n, int w) {
  vector<int> visited(n + 1, 0);
  int group = 1;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      dfs(adj, visited, i, group++, w);
    }
  }

  for (int i = 1; i <= n; i++) {
    int source = p[i];
    int dest = i;
    if (source != dest && visited[source] != visited[dest]) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  int n, m;
  cin >> n >> m;

  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  bool good = true;
  for (int i = 1; i <= n; i++) {
    if (i != p[i]) {
      good = false;
      break;
    }
  }

  if (good) {
    cout << -1;
    return 0;
  }

  vector<vector<Edge>> adj(n + 1);
  int minW = INT_MAX;
  int maxW = 0;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({u, v, w});
    adj[v].push_back({v, u, w});
    maxW = max(maxW, w);
    minW = min(minW, w);
  }

  int low = minW;
  int high = maxW;
  int ans;

  while (low < high) {
    int mid = (low + high) / 2;
    if (f(adj, p, n, mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << ans << endl;
  return 0;
}