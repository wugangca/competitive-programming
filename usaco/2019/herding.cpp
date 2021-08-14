#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());

  int ansMin = 0;

  if (nums[n - 2] - nums[0] == n - 2 && nums[n - 1] - nums[n - 2] > 2) {
    ansMin = 2;
  } else if (nums[n - 1] - nums[1] == n - 2 && nums[1] - nums[0] > 2) {
    ansMin = 2;
  } else {
    int maxCount = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      int end = nums[i] + n - 1;
      while (j < n && nums[j] <= end) {
        j++;
      }
      maxCount = max(maxCount, j - i);

      // while (j < n - 1 && nums[j + 1] - nums[i] <= n - 1) j++;
      // maxCount = max(maxCount, j - i + 1);
    }
    ansMin = n - maxCount;
  }

  // int ansMax = max(nums[n - 2] - nums[0], nums[n - 1] - nums[1]) - (n - 2);

  int ansMax = max(nums[1] - nums[0], nums[n - 1] - nums[n - 2]) - 1 +
               nums[n - 2] - nums[1] - (n - 2) + 1;
  cout << ansMin << endl << ansMax << endl;
}