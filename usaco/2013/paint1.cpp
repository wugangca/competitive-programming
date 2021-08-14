#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
  int n, k;
  cin >> n >> k;
 //const int MAX_N = 1000000002;
  int cur = 0;
  map<int, int> diff;

  for (int i = 0; i < n; i++) {
    int distance;
    char direction;
    cin >> distance >> direction;
    if (diff.find(cur) == diff.end()) {
      diff[cur] = 0;
    }
    if (direction == 'R') {
      diff[cur]++;
      cur += distance;
      if (diff.find(cur) == diff.end()) {
        diff[cur] = 0;
      }
      diff[cur]--;
    } else {
      diff[cur]--;
      cur -= distance;
      if (diff.find(cur) == diff.end()) {
        diff[cur] = 0;
      }
      diff[cur]++;
    }
  }

  int ans = 0;
  int m = 0;
  int start = INT_MIN;
  for (auto const& x : diff) {
    int index = x.first;
    m += x.second;
    if (m >= k) {
      if (start == INT_MIN) {
        start = index;
      }
    } else if (start != INT_MIN) {
      ans += index - start;
      start = INT_MIN;
    }
  }

  cout << ans << endl;

  return 0;
}