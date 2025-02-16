
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;
  int max = 0;
  for (int i = 1; i <= m / x; i++) {
    for (int j = 0; j <= m / y; j++) {
      int total = i * x + j * y;
      if (total <= m && total > max) {
        max = total;
      }
    }
  }
  cout << max;
}