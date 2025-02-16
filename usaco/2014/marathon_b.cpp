#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("marathon.in", "r", stdin);
  freopen("marathon.out", "w", stdout);
  int n;
  cin >> n;

  vector<pair<int, int>> v(n);

  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (i > 0) {
      total +=
          abs(v[i].first - v[i - 1].first) + abs(v[i].second - v[i - 1].second);
    }
  }
  int maxDiff = 0;
  for (int i = 1; i < n - 1; i++) {
    int noskip =
        abs(v[i].first - v[i - 1].first) + abs(v[i].second - v[i - 1].second) +
        abs(v[i + 1].first - v[i].first) + abs(v[i + 1].second - v[i].second);
    int skip = abs(v[i + 1].first - v[i - 1].first) +
               abs(v[i + 1].second - v[i - 1].second);
    int diff = noskip - skip;
    if (diff > maxDiff) {
      maxDiff = diff;
    }
  }

  cout << total - maxDiff;

  return 0;
}