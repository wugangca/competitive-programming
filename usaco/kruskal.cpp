#include <algorithm>
#include <iostream>
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
  friend bool operator<(const Edge &l, const Edge &r) { return l.w < r.w; }
};

int find(vector<int> &parent, int x) {
  if (parent[x] == x)
    return x;
  else {
    int p = find(parent, parent[x]);
    parent[x] = p;
    return p;
  }
}

bool unionRank(vector<int> &parent, int x, int y, vector<int> &rank) {
  int px = find(parent, x);
  int py = find(parent, y);
  if (px == py) {
    return false;
  } else {
    if (rank[x] < rank[y]) {
      parent[px] = py;
    } else {
      parent[py] = px;
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
    }
    return true;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(n);
  vector<int> rank(n, 1);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  int total = 0;
  for (auto edge : edges) {
    if (unionRank(parent, edge.u, edge.v, rank)) {
      cout << edge.u << ", " << edge.v << ", " << edge.w << endl;
      total++;
      if (total == n - 1) {
        break;
      }
    }
  }

  return 0;
}