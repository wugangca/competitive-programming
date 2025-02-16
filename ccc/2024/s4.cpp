#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* Do a DFS on the connected graph.
 Record the depth of each node and color the path alternatively based on the
 depth
*/

void dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &visited,
         int current, string &color, int depth) {
  for (pair<int, int> next : adj[current]) {
    if (visited[next.first]) {
      continue;
    }
    visited[next.first] = true;
    if (depth % 2 == 0) {
      color[next.second] = 'R';
    } else {
      color[next.second] = 'B';
    }
    dfs(adj, visited, next.first, color, depth + 1);
  }
}
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

  string color(m, 'G');
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  vector<bool> visited(n + 1, false);

  for (int i = 1; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(adj, visited, i, color, 0);
    }
  }
  cout << color << endl;
}