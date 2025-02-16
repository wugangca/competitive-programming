#include <algorithm>
#include <iostream>
#include <vector>

/*
will TLE on last numbers.
*/
using namespace std;

int maxSquare(int top, int bottom, int left, int right,
              vector<pair<int, int>> &trees) {
  for (pair<int, int> tree : trees) {
    if (tree.first >= top && tree.first <= bottom && tree.second >= left &&
        tree.second <= right) {
      int square1 = maxSquare(top, tree.first - 1, left, right, trees);
      int square2 = maxSquare(tree.first + 1, bottom, left, right, trees);

      int square3 = maxSquare(top, bottom, left, tree.second - 1, trees);

      int square4 = maxSquare(top, bottom, tree.second + 1, right, trees);
      return max(max(square1, square2), max(square3, square4));
    }
  }
  return min(bottom - top, right - left) + 1;
}

int main() {
  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> trees(t);

  for (int i = 0; i < t; i++) {
    cin >> trees[i].first >> trees[i].second;
  }
  cout << maxSquare(1, n, 1, n, trees);
}