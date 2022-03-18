#include <bits/stdc++.h>
using namespace std;

bool solve(int m, int x, int y) {
  if (m <= 0) {
    return false;
  }
  int p = (int)pow(5, m - 1);

  int x0 = x / p;
  int y0 = y / p;

  if (x0 >= 1 && x0 <= 3 && y0 == 0) {
    // bottom 3
    return true;
  } else if (x0 == 2 && y0 == 1) {
    // middle one
    return true;
  } else if ((x0 == 1 && y0 == 1) || (x0 == 2 && y0 == 2) ||
             (x0 == 3 && y0 == 1)) {
    // possible extra blocks
    // reduce m level by 1, find the new x, y values in the m-1 level
    return solve(m - 1, x % p, y % p);
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m, x, y;
    cin >> m >> x >> y;
    if (solve(m, x, y)) {
      cout << "crystal\n";
    } else {
      cout << "empty\n";
    }
  }
}