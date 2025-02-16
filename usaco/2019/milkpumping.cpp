
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
  int u, v, w, f;
  Edge(int u1, int v1, int w1, int f1) {
    u = u1;
    v = v1;
    w = w1;
    f = f1;
  }
  friend bool operator<(const Edge& l, const Edge& r) { return l.w > r.w; }
};

struct Node {
  int num, distance;

  Node(int n, int dist) {
    num = n;
    distance = dist;
  }
  friend bool operator<(const Node& l, const Node& r) {
    return l.distance > r.distance;
  }
};

int dijkstra(const vector<vector<Edge>>& adj, int n, int minFlow) {
  priority_queue<Node> q;
  q.push(Node(1, 0));

  vector<int> dist(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    dist[i] = INT_MAX;
  }

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
      if (edge.f < minFlow) continue;
      dist[v] = min(dist[v], dist[edge.u] + edge.w);
      q.push(Node(v, dist[v]));
    }
  }

  return dist[n];
}

int ucs(const vector<vector<Edge>>& adj, int n, int minFlow) {
  priority_queue<Node> q;
  q.push(Node(1, 0));

  vector<bool> visited(n + 1, false);

  while (!q.empty()) {
    Node node = q.top();
    int num = node.num;
    if (num == n) {
      return node.distance;
    }
    visited[num] = true;
    q.pop();
    for (Edge edge : adj[num]) {
      int u = edge.u;
      int v = edge.v;
      if (visited[v]) continue;
      if (edge.f < minFlow) continue;
      q.push(Node(v, node.distance + edge.w));
    }
  }

  return INT_MAX;
}

int main() {
  freopen("pump.in", "r", stdin);
  freopen("pump.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w, f;
    cin >> u >> v >> w >> f;
    adj[u].push_back(Edge(u, v, w, f));
    adj[v].push_back(Edge(v, u, w, f));
  }

  double result = 0;
  for (int i = 1; i < 1000; i++) {
    int c = ucs(adj, n, i);
    if (c == INT_MAX) {
      continue;
    }
    result = max(result, i * 1.0 / c);
  }

  cout << (int)(result * 1000000);
  return 0;
}