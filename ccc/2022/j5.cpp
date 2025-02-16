#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> trees(t);
  set<int> tops;
  set<int> lefts;
  tops.insert(0);
  lefts.insert(0);

  for (int i = 0; i < t; i++) {
    cin >> trees[i].first >> trees[i].second;
    tops.insert(trees[i].first);
    lefts.insert(trees[i].second);
  }
  int ans = 1;
  for (int top : tops) {
    for (int left : lefts) {
      vector<pair<int, int>> candidates;
      for (pair<int, int> tree : trees) {
        if (tree.first > top && tree.second > left) {
          candidates.push_back(tree);
        }
      }
      if (candidates.size() == 0) {
        ans = max(ans, min(n - top, n - left));
        continue;
      }
      for (pair<int, int> tree : candidates) {
        int bottom = tree.first;
        int right = n + 1;
        for (pair<int, int> tree1 : candidates) {
          if (tree1.first >= bottom) {
            continue;
          }
          right = min(right, tree1.second);
        }
        int pool = min(bottom - top - 1, right - left - 1);
        ans = max(ans, pool);

        right = tree.second;
        bottom = n + 1;

        for (pair<int, int> tree1 : candidates) {
          if (tree1.second >= right) {
            continue;
          }
          bottom = min(bottom, tree1.first);
        }
        pool = min(bottom - top - 1, right - left - 1);
        ans = max(ans, pool);
      }
    }
  }

  cout << ans;
}