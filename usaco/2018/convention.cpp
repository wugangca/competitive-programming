#include <bits/stdc++.h>

using namespace std;

bool f(vector<int>& time, int wait, int m, int c) {
  int count = 1;
  int first = time[0];
  for (int i = 1; i < time.size(); i++) {
    int t = time[i];
    if (t - first <= wait && count < c) {
      count++;
    } else {
      m--;
      if (m == 0) {
        return false;
      }
      count = 1;
      first = t;
    }
  }

  return true;
}
int main() {
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> time(n);
  for (int i = 0; i < n; i++) {
    cin >> time[i];
  }

  sort(time.begin(), time.end());
  int low = 0;
  int high = time[n - 1] - time[0];

  while (low < high) {
    int mid = (low + high) / 2;
    if (f(time, mid, m, c)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;

  return 0;
}