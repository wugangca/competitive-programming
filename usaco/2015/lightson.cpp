#include <bits/stdc++.h>

using namespace std;

struct Cell {
  bool on;
  bool visited;
  vector<pair<int, int>> switches;
};

int main() {
  freopen("lightson.in", "r", stdin);
  freopen("lightson.out", "w", stdout);
  int n, m;
  cin >> n >> m;

  vector<vector<Cell>> grid(n + 2, vector<Cell>(n + 2, {false, false, {}}));

  for (int i = 0; i < m; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    grid[x][y].switches.push_back({a, b});
  }

  queue<pair<int, int>> q;

  grid[1][1].on = true;
  q.push({1, 1});

  int total = 1;
  while (!q.empty()) {
    pair<int, int> location = q.front();
    q.pop();

    int x = location.first;
    int y = location.second;

    if (grid[x][y].visited) {
      continue;
    }
    grid[x][y].visited = true;

    for (pair<int, int> s : grid[x][y].switches) {
      int i = s.first;
      int j = s.second;
      if (!grid[i][j].on) {
        total++;
        grid[i][j].on = true;
        if (grid[i - 1][j].visited || grid[i + 1][j].visited ||
            grid[i][j - 1].visited || grid[i][j + 1].visited) {
          q.push({i, j});
        }
      }
    }

    if (grid[x - 1][y].on && !grid[x - 1][y].visited) {
      q.push({x - 1, y});
    }
    if (grid[x + 1][y].on && !grid[x + 1][y].visited) {
      q.push({x + 1, y});
    }
    if (grid[x][y - 1].on && !grid[x][y - 1].visited) {
      q.push({x, y - 1});
    }
    if (grid[x][y + 1].on && !grid[x][y + 1].visited) {
      q.push({x, y + 1});
    }
  }

  cout << total;

  return 0;
}