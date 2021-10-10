#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
  int total = accumulate(nums.begin(), nums.end(), 0);
  if (total % 2 == 1) {
    return false;
  }
  int half = total / 2;
  int n = nums.size();

  vector<vector<bool> > dp(n + 1, vector<bool>(half + 1, false));

  // dp[n+1][half+1]
  // dp[i][sum]: can reach sum with first i numbers

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  for (int i = 1; i <= n; i++) {
    int num = nums[i - 1];

    for (int sum = 1; sum <= half; sum++) {
      dp[i][sum] = dp[i - 1][sum] | ((sum >= num) && dp[i - 1][sum - num]);
    }
  }

  return dp[n][half];
}

int main() {
  vector<int> nums{1, 2, 5};
  cout << canPartition(nums);
}