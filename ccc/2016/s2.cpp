#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q, n;
  cin >> q >> n;
  vector<int> d(n, 0);
  vector<int> p(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(d.begin(), d.end());
  sort(p.begin(), p.end());

  if (q == 2) {
    reverse(p.begin(), p.end());
  }

  int total = 0;

  for (int i = 0; i < n; i++) {
    total += max(d[i], p[i]);
  }

  cout << total;
  return 0;
}