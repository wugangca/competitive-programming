#include <bits/stdc++.h>

using namespace std;
struct Edge {
  int u, v, w;
  bool operator<(Edge& e) { return w < e.w; }
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

int unite(vector<int>& parent, vector<int>& size, int px, int py) {
  if (size[px] < size[py]) {
    parent[px] = py;
    size[py] += size[px];
    return size[py];
  } else {
    parent[py] = px;
    size[px] += size[py];
    return size[px];
  }
}

int main() {
  freopen("tractor.in", "r", stdin);
  freopen("tractor.out", "w", stdout);
  int n;
  cin >> n;
  int total = n * n;
  int half = total / 2 + total % 2;
  vector<int> grid(total);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i * n + j];
    }
  }

  vector<Edge> edges;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int node = i * n + j;
      if (i > 0) {
        int up = node - n;
        edges.push_back({up, node, abs(grid[up] - grid[node])});
      }
      if (i < n - 1) {
        int down = node + n;
        edges.push_back({down, node, abs(grid[down] - grid[node])});
      }
      if (j > 0) {
        int left = node - 1;
        edges.push_back({left, node, abs(grid[left] - grid[node])});
      }
      if (j < n - 1) {
        int right = node + 1;
        edges.push_back({right, node, abs(grid[right] - grid[node])});
      }
    }
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(total, 0);
  vector<int> size(total, 1);

  for (int i = 0; i < total; i++) {
    parent[i] = i;
  }

  for (Edge e : edges) {
    int px = find(parent, e.u);
    int py = find(parent, e.v);
    if (px == py) {
      continue;
    }
    int s = unite(parent, size, px, py);
    if (s >= half) {
      cout << e.w << endl;
      break;
    }
  }
}