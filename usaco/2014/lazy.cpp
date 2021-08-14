#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Cow {
  int x;
  int grass;

  friend bool operator<(const Cow& l, const Cow& r) { return l.x < r.x; }
};

int main() {
   freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<Cow> cows(n);

  for (int i = 0; i < n; i++) {
    cin >> cows[i].grass >> cows[i].x;
  }
  sort(cows.begin(), cows.end());

  int total = 0;
  int left = 0;
  int right = 0;
  int ans = 0;

while (right < n) {
  while (right < n && cows[right].x - cows[left].x <= 2 * k) {
    total += cows[right].grass;
    right++;
  }
  ans = max(ans, total);
  total -=  cows[left].grass;
  left++;
}

/*
  for (int i = 0; i < n; i++) {
    total += cows[i].grass;
    while (cows[i].x - cows[left].x > 2 * k) {
      total -= cows[left].grass;
      left++;
    }
    ans = max(ans, total);
  }
*/
  cout << ans << endl;
  return 0;
}