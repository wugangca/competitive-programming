#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Milk {
  int num;
  int output;
  friend bool operator<(const Milk& l, const Milk& r) {
    return l.output < r.output;
  }
};

int main() {
  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);
  int n;
  cin >> n;

  vector<Milk> milks(n);
  for (int i = 0; i < n; i++) {
    cin >> milks[i].num >> milks[i].output;
  }

  sort(milks.begin(), milks.end());

  int i = 0;
  int j = n - 1;

  int maxSum = 0;
  while (i <= j) {
    if (milks[i].num > 0 && milks[j].num > 0) {
      maxSum = max(maxSum, milks[i].output + milks[j].output);
      milks[i].num--;
      milks[j].num--;
    } else if (milks[i].num <= 0) {
      i++;
    } else {
      j--;
    }
  }

  cout << maxSum;

  return 0;
}