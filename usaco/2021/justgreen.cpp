#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

long long solve(const vector<vector<bool>>& ok, int n) {
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> all_ones(n, true);
    for (int j = i; j < n; j++) {
      int run = 0;
      for (int k = 0; k < n; k++) {
        all_ones[k] = all_ones[k] & ok[j][k];
        if (all_ones[k])
          ans += ++run;
        else
          run = 0;
      }
    }
  }
  return ans;
}

long long solve1(const vector<vector<bool>>& ok, int n) {
  vector<vector<int>> ones(n + 1, vector<int>(n + 1, 0));
  vector<vector<long long>> result(n + 1, vector<long long>(n + 1, 0));

  for (int col = 1; col <= n; col++) {
    for (int row = 1; row <= n; row++) {
      long long r = result[row][col - 1] + result[row - 1][col] -
              result[row - 1][col - 1];
      if (ok[row-1][col-1]) {
        ones[row][col] = ones[row][col - 1] + 1;
        int len = n;
        for (int k = row; k > 0; k--) {
          len = min(len, ones[k][col]);
          if (len == 0) break;
          r += len;
        }
      } else {
        ones[row][col] = 0;
      }
      result[row][col] = r;
    }
  }
  return result[n][n];
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  vector<vector<bool>> ok(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] >= 100) {
        ok[i][j] = true;
      } else {
        ok[i][j] = false;
      }
    }
  }

  long long ans1 = solve1(ok, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] > 100) {
        ok[i][j] = true;
      } else {
        ok[i][j] = false;
      }
    }
  }

  long long ans2 = solve1(ok, n);

  cout << ans1 - ans2 << "\n";
  return 0;
}