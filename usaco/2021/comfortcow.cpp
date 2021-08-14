#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void checkCompfortable(const vector<vector<bool> >& grid, int x, int y,
                       queue<pair<int, int> >& q) {
  if (!grid[x][y]) {
    return;
  }
  int count = 0;
  int e_x, e_y;
  if (grid[x - 1][y]) {
    count++;
  } else {
    e_x = x-1;
    e_y = y;
  }
  if (grid[x + 1][y]) {
    count++;
  }else {
    e_x = x+1;
    e_y = y;
  }

  if (grid[x][y - 1]) {
    count++;
  }
  else {
    e_x = x;
    e_y = y-1;
  }
  if (grid[x][y + 1]) {
    count++;
  }
  else {
    e_x = x;
    e_y = y+1;
  }

  if (count == 3) {
    q.push({e_x, e_y});
  }
}

int main() {

 // freopen("2.in", "r", stdin);
  //freopen("2_code.out", "w", stdout);

  int n;
  cin >> n;
  const int N = 1000;
  vector<vector<bool> > grid(N * 3, vector<bool>(N * 3, false));
  int total = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    x += N;
    y += N;

    queue<pair<int, int> > q;
    q.push({x, y});

    while (!q.empty()) {
      pair<int, int> cow = q.front();
      q.pop();
      int x = cow.first;
      int y = cow.second;
      if (grid[x][y]) {
        continue;
      }
      total++;
      grid[x][y] = true;
      checkCompfortable(grid, x, y, q);
      checkCompfortable(grid, x+1, y, q);
      checkCompfortable(grid, x-1, y, q);
      checkCompfortable(grid, x, y+1, q);
      checkCompfortable(grid, x, y-1, q);
    }
    cout << total - i << "\n";
  }

  return 0;
}