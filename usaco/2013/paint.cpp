#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  const int MAX_N = 100000;
  vector<int> diff(MAX_N * 2 + 10, 0);
  int cur = MAX_N;
  // int minX = MAX_N * 2 + 2;
  // int maxX = 0;
  vector<int> positions(n + 1, 0);

  
  positions[0] = cur;

  for (int i = 0; i < n; i++) {
    int distance;
    char direction;
    cin >> distance >> direction;
    if (direction == 'R') {
      diff[cur]++;
      cur += distance;
      diff[cur]--;
    } else {
      diff[cur]--;
      cur -= distance;
      diff[cur]++;
    }
    positions[i + 1] = cur;
  }

  sort(positions.begin(), positions.end());

  int ans = 0;
  int m = 0;

  // for (int i = positions[0]; i <= positions[n]; i++) {
  //      m += diff[i];
  //      if (m >= k) {
  //        ans++;
  //      }
  // }

  int start = -1;
  int prevIndex = -1;
  for (int i = 0; i <= n; i++) {
    int index = positions[i];
    if (index == prevIndex) {
      continue;
    } else {
      prevIndex = index;
    }
    m += diff[index];
    if (m >= k) {
      if (start < 0) {
        start = index;
      }
    } else {
      if (start >= 0) {
        ans += index - start;
        start = -1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}