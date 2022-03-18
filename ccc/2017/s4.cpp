/*
1. First n-1 edges are the original plan
2. We need to find a minimum spanning tree (MST) that closes to the original
plan as much as possible.
3. Assign an index (starts from 0) to each edge: index < n-1 means original plan
4. Use Kruskal algorithm with path compression and union by rank.
5. Order edges by weight and index, if two edges have the same weight, we choose
the smaller index. In this way, we can get a minimum spanning tree that closes
to the original plan.
6. In the result MST, if an edge's index is outside the first (n-1) index, then
we need to switch it in.
7. We can apply d on only one edge. Therefore, we can reduce the day at most 1.
8. For the generated MST, We can apply the enhancer (d) to the edge with the
maximum weight. This is the our optimal solution.
9. If all MST edges are in the original plan, no way to reduce more. 
   If you want to apply d to an outside edge and switch in, we can do the same to apply d
   on an MST edge (with smaller weight) 
10. The only way to reduce 1 day is to:
    Apply d on an edge which is in the original plan (index < n-1) and is not in the MST
    Replace an edge in the MST but not in the original plan (index >= n-1)
11. The reason we didn't choose that edge (in the original plan) in MST is either
    1. the edge introduce a cycle
    2. the edge the weight is too big (> maxWeight)
    Since the we cannot switch an edge in for a cycle, the newly chosen edge must be >maxWeight

12. Since the newly chose edge's weight > maxWeight, 
    its weight must be <= d, i.e. the enhancer will zero the new edge. 
    if >d, we will increse the total weight if we switch it in. Originally, we
    reduce the MST with min(maxWeigt, d) Since the switched-in edge's weight is >maxWeight, 
    we must make sure we still reduce the same amount. Therefore, the new weight must be <=d.
13. The switched-in edge must be able form a spanning tree. i.e. Kruskal
algorithm also applies.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w, index;
  friend bool operator<(const Edge& l, const Edge& r) {
    if (l.w == r.w) {
      return l.index < r.index;
    } else {
      return l.w < r.w;
    }
  }
};

int find(vector<int>& parent, int x) {
  if (parent[x] == x) {
    return x;
  }

  int p = find(parent, parent[x]);
  parent[x] = p;
  return p;
}

bool uninion(vector<int>& parent, vector<int>& rank, int x, int y) {
  int px = find(parent, x);
  int py = find(parent, y);

  if (px == py) {
    return false;
  } else {
    if (rank[px] < rank[py]) {
      parent[px] = py;
    } else if (rank[px] > rank[py]) {
      parent[py] = px;
    } else {
      parent[py] = px;
      rank[px]++;
    }
    return true;
  }
}

int main() {
  int n, m, d;
  cin >> n >> m >> d;

  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u - 1, v - 1, w, i});
  }

  sort(edges.begin(), edges.end());

  vector<int> parent(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  vector<int> rank(n, 0);

  int total = 0;
  int ans = 0;
  Edge maxEdge = {0, 0, 0, 0};
  for (auto edge : edges) {
    if (uninion(parent, rank, edge.u, edge.v)) {
      if (edge.index >= n - 1) {
        ans++;
      }
      maxEdge = edge;
      total++;
      if (total == n - 1) {
        break;
      }
    }
  }

  if (maxEdge.index >= n - 1) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }

    int maxWeight = maxEdge.w;

    for (Edge e : edges) {
      if (find(parent, e.u) == find(parent, e.v)) {
        continue;
      }

      if (e.w < maxWeight || (e.w == maxWeight && e.index < n - 1)) {
        uninion(parent, rank, e.u, e.v);
      } else if (e.index < n - 1 && e.w <= d) {
        ans--;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}
