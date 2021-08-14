#include <bits/stdc++.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Edge {
  int u, v;
  long long w;
};

int dfs(vector<vector<Edge>>& adj, vector<bool>& visited, int u, long long x) {
  visited[u] = true;
  int total = 1;
  for (Edge edge : adj[u]) {
    if (!visited[edge.v] && edge.w <= x) {
      total += dfs(adj, visited, edge.v, x);
    }
  }
  return total;
}

int bfs(vector<vector<Edge>>& adj, int n, long long x) {
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  int total = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (visited[u]) {
      continue;
    }
    visited[u] = true;
    total++;
    for (Edge edge : adj[u]) {
      if (!visited[edge.v] && edge.w <= x) {
        q.push(edge.v);
      }
    }
  }
  return total;
}

bool f(vector<vector<Edge>>& adj, int n, long long x) {
  int total = bfs(adj, n, x);
  //   vector<bool> visited(n, false);
  //   int total = dfs(adj, visited, 0, x);
  return total == n;
}

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  int n;
  cin >> n;

  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].first >> cows[i].second;
  }

  vector<vector<Edge>> adj(n, vector<Edge>());
  long long minDist = 25000 * 50000;
  long long maxDist = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int deltaX = cows[i].first - cows[j].first;
      int deltaY = cows[i].second - cows[j].second;
      long long distance = deltaX * deltaX + deltaY * deltaY;
      adj[i].push_back({i, j, distance});
      adj[j].push_back({j, i, distance});
      minDist = min(minDist, distance);
      maxDist = max(maxDist, distance);
    }
  }

  long long low = minDist;
  long long high = maxDist;

  while (low < high) {
    long long mid = (low + high) / 2;
    if (f(adj, n, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low;
}