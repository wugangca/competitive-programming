#include <bits/stdc++.h>
using namespace std;

struct Location {
  int row, col, distance;
};

int findClosestXY(const vector<vector<char>>& grid, int m, int n) {
  queue<Location> q;
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'X') {
        q.push({i, j, 0});
        visited[i][j] = true;
      }
    }
  }

  while (!q.empty()) {
    Location cell = q.front();
    q.pop();
    int row = cell.row;
    int col = cell.col;
    int distance = cell.distance;
    if (grid[row][col] == 'Y') {
      return distance;
    }

    if (row > 0 && !visited[row - 1][col]) {
      q.push({row - 1, col, distance + 1});
      visited[row - 1][col] = true;
    }
    if (row < m - 1 && !visited[row + 1][col]) {
      q.push({row + 1, col, distance + 1});
      visited[row + 1][col] = true;
    }
    if (col > 0 && !visited[row][col - 1]) {
      q.push({row, col - 1, distance + 1});
      visited[row][col - 1] = true;
    }
    if (col < n - 1 && !visited[row][col + 1]) {
      q.push({row, col + 1, distance + 1});
      visited[row][col + 1] = true;
    }
  }
  return -1;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<char>> grid(m, vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cout << findClosestXY(grid, m, n);
}
