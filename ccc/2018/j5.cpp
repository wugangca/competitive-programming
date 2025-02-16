#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int o;
      cin >> o;
      adj[i].push_back(o);
    }
  }
  queue<pair<int, int>> q;
  vector<int> visited(n + 1, false);
  q.push({1, 1});
  visited[0] = true;
  visited[1] = true;
  int ans = -1;
  while (!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    int u = front.first;
    for (int v : adj[u]) {
      if (!visited[v]) {
        q.push({v, front.second + 1});
        visited[v] = true;
        if (adj[v].size() == 0 && ans < 0) {
          ans = front.second + 1;
        }
      }
    }
  }
  bool allvisited = true;
  for (bool v : visited) {
    if (!v) {
      allvisited = false;
      break;
    }
  }
  if (allvisited) {
    cout << "Y" << endl;
  } else {
    cout << "N" << endl;
  }
  cout << ans << endl;
}