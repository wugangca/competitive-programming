#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, n;
  cin >> w >> n;

  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int i = 0;
  int j = 0;

  int total = 0;

  while (j < n && j < 4) {
    total += v[j];
    if (total > w ) {
      cout << j;
      return 0;
    }
    j++;
  }

  while (j < n) {
    total -= v[i];
    total += v[j];
    if (total > w) {
      cout << j;
      return 0;
    }
    i++;
    j++;
  }
  cout << n;

}