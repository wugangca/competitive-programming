#include <bits/stdc++.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
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

int dfs (vector<bool>& visited, int v, int n, const vector<vector<int>> &graph) {
    visited[v] = true;
    int total = 0;

    for (int c : graph[v]){
        if (visited[v]) continue;
        total += dfs(visited, c, n, graph) + 1;
    }
    return total;
}

int main() {
  ifstream inFile("moocast.in");
  int n;
  inFile >> n;

  vector<Cow> cows(n, Cow());
  vector<vector<int>> graph(n, vector<int>());

  for (int i = 0; i < n; i++) {
    inFile >> cows[i].x >> cows[i].y >> cows[i].p;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int deltaX = cows[i].x - cows[j].x;
      int deltaY = cows[i].y - cows[j].y;

      int distance = deltaX * deltaX + deltaY * deltaY;
      if (distance <= cows[i].p * cows[i].p) {
        graph[i].push_back(j);
      }
      if (distance <= cows[j].p * cows[j].p) {
        graph[j].push_back(i);
      }
    }
  }
  inFile.close();

  int maxCount = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(i);
    int total = 0;
    while (!q.empty()) {
      int cowIndex = q.front();
      total++;
      q.pop();
      visited[cowIndex] = true;
      for (int c : graph[cowIndex]) {
        if (!visited[c]) {
          q.push(c);
        }
      }
    }

    if (total > maxCount) {
      maxCount = total;
    }
  }

  ofstream outFile("moocast.out");
  outFile << maxCount;
  outFile.close();
}