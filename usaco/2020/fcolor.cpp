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

void unite(vector<int>& parent, int x, int y) {
    parent[y] = x;
}

int main() {
  freopen("fcolor.in", "r", stdin);
  freopen("fcolor.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > 1) {
      q.push(i);
    }
  }
  vector<int> parent(n+1, 0);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    if (adj[a].size() <= 1) {
      continue;
    }
    sort(adj[a].begin(), adj[a].end());
    int x = find(parent, adj[a][0]);
    int prev =  adj[a][0];
    for (int i = 1; i < adj[a].size(); i++) {
      int u = adj[a][i];
      if (u == prev) {
        continue;
      }
      prev = u;

      u = find (parent, u);
      if (x != u) {
         unite(parent, x, u);
      }
      for (int v: adj[u]) {
        adj[x].push_back(find(parent, v));
      }
      adj[u].clear();
    } 

    if (adj[x].size() > 1) {
      q.push(x);
    }
    adj[a].clear();
    adj[a].push_back(x);
  }

  vector<int> colors(n+1, 0);
  int clr = 1;
  for (int i = 1; i <= n; i++) {
     int p = find(parent, i);
     if (colors[p] == 0) {
       colors[p] = clr++;
     }
     cout << colors[p] << endl;
  }

  
}
