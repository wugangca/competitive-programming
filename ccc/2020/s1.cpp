/*
sort the observations by time, then calculate the speed on the time intervals
*/
#include <bits/stdc++.h>
using namespace std;

struct Observation {
  int time;
  int pos;

  friend bool operator<(Observation& l, Observation& r) {
    return l.time < r.time;
  }
};

int main() {
  int n;
  cin >> n;
 
  vector<Observation> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].time >> v[i].pos;
  }

  sort(v.begin(), v.end());

  double ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans,  abs(v[i].pos - v[i - 1].pos) * 1.0 / (v[i].time - v[i - 1].time));
  }

  cout << fixed << ans;

  return 0;
}
