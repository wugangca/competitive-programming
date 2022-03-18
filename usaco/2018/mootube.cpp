#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u;
  int v;
  int w;
  bool operator<(Edge& e) { return e.w < w; }
};

struct Query {
  int k;
  int v;
  int i;
  bool operator<(Query& q) { return q.k < k; }
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

bool unite(vector<int>& parent, vector<int>& size, int x, int y) {
  int px = find(parent, x);
  int py = find(parent, y);
  if (px == py) {
    return false;
  } else {
    if (size[px] < size[py]) {
      parent[px] = py;
      size[py] += size[px];
    } else {
      parent[py] = px;
      size[px] += size[py];
    }
    return true;
  }
}

int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);
  int n, q;
  cin >> n >> q;

  vector<Edge> edges(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  sort(edges.begin(), edges.end());

  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].k >> queries[i].v;
    queries[i].i = i;
  }
  sort(queries.begin(), queries.end());

  vector<int> ans(q);
  vector<int> parent(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  vector<int> size(n + 1, 1);

  int index = 0;
  for (Query q : queries) {
    int k = q.k;
    while (index < n-1) {
      Edge e = edges[index];
      if (e.w >= k) {
        unite(parent, size, e.u, e.v);
        index++;
      } else {
        break;
      }
    }
    int p = find(parent, q.v);
    ans[q.i] = size[p] - 1;
  }

  for (int a : ans) {
    cout << a << endl;
  }

  return 0;
}