#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

/*
Sort all edges by length and cost.

We process edges with longer length and higher cost first
We do edges one by one.
for each edge, {u, v}
1. Remove it from the graph
2. Run dijkstra on the remaining graph
3. check the shorest distance between u and v.
   if the shortest distance > length of u,v, then we keep {u, v} and add it back
   Otherwise, remove this edge permantly


*/
struct Node {
  int num;
  long long dist;
  friend bool operator<(const Node &n1, const Node &n2) {
    return n1.dist > n2.dist;
  }
};

struct Edge {
  int u, v;
  long long len, cost;
  friend bool operator<(const Edge &l, const Edge &r) {
    if (l.len == r.len) {
      return l.cost > r.cost;
    } else {
      return l.len > r.len;
    }
  }
};

void dijkstra(const vector<vector<Node>> &adj, int start,
              vector<long long> &dist) {
  dist[start] = 0;
  priority_queue<Node> pq;
  // Only push the start node
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();
    int u = current.num;
    long long curDist = current.dist;

    if (curDist > dist[u]) {
      // Don’t check neighbors if the popped node distance is already bigger
      continue;
    }
    for (Node next : adj[u]) {
      int v = next.num;
      long long nextDist = dist[u] + next.dist;
      if (nextDist < dist[v]) {
        dist[v] = nextDist;
        pq.push({v, nextDist});
      }
    }
  }
}

long long uniform_cost_search(const vector<vector<Node>> &adj, int start,
                              int end, vector<long long> &dist) {
  dist[start] = 0;
  priority_queue<Node> pq;
  // Only push the start node
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();
    int u = current.num;
    long long curDist = current.dist;

    if (u == end) {
      return curDist;
    }

    if (curDist > dist[u]) {
      // Don’t check neighbors if the popped node distance is already bigger
      continue;
    }
    for (Node next : adj[u]) {
      int v = next.num;
      long long nextDist = dist[u] + next.dist;
      if (nextDist < dist[v]) {
        dist[v] = nextDist;
        pq.push({v, nextDist});
      }
    }
  }
  return LONG_LONG_MAX;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Node>> adj(n + 1);
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int u, v, l, c;
    cin >> u >> v >> l >> c;
    adj[u].push_back({v, l});
    adj[v].push_back({u, l});
    edges.push_back({u, v, l, c});
  }

  sort(edges.begin(), edges.end());

  long long cost = 0;
  for (auto edge : edges) {
    int u = edge.u;
    int v = edge.v;
    int l = edge.len;

    for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
      if ((*it).num == v && (*it).dist == l) {
        adj[u].erase(it);
        break;
      }
    }

    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
      if ((*it).num == u && (*it).dist == l) {
        adj[v].erase(it);
        break;
      }
    }

    std::vector<long long> dist(n + 1,
                                LONG_LONG_MAX); // Distance array for Dijkstra's
    // dijkstra(adj, u, dist);

    long long shortest = uniform_cost_search(adj, u, v, dist);

    // If there exists no indirect path that has length equal to or less than
    // l, than this edge is mandatory, add it to our plan
    if (shortest > edge.len) {

      // Re add edges to graph, update cost of plan

      adj[u].push_back({v, l});
      adj[v].push_back({u, l});
      cost += edge.cost;
    }
  }

  std::cout << cost << '\n';

  return 0;
}