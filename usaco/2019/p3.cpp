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
  }
  int x;
  int y;
};

int main() {
  ifstream inFile("fenceplan.in");
  int n, m;
  inFile >> n >> m;

  vector<Cow> cows(n + 1, Cow());
  vector<vector<int>> graph(n + 1, vector<int>());

  for (int i = 1; i <= n; i++) {
    inFile >> cows[i].x >> cows[i].y;
  }

  for (int i = 0; i < m; i++) {
    int cow1, cow2;
    inFile >> cow1 >> cow2;
    graph[cow1].push_back(cow2);
    graph[cow2].push_back(cow1);
  }
  inFile.close();

  vector<bool> visited(n + 1, false);
  int minPerimeter = INT_MAX;

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }
    queue<int> q;
    q.push(i);
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = 0;
    int maxY = 0;

    while (!q.empty()) {
      int cowIndex = q.front();
      if (cows[cowIndex].x < minX) {
        minX = cows[cowIndex].x;
      }
      if (cows[cowIndex].y < minY) {
        minY = cows[cowIndex].y;
      }
      if (cows[cowIndex].x > maxX) {
        maxX = cows[cowIndex].x;
      }
      if (cows[cowIndex].y > maxY) {
        maxY = cows[cowIndex].y;
      }


      q.pop();
      visited[cowIndex] = true;
      for (int c : graph[cowIndex]) {
        if (!visited[c]) {
          q.push(c);
        }
      }
    }
    int perimeter = 2 * ((maxX - minX) + (maxY - minY));
    if (perimeter < minPerimeter) {
      minPerimeter = perimeter;
    }
  }

  ofstream outFile("fenceplan.out");
  outFile << minPerimeter;
  outFile.close();
}