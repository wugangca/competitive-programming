#include <algorithm>
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
  friend bool operator<(const Edge& l, const Edge& r) { return l.w < r.w; }
};

int find(const vector<int>& parent, int x) {
  if (parent[x] == x)
    return x;
  else
    return find(parent, parent[x]);
}

bool uninion(vector<int>& parent, int x, int y) {
  int px = find(parent, x);
  int py = find(parent, y);

  if (px == py) {
    return false;
  } else {
    if (rand() % 2 == 0) {
      parent[px] = py;
    } else {
      parent[py] = px;
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
    edges.push_back(Edge(u, v, w));
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  
  int total = 0;
  for (auto edge : edges) {
     if (uninion (parent, edge.u, edge.v)) {
        cout << edge.u << ", " << edge.v << ", " << edge.w << endl;
        total++;
        if (total == n-1) {
          break;
        }
     }
  }

  return 0;
}