#include <bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>>& grid, vector<pair<int, int>>& waypoints, int d,
       int m, int n) {
  vector<vector<bool>> visited(m + 2, vector<bool>(n + 2, false));
  for (int i = 0; i <= m + 1; i++) {
    visited[i][0] = true;
    visited[i][n + 1] = true;
  }

  for (int i = 0; i <= n + 1; i++) {
    visited[0][i] = true;
    visited[m + 1][i] = true;
  }

  queue<pair<int, int>> q;
  q.push(waypoints[0]);

  while (!q.empty()) {
    pair<int, int> point = q.front();
    q.pop();
    int x = point.first;
    int y = point.second;
    if (visited[x][y]) {
      continue;
    }
    visited[x][y] = true;

    if (!visited[x - 1][y] && abs(grid[x][y] - grid[x - 1][y]) <= d) {
      q.push({x - 1, y});
    }
    if (!visited[x + 1][y] && abs(grid[x][y] - grid[x + 1][y]) <= d) {
      q.push({x + 1, y});
    }

    if (!visited[x][y - 1] && abs(grid[x][y] - grid[x][y - 1]) <= d) {
      q.push({x, y - 1});
    }
    if (!visited[x][y + 1] && abs(grid[x][y] - grid[x][y + 1]) <= d) {
      q.push({x, y + 1});
    }
  }

  for (pair<int, int> point : waypoints) {
    if (!visited[point.first][point.second]) {
      return false;
    }
  }

  return true;
}
int main() {
  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m + 2, vector<int>(n + 2, 0));

  int maxE = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
      maxE = max(maxE, grid[i][j]);
    }
  }

  vector<pair<int, int>> waypoints;
  int point;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> point;
      if (point == 1) {
        waypoints.push_back({i, j});
      }
    }
  }

  int low = 0;
  int high = maxE;

  // false, false,..., false, true, ....true
  while (low < high) {
    int d = (low + high) / 2;
    if (f(grid, waypoints, d, m, n)) {
      high = d;
    } else {
      low = d + 1;
    }
  }
  cout << low;
  return 0;
}