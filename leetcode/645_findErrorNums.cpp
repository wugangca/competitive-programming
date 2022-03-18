#include <bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
  vector<int> ans(2);
  for (int i : nums) {
    int index = abs(i);
    if (nums[index - 1] > 0) {
      nums[index - 1] = -nums[index - 1];
    } else {
      ans[0] = index;
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      ans[1] = i + 1;
      break;
    }
  }

  return ans;
}

int main() {
  vector<int> nums{2, 2};
  vector<int> ans = findErrorNums(nums);
  cout << ans[0] << " " << ans[1];
}