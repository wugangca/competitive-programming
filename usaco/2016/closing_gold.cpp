#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x) {
  if (parent[x] == x)
    return x;
  else {
    int p = find(parent, parent[x]);
    parent[x] = p;
    return p;
  }
}

int unite(vector<int>& parent, vector<int>& rank, int px, int py) {
  if (rank[px] < rank[py]) {
    parent[px] = py;
    return px;
  } else if (rank[px] > rank[py]) {
    parent[py] = px;
    return py;
  } else {
    parent[py] = px;
    rank[px]++;
    return py;
  }
}

int main() {
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> close(n + 1, 0);
  vector<int> u(m + 1);
  vector<int> v(m + 1);

  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
  }

  vector<int> order(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> close[i];
    order[close[i]] = i;
  }

  for (int i = 0; i < m; i++) {
    if (order[u[i]] < order[v[i]]) {
      adj[u[i]].push_back(v[i]);
    } else {
      adj[v[i]].push_back(u[i]);
    }
  }

  vector<string> ans(n, "");
  vector<int> parent(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  vector<int> rank(n + 1, 0);
  set<int> roots;
  for (int i = n - 1; i >= 0; i--) {
    int x = close[i];
    roots.insert(x);
    for (int y : adj[x]) {
      int px = find(parent, x);
      int py = find(parent, y);
      if (px != py) {
        int remove = unite(parent, rank, px, py);
        if (roots.find(px) != roots.end() && roots.find(py) != roots.end()) {
          roots.erase(remove);
        }
      }
    }
    ans[i] = (roots.size() == 1) ? "YES" : "NO";
  }

  for (string a : ans) {
    cout << a << endl;
  }

  return 0;
}