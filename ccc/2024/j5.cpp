#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Location {
  int row, col;
};

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> v(r, vector<int>(c, 0));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char ch;
      cin >> ch;
      if (ch == 'L') {
        v[i][j] = 10;
      } else if (ch == 'M') {
        v[i][j] = 5;
      } else if (ch == 'S') {
        v[i][j] = 1;
      }
    }
  }
  int startR, startC;
  cin >> startR >> startC;

  queue<Location> q;

  vector<vector<bool>> visited(r, vector<bool>(c, false));
  long long total = 0;
  q.push({startR, startC});
  visited[startR][startC] = true;
  while (!q.empty()) {
    Location cell = q.front();
    q.pop();
    int row = cell.row;
    int col = cell.col;
    total += v[row][col];
    if (row > 0 && !visited[row - 1][col] && v[row - 1][col] > 0) {
      q.push({row - 1, col});
      visited[row - 1][col] = true;
    }
    if (row < r - 1 && !visited[row + 1][col] && v[row + 1][col] > 0) {
      q.push({row + 1, col});
      visited[row + 1][col] = true;
    }
    if (col > 0 && !visited[row][col - 1] && v[row][col - 1] > 0) {
      q.push({row, col - 1});
      visited[row][col - 1] = true;
    }
    if (col < c - 1 && !visited[row][col + 1] && v[row][col + 1] > 0) {
      q.push({row, col + 1});
      visited[row][col + 1] = true;
    }
  }
  cout << total;
}
