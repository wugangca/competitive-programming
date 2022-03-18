/*
Construct two directed graphs. One for taller and one for shorter.
DFS/BFS on the two graphs, starting from p
if we can find q during the traversal, we can know p is taller/shorter than q
otherwise, we output unknown.
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, int q) {
  if (u == q) {
    return true;
  }
  visited[u] = true;
  bool exist = false;
  for (int v : adj[u]) {
    if (visited[v]) {
      continue;
    }
    exist |= dfs(adj, v, visited, q);
  }
  return exist;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj_tall(n + 1);
  vector<vector<int>> adj_short(n + 1);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj_tall[x].push_back(y);
    adj_short[y].push_back(x);
  }

  int p, q;
  cin >> p >> q;

  vector<bool> visited(n + 1, false);
  if (dfs(adj_tall, p, visited, q)) {
    cout << "yes";
  } else {
    vector<bool> visited1(n + 1, false);
    if (dfs(adj_short, p, visited1, q)) {
      cout << "no";
    } else {
      cout << "unknown";
    }
  }
}