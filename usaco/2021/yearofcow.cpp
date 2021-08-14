#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void checkCompfortable(const vector<vector<bool> >& grid, int x, int y,
                       queue<pair<int, int> >& q) {
  if (!grid[x][y]) {
    return;
  }
  int count = 0;
  int e_x, e_y;
  if (grid[x - 1][y]) {
    count++;
  } else {
    e_x = x - 1;
    e_y = y;
  }
  if (grid[x + 1][y]) {
    count++;
  } else {
    e_x = x + 1;
    e_y = y;
  }

  if (grid[x][y - 1]) {
    count++;
  } else {
    e_x = x;
    e_y = y - 1;
  }
  if (grid[x][y + 1]) {
    count++;
  } else {
    e_x = x;
    e_y = y + 1;
  }

  if (count == 3) {
    q.push({e_x, e_y});
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> years(n);
  for (int i = 0; i < n; i++) {
    cin >> years[i];
  }

  sort(years.begin(), years.end());
  vector<int> gaps;
  int start = 0;
  int end = 0;
  for (int i = 0; i < n; i++) {
    int diff = years[i] - start;
    if (diff < 12) {
      end = start + 12;
    } else {
      int newStart = 12 * (years[i] / 12);
      int gap = newStart - end;
      if (gap > 0) gaps.push_back(gap);
      start = newStart;
      end = start + 12;
    }
  }
  sort(gaps.begin(), gaps.end(), greater<int>());

  int total = 12 * (years[n - 1] / 12 + 1);
  for (int i = 0; i < k - 1; i++) {
    total -= gaps[i];
  }

  cout << total << "\n";

  return 0;
}