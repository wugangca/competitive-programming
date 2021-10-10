#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> x(n, 0);
  vector<int> y(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  // i will be corner
  // j will be flat (same x-coordinate as i)
  // k will be same y-coordinate as i
  int best = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (y[i] == y[j] && x[i] == x[k]) {
          int area = abs(x[j] - x[i]) * abs(y[k] - y[i]);
          if (area > best) {
            best = area;
          }
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
