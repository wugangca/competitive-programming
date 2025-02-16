#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("cownomics.in", "r", stdin);
  // freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<string> v(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    cin >> v[i];
  }

  int count = 0;
  for (int col = 0; col < m; col++) {
    set<char> s;
    for (int row = n; row < 2 * n; row++) {
      s.insert(v[row][col]);
    }
    bool unique = true;
    for (int row = 0; row < n; row++) {
      if (s.count(v[row][col]) > 0) {
        unique = false;
        break;
      }
    }
    if (unique) {
      count++;
    }
  }
  cout << count;
}