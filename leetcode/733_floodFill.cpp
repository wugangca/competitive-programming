#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                              int newColor) {
  struct Location {
    int row, col;
  };
  queue<Location> q;
  q.push({sr, sc});
  int m = image.size();
  int n = image[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  int color = image[sr][sc];
  while (!q.empty()) {
    Location cell = q.front();
    q.pop();

    int row = cell.row;
    int col = cell.col;
    image[row][col] = newColor;
    visited[row][col] = true;
    if (row > 0 && !visited[row - 1][col] && image[row - 1][col] == color) {
      q.push({row - 1, col});
      visited[row - 1][col] = true;
    }
    if (row < m - 1 && !visited[row + 1][col] && image[row + 1][col] == color) {
      q.push({row + 1, col});
      visited[row + 1][col] = true;
    }
    if (col > 0 && !visited[row][col - 1] && image[row][col - 1] == color) {
      q.push({row, col - 1});
      visited[row][col - 1] = true;
    }
    if (col < n - 1 && !visited[row][col + 1] && image[row][col + 1] == color) {
      q.push({row, col + 1});
      visited[row][col + 1] = true;
    }
  }
  return image;
}