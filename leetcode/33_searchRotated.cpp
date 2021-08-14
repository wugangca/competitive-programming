#include <bits/stdc++.h>
using namespace std;
int findPeak(vector<int>& nums) {
  int low = 0;
  int high = nums.size() - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (nums[mid] < nums[high]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int search(vector<int>& nums, int target) {
  int pivot = findPeak(nums);

  vector<int>::iterator itr =
      lower_bound(nums.begin(), nums.begin() + pivot, target);

  if (*itr == target) {
    return (int)(itr - nums.begin());
  } else {
    itr = lower_bound(nums.begin() + pivot, nums.end(), target);
    if (itr == nums.end() || *itr != target) {
      return -1;
    } else {
      return (int)(itr - nums.begin());
    }
  }
}

int main() {
  // vector<int> v{4, 5, 6, 7, 0, 1, 2};
  vector<int> v{1};
  cout << search(v, 0) << endl;
}