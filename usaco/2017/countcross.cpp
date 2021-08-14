#include <bits/stdc++.h>

struct Cell {
  int num;
  bool left, right, up, down;
};
using namespace std;

void bfs(vector<vector<Cell>>& grid, int r, int c, int num) {
  queue<pair<int, int>> q;
  q.push({r, c});

  while (!q.empty()) {
    pair<int, int> cell = q.front();
    q.pop();
    int x = cell.first;
    int y = cell.second;

    if (grid[x][y].num > 0) continue;
    grid[x][y].num = num;

    if (grid[x][y].up && grid[x - 1][y].num == 0) {
      q.push({x - 1, y});
    }
    if (grid[x][y].down && grid[x + 1][y].num == 0) {
      q.push({x + 1, y});
    }
    if (grid[x][y].left && grid[x][y - 1].num == 0) {
      q.push({x, y - 1});
    }
    if (grid[x][y].right && grid[x][y + 1].num == 0) {
      q.push({x, y + 1});
    }
  }
}

int main() {
  freopen("countcross.in", "r", stdin);
  freopen("countcross.out", "w", stdout);
  int n, k, r;
  cin >> n >> k >> r;

  vector<vector<Cell>> grid(n + 1,
                            vector<Cell>(n + 1, {0, true, true, true, true}));

  for (int i = 1; i <= n; i++) {
    grid[1][i].up = false;
    grid[n][i].down = false;
    grid[i][1].left = false;
    grid[i][n].right = false;
  }

  for (int i = 0; i < r; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2) {
      if (c1 < c2) {
        grid[r1][c1].right = false;
        grid[r2][c2].left = false;
      } else {
        grid[r2][c2].right = false;
        grid[r1][c1].left = false;
      }
    } else {
      if (r1 < r2) {
        grid[r1][c1].down = false;
        grid[r2][c2].up = false;
      } else {
        grid[r2][c2].down = false;
        grid[r1][c1].up = false;
      }
    }
  }

  vector<pair<int, int>> cows;

  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    cows.push_back({r, c});
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i][j].num == 0) {
        count++;
        bfs(grid, i, j, count);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < k - 1; i++) {
    for (int j = i + 1; j < k; j++) {
      if (grid[cows[i].first][cows[i].second].num !=
          grid[cows[j].first][cows[j].second].num) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}