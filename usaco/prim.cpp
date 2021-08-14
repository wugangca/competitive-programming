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
  Edge(int u1, int v1, int w1) {
    u = u1;
    v = v1;
    w = w1;
  }
  friend bool operator<(const Edge& l, const Edge& r) { return l.w > r.w; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(Edge(u, v, w));
    adj[v].push_back(Edge(v, u, w));
  }

  priority_queue<Edge> q;
  int total = 0;
  vector<bool> chosen(n, false);
  int cur = 0;
  while (total < n - 1) {
    chosen[cur] = true;
    for (auto e : adj[cur]) {
      if (!chosen[e.v]) {
        q.push(e);
      }
    }

    Edge e = q.top();
    while (chosen[e.v]) {
      q.pop();
      if (q.empty()) {
        break;
      }
      e = q.top();
    }
    cout << e.u << ", " << e.v << ", " << e.w << endl;
    cur = e.v;
    total++;
  }

  return 0;
}