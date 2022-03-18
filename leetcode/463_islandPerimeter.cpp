#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
  queue<pair<int, int>> q;
  int m = grid.size();
  int n = grid[0].size();

  vector<vector<bool>> visited(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        q.push({i, j});
        visited[i][j] = true;
        break;
      }
    }
    if (q.size() > 0) {
      break;
    }
  }
  int perimeter = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;

    if (x == 0 || grid[x - 1][y] == 0) {
      perimeter++;
    } else if (!visited[x - 1][y]) {
      q.push({x - 1, y});
      visited[x - 1][y] = true;
    }

    if (x == m - 1 || grid[x + 1][y] == 0) {
      perimeter++;
    } else if (!visited[x + 1][y]) {
      q.push({x + 1, y});
      visited[x + 1][y] = true;
    }

    if (y == 0 || grid[x][y - 1] == 0) {
      perimeter++;
    } else if (!visited[x][y - 1]) {
      q.push({x, y - 1});
      visited[x][y - 1] = true;
    }

    if (y == n - 1 || grid[x][y + 1] == 0) {
      perimeter++;
    } else if (!visited[x][y + 1]) {
      q.push({x, y + 1});
      visited[x][y + 1] = true;
    }
  }
  return perimeter;
}

int main() {
  // vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
  vector<vector<int>> grid = {{1, 1}, {1, 1}};
  cout << islandPerimeter(grid);
}