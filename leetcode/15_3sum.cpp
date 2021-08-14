#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  const size_t len = nums.size();
  if (len < 3) return {};

  sort(nums.begin(), nums.end());

  vector<vector<int>> results;

  for (int i = 0; i < len - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int j = i + 1;
    int k = len - 1;

    while (j < k) {
      const int sum = nums[i] + nums[j] + nums[k];
      if (0 == sum) {
        results.push_back({nums[i], nums[j], nums[k]});
        do {
          j++;
          k--;
        } while (j < k && nums[j] == nums[j - 1] && nums[k] == nums[k + 1]);
      } else if (sum < 0) {
        do {
          j++;
        } while (j < k && nums[j] == nums[j - 1]);
      } else if (sum > 0) {
        do {
          k--;
        } while (j < k && nums[k] == nums[k + 1]);
      }
    }
  }
  return results;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = threeSum(nums);

  return 1;
}