#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
4
3
6
9
10
*/
struct Edge {
  int u, v, w;
  Edge(int u1, int v1, int w1) {
    u = u1;
    v = v1;
    w = w1;
  }
  friend bool operator<(const Edge& l, const Edge& r) { return l.w < r.w; }
};

int main() {
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> teams(n);

  for (int i = 0; i < n; i++) {
    cin >> teams[i];
  }

  vector<vector<Edge>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int score = teams[i] ^ teams[j];
      adj[i].push_back(Edge(i, j, score));
      adj[j].push_back(Edge(j, i, score));
    }
  }

  long long result = 0;
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
    // cout << e.u << ", " << e.v << ", " << e.w << endl;
    cur = e.v;
    total++;
    result += e.w;
  }

  cout << result;
  return 0;
}