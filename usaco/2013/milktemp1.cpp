#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("milktemp.in", "r", stdin);
  freopen("milktemp.out", "w", stdout);
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  int delta1 = y - x;
  int delta2 = z - y;

  map<int, int> temps;
  temps[0] = 0;

  for (int i = 0; i < n; i++) {
    int low, high;
    cin >> low >> high;
    temps[0] += x;
    if (temps.find(low) == temps.end()) {
      temps[low] = 0;
    }
    temps[low] += delta1;

    high++;
    if (temps.find(high) == temps.end()) {
      temps[high] = 0;
    }
    temps[high] += delta2;
  }

  int maxMilk = 0;
  int m = 0;
  for (auto &x : temps) {
    m += x.second;
    if (m > maxMilk) {
      maxMilk = m;
    }
  }

  cout << maxMilk << endl;
  return 0;
}