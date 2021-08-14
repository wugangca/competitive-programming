#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  double minSize = INT_MAX;
  for (int i = 1; i < n - 1; i++) {
    minSize = min(minSize, (v[i + 1] - v[i - 1])/2.0);
  }
  cout << fixed << setprecision(1) << minSize;

  return 0;
}