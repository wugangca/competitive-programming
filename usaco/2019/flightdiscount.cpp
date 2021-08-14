
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
5 7
0 1 8
0 2 5
1 2 9
1 3 11
2 3 15
2 4 10
3 4 7
*/
struct Edge {
  int u, v, w;
  Edge(int u1, int v1, int w1) {
    u = u1;
    v = v1;
    w = w1;
  }
  friend bool operator<(const Edge& l, const Edge& r) { return l.w > r.w; }
};

struct Node {
  int num, distance;
  bool usedCoupon;

  Node(int n, int dist, bool used) {
    num = n;
    distance = dist;
    usedCoupon = used;
  }
  friend bool operator<(const Node& l, const Node& r) {
    return l.distance > r.distance;
  }
};

int dijkstra(const vector<vector<Edge>>& adj, int n) {
  priority_queue<Node> q;
  q.push(Node(1, 0, false));

  vector<vector<int>> dist(n + 1);
  for (int i = 0; i <= n; i++) {
    dist[i].push_back(INT_MAX);
    dist[i].push_back(INT_MAX);
  }
  dist[1][0] = 0;
  dist[1][1] = 0;

  vector<bool> visited(n + 1, false);

  while (!q.empty()) {
    Node node = q.top();
    int num = node.num;
    if (num == n) {
      break;
    }
    visited[num] = true;
    q.pop();
    for (Edge edge : adj[num]) {
      int u = edge.u;
      int v = edge.v;
       if (visited[v]) continue;
      if (node.usedCoupon) {
        int d = dist[edge.u][1] + edge.w;
        if (d < dist[v][1]) {
          dist[v][1] = d;
          q.push(Node(v, dist[v][1], true));
        }
      } else {
        int d = dist[edge.u][0] + edge.w;
        if (d < dist[v][0]) {
          dist[v][0] = d;
          q.push(Node(v, dist[v][0], false));
        }

        d = dist[edge.u][0] + edge.w / 2;
        if (d < dist[v][1]) {
          dist[v][1] = d;
          q.push(Node(v, dist[v][1], true));
        }
      }
    }
  }

  return min(dist[n][0], dist[n][1]);
}
int main() {
  // freopen("pump.in", "r", stdin);
  // freopen("pump.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(Edge(u, v, w));
    adj[v].push_back(Edge(v, u, w));
  }

  cout << dijkstra(adj, n);
  return 0;
}