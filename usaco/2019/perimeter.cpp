#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int n, int num) {
  grid[i][j] = num;

  if (j > 0 && grid[i][j - 1] == 1) {
    dfs(grid, i, j - 1, n, num);
  }
  if (i > 0 && grid[i - 1][j] == 1) {
    dfs(grid, i - 1, j, n, num);
  }
  if (j < n - 1 && grid[i][j + 1] == 1) {
    dfs(grid, i, j + 1, n, num);
  }
  if (i < n - 1 && grid[i + 1][j] == 1) {
    dfs(grid, i + 1, j, n, num);
  }
}

void bfs(vector<vector<int>> &grid, int x, int y, int n, int num) {
  queue<pair<int, int>> q;
  q.push({x, y});
  grid[x][y] = num;

  while (!q.empty()) {
    pair<int, int> cell = q.front();
    q.pop();
    int i = cell.first;
    int j = cell.second;
    if (grid[i][j - 1] == 1) {
      grid[i][j - 1] = num;
      q.push({i, j - 1});
    }
    if (grid[i - 1][j] == 1) {
      grid[i - 1][j] = num;
      q.push({i - 1, j});
    }
    if (grid[i][j + 1] == 1) {
      grid[i][j + 1] = num;
      q.push({i, j + 1});
    }
    if (grid[i + 1][j] == 1) {
      grid[i + 1][j] = num;
      q.push({i + 1, j});
    }
  }
}

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> grid(n + 2, vector<int>(n + 2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      if (ch == '#') {
        grid[i][j] = 1;
      }
    }
  }

  int num = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i][j] == 1) {
        num++;
        bfs(grid, i, j, n, num);
      }
    }
  }

  vector<int> area(n * n + 2, 0);
  vector<int> perimeter(n * n + 2, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int num = grid[i][j];
      if (num == 0) {
        continue;
      }
      area[num]++;
      if (grid[i][j - 1] == 0) {
        perimeter[num]++;
      }
      if (grid[i - 1][j] == 0) {
        perimeter[num]++;
      }
      if (grid[i][j + 1] == 0) {
        perimeter[num]++;
      }
      if (grid[i + 1][j] == 0) {
        perimeter[num]++;
      }
    }
  }

  int maxArea = 0;
  int maxPerimeter = 0;
  for (int i = 2; i < n * n + 2; i++) {
    if ((area[i] > maxArea) ||
        (area[i] == maxArea && perimeter[i] < maxPerimeter)) {
      maxArea = area[i];
      maxPerimeter = perimeter[i];
    }
  }

  cout << maxArea << " " << maxPerimeter;

  return 0;
}