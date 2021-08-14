/*

Sample graph 1:
    5
    |
0 - 1 - 6
|
2 - 3 - 4
Pho:
5 2

Sample graph 2:
    6           4
    |           |
5 - 1 - 0 - 2 - 3 -7

Pho:
0 6 4 3 7

1. The optimal solution should be started with a pho
2. Remove redundant nodes: nodes that won't reach a pho if we start with a pho
   For example, node 3, 4, 6 in sample graph 1 and node 5 in sample graph 2
3. We can travel on the main route, then visit branches for the other phos.
   Each time we finsih the branch, we come back to the main route and continue.
   For example (sample 2):
   6-1-0-2-3 -4-3 -7
   At the node 3, we travel the branch for node 4 and then come back.
   Sample 1's main route is 5-1-0-2, no branches
4. To minimize the overall number of edges, we need to maximize the main route.
   This is the diameter of the graph (on pho reachable nodes only).
5. Standard way to calculate the diameter of the graph :
   1. Start with a node, DFS or BFS to reach the farest node.
   2. Start with the farest node, DFS or BFS again to reach the farest node.
   3. The distance of the second step is the diameter of the graph.

6. We need to visit all pho reachable nodes at least once.
   We visit nodes on the diameter route once, and nodes on branches twice.

   let anser = number of edges of the optimail solution
       diameter = number of edges of the graph diameter

   Therefore:

   answer + diameter = visit all pho reachable nodes twice
   ->
   answer = 2 ("total pho reachable nodes" - 1) - diameter

*/
#include <bits/stdc++.h>
using namespace std;

bool dfsTrim(int u, vector<vector<int>>& adj, vector<bool>& phoReachable,
             vector<bool>& visited) {
  bool pho = phoReachable[u];
  visited[u] = true;
  for (int v : adj[u]) {
    if (visited[v]) {
      continue;
    }
    pho |= dfsTrim(v, adj, phoReachable, visited);
  }
  phoReachable[u] = pho;
  return pho;
}

pair<int, int> bfs(int u, int n, vector<vector<int>>& adj,
                   vector<bool>& phoReachable) {
  vector<bool> visited(n, false);
  queue<pair<int, int>> q;
  q.push({u, 0});
  visited[u] = true;
  pair<int, int> last;
  while (!q.empty()) {
    last = q.front();
    q.pop();
    for (int v : adj[last.first]) {
      if (visited[v] || !phoReachable[v]) {
        continue;
      }
      q.push({v, last.second + 1});
      visited[v] = true;
    }
  }
  return last;
}

int diameter(int u, int n, vector<vector<int>>& adj,
             vector<bool>& phoReachable) {
  pair<int, int> last = bfs(u, n, adj, phoReachable);
  last = bfs(last.first, n, adj, phoReachable);
  return last.second;
}

int main() {
  int n, m;

  cin >> n >> m;

  vector<bool> phoReachable(n, false);
  int phoIdx;
  for (int i = 0; i < m; i++) {
    cin >> phoIdx;
    phoReachable[phoIdx] = true;
  }

  vector<vector<int>> adj(n, vector<int>());

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n, false);
  dfsTrim(phoIdx, adj, phoReachable, visited);
  int d = diameter(phoIdx, n, adj, phoReachable);

  int total = accumulate(phoReachable.begin(), phoReachable.end(), 0);

  int ans = 2 * (total - 1) - d;
  cout << ans << endl;

  return 0;
}