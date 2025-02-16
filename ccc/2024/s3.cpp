#include <iostream>
#include <vector>
using namespace std;
/*
We process array B block by block.
In each block of B, all numbers are the same. This corresponds to one swipe.
For each block of B, we need to find the position of the block's value in the
array A.
Use two-pointers: 
i: the pointer in the A to find the value of a block
j: the pointer in the B to find the blocks

Suppose the block's position is [start, end] and the value is B[start]
We go through A to find the first occurrance of B[start]
The position can have the following cases:
1. i < start: We need a R swipe, [i, end]
2. start <= i <= end: we need a L swipe [start, i] and R swipe [i, end]
3. i > end: we need a L swipe [start, i]
The conditions can be simplified into two:
1. As long as i < end, we do R swipe [i, end]
2. As long as i > start, we do L swipe [start, i]

For L swipes, we can do from left to right:
e.g.

5
3 4 5 1 2
1 1 2 2 2
We need to do two L swipes, [0,3] -> 1 1 1 1 2, then [2, 4]-> 1 1 2 2 2

For R swipes, we need to do from right to left:

6
1 2 3 4 5 6
1 1 1 1 2 2
The recorded R swipes (two pointers, from left to right ) are:
[0, 3], [1, 5]
If we do from left to right, we have 1 1 1 1 5 6-> 1 2 2 2 2 2
We need to do from right to left: [1, 5] -> 1 2 2 2 2 2
then [0, 3] -> 1 1 1 1 2 2

*/
int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> b(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int i = 0;
  int j = 0;

  vector<pair<int, int>> swipesL, swipesR;
  bool can = true;
  while (j < n) {
    int start = j;
    while (j < n && b[j] == b[start]) {
      j++;
    }
    int end = j - 1;

    while (i < n && a[i] != b[start]) {
      i++;
    }
    if (i == n) {
      can = false;
      break;
    }

    if (i < end) {
      swipesR.push_back({i, end});
    }

    if (i > start) {
      swipesL.push_back({start, i});
    }
  }

  if (can) {
    cout << "YES\n";
    cout << swipesL.size() + swipesR.size() << endl;
    for (auto p : swipesL) {
      cout << "L " << p.first << " " << p.second << endl;
    }
    for (int i = swipesR.size() - 1; i >= 0; i--) {
      auto p = swipesR[i];
      cout << "R " << p.first << " " << p.second << endl;
    }
  } else {
    cout << "NO\n";
  }
}