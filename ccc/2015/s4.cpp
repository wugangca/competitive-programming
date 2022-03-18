/*
Use BFS to traverse all nodes
Each time we visit a node, we record its min. damage and min. time.
Next time we visit the same node again, we check if we will introduce new min.
damage or min. time if yes, we will traverse this node again. This is because
there exist multiple paths between two nodes (with different time or damage) We
may traverse the same node again with a different route.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, t, h;
};

struct Node {
  int v, time, damage;
};

int main() {
  int k, n, m;
  cin >> k >> n >> m;

  vector<vector<Edge>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, t, h;
    cin >> a >> b >> t >> h;
    adj[a].push_back({b, t, h});
    adj[b].push_back({a, t, h});
  }

  int start, end;
  cin >> start >> end;

  vector<Node> visited(n + 1, {0, INT_MAX, INT_MAX});
  queue<Node> q;
  q.push({start, 0, 0});
  while (!q.empty()) {
    Node source = q.front();
    q.pop();

    for (Edge edge : adj[source.v]) {
      int v = edge.v;
      int damage = source.damage + edge.h;
      int time = source.time + edge.t;
      if (damage >= k) {
        continue;
      }
      if (damage < visited[v].damage || time < visited[v].time) {
        visited[v].damage = min(visited[v].damage, damage);
        visited[v].time = min(visited[v].time, time);
        q.push({v, time, damage});
      }
    }
  }

  if (visited[end].time != INT_MAX) {
    cout << visited[end].time;
  } else {
    cout << -1;
  }

  return 0;
}