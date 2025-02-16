#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
15 15 5 2
2
5
10
6
4
11
3
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

int find(vector<int>& parent, int x) {
  if (parent[x] == x)
    return x;
  else {
    int p = find(parent, parent[x]);
    parent[x] = p;
    return p;
  }
}

bool union2(vector<int>& parent, int x, int y, vector<int>& rank) {
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
  // freopen("fencedin.in", "r", stdin);
  // freopen("fencedin.out", "w", stdout);
  int A, B, n, m;
  cin >> A >> B >> n >> m;

  vector<int> a(n + 2);
  vector<int> b(m + 2);

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = A;

  b[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  b[m + 1] = B;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i <= n; i++) {
    a[i] = a[i + 1] - a[i];
  }
  for (int i = 0; i <= m; i++) {
    b[i] = b[i + 1] - b[i];
  }

  int totalNodes = (n + 1) * (m + 1);
  int cur = 0;
  vector<Edge> edges;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      // int cur = i * (m + 1) + j;
      cur++;
      if (j < m) edges.push_back(Edge(cur, cur + 1, a[i]));
      if (i < n) edges.push_back(Edge(cur, cur + (m + 1), b[j]));
    }
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(totalNodes);
  for (int i = 0; i < totalNodes; i++) {
    parent[i] = i;
  }

  vector<int> rank(totalNodes, 0);

  int count = 0;
  long long result = 0;
  for (auto edge : edges) {
    if (union2(parent, edge.u, edge.v, rank)) {
      // cout << edge.u << ", " << edge.v << ", " << edge.w << endl;
      result += edge.w;
      count++;
      if (count == totalNodes - 1) {
        break;
      }
    }
  }

  cout << result;
  return 0;
}