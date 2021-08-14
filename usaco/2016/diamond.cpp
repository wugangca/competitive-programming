#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<int> diamond(n);

  for (int i = 0; i < n; i++) {
    cin >> diamond[i];
  }
  sort(diamond.begin(), diamond.end());

  vector<int> maxRightIndex;

  int end = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
   
    while ((diamond[j] - diamond[i] <= k) && j < n) {
      j++;
    }
    maxRightIndex.push_back(j);
   
  }

  int prevMaxCase2Start = 0;
  int prevMaxCase2Count = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int end = maxRightIndex[i];
    int case1Count = end - i;
    int case2Count = prevMaxCase2Count;
    if (end > prevMaxCase2Start) {
      prevMaxCase2Start = 0;
      prevMaxCase2Count = 0;
      for (int j = end; j < n; j++) {
        int count = maxRightIndex[j] - j;
        if (count > case2Count) {
          prevMaxCase2Start = j;
          prevMaxCase2Count = count;
        }
        case2Count = prevMaxCase2Count;
      }
    }
    ans = max(ans, case1Count + case2Count);
  }

  cout << ans;
  return 0;
}