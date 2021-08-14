#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> ans{-1, -1};
  if (nums.size() == 0) {
    return ans;
  }
  vector<int>::iterator itr1 = lower_bound(nums.begin(), nums.end(), target);

  if (itr1 == nums.end() || *itr1 != target) {
    return ans;
  }
  vector<int>::iterator itr2 = upper_bound(nums.begin(), nums.end(), target);
  return {(int)(itr1 - nums.begin()), (int)(itr2 - nums.begin() - 1)};
}