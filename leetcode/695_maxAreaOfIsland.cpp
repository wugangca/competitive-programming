#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
          int j, int m, int n) {
    visited[i][j] = true;
    int result = 1;
    if (j > 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
      result += dfs(grid, visited, i, j - 1, m, n);
    }
    if (i > 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
      result += dfs(grid, visited, i - 1, j, m, n);
    }
    if (j < n - 1 && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
      result += dfs(grid, visited, i, j + 1, m, n);
    }
    if (i < m - 1 && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
      result += dfs(grid, visited, i + 1, j, m, n);
    }
    return result;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && grid[i][j] == 1) {
          maxArea = max(maxArea, dfs(grid, visited, i, j, m, n));
        }
      }
    }
    return maxArea;
  }
};

class Solution1 {
 public:
  struct Location {
    int row, col;
  };

  int countOnes(vector<vector<int>>& grid, int m, int n, int startRow,
                int startCol, vector<vector<bool>>& visited) {
    queue<Location> q;
    q.push({startRow, startCol});
    // vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;
    while (!q.empty()) {
      Location cell = q.front();
      q.pop();
      count++;
      int row = cell.row;
      int col = cell.col;
      visited[row][col] = true;
      if (row > 0 && !visited[row - 1][col] && grid[row - 1][col] == 1) {
        q.push({row - 1, col});
        visited[row - 1][col] = true;
      }
      if (row < m - 1 && !visited[row + 1][col] && grid[row + 1][col] == 1) {
        q.push({row + 1, col});
        visited[row + 1][col] = true;
      }
      if (col > 0 && !visited[row][col - 1] && grid[row][col - 1] == 1) {
        q.push({row, col - 1});
        visited[row][col - 1] = true;
      }
      if (col < n - 1 && !visited[row][col + 1] && grid[row][col + 1] == 1) {
        q.push({row, col + 1});
        visited[row][col + 1] = true;
      }
    }
    return count;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          int area = countOnes(grid, m, n, i, j, visited);
          if (area > maxArea) {
            maxArea = area;
          }
        }
      }
    }
    return maxArea;
  }
};