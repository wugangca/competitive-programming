#include <bits/stdc++.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
struct Cow {
  Cow() {
    x = 0;
    y = 0;
    p = 0;
  }
  int x;
  int y;
  int p;
};

int dfs(vector<bool>& visited, int v, const vector<vector<int>>& graph) {
  visited[v] = true;
  int total = 0;

  for (int c : graph[v]) {
    if (visited[c]) continue;
    total += dfs(visited, c, graph) + 1;
  }
  return total;
}

int dfsStack(vector<bool>& visited, int v, const vector<vector<int>>& graph) {
  stack<int> s;
  s.push(v);
  int total = 0;
  while (!s.empty()) {
    int c = s.top();
    visited[c] = true;
    total++;
    s.pop();
    for (int u : graph[c]) {
      if (!visited[u]) s.push(u);
    }
  }
  return total;
}

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  int n;
  cin >> n;

  vector<Cow> cows(n, Cow());
  vector<vector<int>> graph(n, vector<int>());

  for (int i = 0; i < n; i++) {
    cin >> cows[i].x >> cows[i].y >> cows[i].p;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int deltaX = cows[i].x - cows[j].x;
      int deltaY = cows[i].y - cows[j].y;

      double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
      if (distance <= cows[i].p) {
        graph[i].push_back(j);
      }
      if (distance <= cows[j].p) {
        graph[j].push_back(i);
      }
    }
  }

  int maxCount = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> visited(n, false);
    maxCount = max(maxCount, dfs(visited, i, graph) + 1);
  }
  cout << maxCount;
}