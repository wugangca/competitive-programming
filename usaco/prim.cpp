#include <iostream>
#include <queue>
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
  friend bool operator<(const Edge& l, const Edge& r) { return l.w > r.w; }
};

struct Node {
  int num, w;
  friend bool operator<(const Node& n1, const Node& n2) { return n1.w > n2.w; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({u, v, w});
    adj[v].push_back({v, u, w});
  }

  priority_queue<Edge> q;
  int total = 0;
  vector<bool> chosen(n, false);
  int cur = 0;
  while (total < n - 1) {
    chosen[cur] = true;
    for (auto edge : adj[cur]) {
      if (!chosen[edge.v]) {
        q.push(edge);
      }
    }
    while (!q.empty() && chosen[q.top().v]) {
      q.pop();
    }
    Edge e = q.top();
    cout << e.u << ", " << e.v << ", " << e.w << endl;
    cur = e.v;
    total++;
  }

  return 0;
}