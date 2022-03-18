#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
  int r1, r2, c1, c2;
  bool contains(int r, int c) {
    return (r1 <= r) && (r <= r2) && (c1 <= c) && (c <= c2);
  }
};

void breakArea(const Rectangle &area, int r, int c, list<Rectangle> &areas,
               int minLen) {
  int r1 = area.r1;
  int r2 = area.r2;
  int c1 = area.c1;
  int c2 = area.c2;
  if (r > r1 + minLen) {
    areas.push_back({r1, r - 1, c1, c2});
  }
  if (r + minLen < r2) {
    areas.push_back({r + 1, r2, c1, c2});
  }
  if (c > c1 + minLen) {
    areas.push_back({r1, r2, c1, c - 1});
  }

  if (c + minLen < c2) {
    areas.push_back({r1, r2, c + 1, c2});
  }
}

int main() {
  int n;
  cin >> n;
  list<Rectangle> areas;

  int t;
  cin >> t;
  if ((long long)n * (long long)n == (long long)t) {
    cout << 0;
    return 0;
  }
  int minLen = 1;
  if (n > t) {
    minLen = max(1, (int)sqrt(n - t));
  }
  areas.push_back({1, n, 1, n});
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    auto itr = areas.begin();
    list<Rectangle> newAreas;
    while (itr != areas.end()) {
      if (itr->contains(r, c)) {
        breakArea(*itr, r, c, newAreas, minLen);
        itr = areas.erase(itr);
      } else {
        itr++;
      }
    }
    areas.splice(areas.end(), newAreas);
  }

  int ans = 1;
  for (Rectangle area : areas) {
    ans = max(ans, min(area.r2 - area.r1 + 1, area.c2 - area.c1 + 1));
  }
  cout << ans;
}