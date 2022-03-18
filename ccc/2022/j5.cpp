#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 1));
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    grid[r - 1][c - 1] = 0;
  }

  int maxsqlen = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) continue;

      int sqlen = 1;
      bool flag = true;
      while (sqlen + i < n && sqlen + j < n && flag) {
        for (int k = j; k <= sqlen + j; k++) {
          if (grid[i + sqlen][k] == 0) {
            flag = false;
            break;
          }
        }
        for (int k = i; k <= sqlen + i; k++) {
          if (grid[k][j + sqlen] == 0) {
            flag = false;
            break;
          }
        }
        if (flag) sqlen++;
      }
      if (maxsqlen < sqlen) {
        maxsqlen = sqlen;
      }
    }
  }
  cout << maxsqlen;
}