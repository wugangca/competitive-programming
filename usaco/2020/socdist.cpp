#include <bits/stdc++.h>

using namespace std;

bool f(vector<pair<int, int>> intervals, int n, int d) {
  int count = 1;
  int location = intervals[0].first;
  int end = intervals[0].second;
  int i = 0;
  while (true) {
    if (count == n) {
      return true;
    }
    if (location + d <= end) {
      location += d;
      count++;
      continue;
    } else {
      while (true) {
        i++;
        if (i == intervals.size()) {
          return false;
        }
        if (location + d <= intervals[i].first) {
          break;
        }
      }
      location = intervals[i].first;
      count++;
      end = intervals[i].second;
    }
  }

  return false;
}
int main() {
  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> intervals(m);
  for (int i = 0; i < m; i++) {
    cin >> intervals[i].first >> intervals[i].second;
  }

  sort(intervals.begin(), intervals.end());

  int low = 0;
  int high = (intervals[m - 1].second - intervals[0].first);
  int ans;

  while (low < high) {
    int mid = (low + high) / 2;
    if (f(intervals, n, mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << ans << endl;
  return 0;
}