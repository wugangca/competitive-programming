#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
4
3
6
9
10
*/
struct Cow {
  int x;
  int id;

  friend bool operator<(const Cow& l, const Cow& r) { return l.x < r.x; }
};

int main() {
  freopen("I.12", "r", stdin);
  //freopen("12.out", "w", stdout);
  int n;
  cin >> n;
  vector<Cow> cows(n);

  map<int, int> idCount;

  for (int i = 0; i < n; i++) {
    cin >> cows[i].x >> cows[i].id;
    if (idCount.find(cows[i].id) == idCount.end()) {
      idCount[cows[i].id] = 0;
    }
  }
  sort(cows.begin(), cows.end());

  int left = 0, right = 0;
  int totalIds = idCount.size();
  int num = 0;
  int minSize = INT_MAX;
  while (right < n) {
    while (right < n) {
      int id = cows[right].id;
      if (idCount[id] == 0) {
        idCount[id]++;
        num++;
        if (num == totalIds) {
          break;
        }
      } else {
        idCount[id]++;
      }
      right++;
    }
    if (right >= n) {
        break;
    }
    while (left < right) {
      int id = cows[left].id;
      idCount[id]--;
      if (idCount[id] == 0) {
        break;
      }
      left++;
    }

    minSize = min(minSize, cows[right].x - cows[left].x);
    left++;
    num--;
    right++;
  }

  cout << minSize << endl;
  return 0;
}