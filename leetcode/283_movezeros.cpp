#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
  int total = nums.size();
  int i = 0;
  while (i < total && nums[i] != 0) {
    i++;
  }
  for (int j = i + 1; j < total; j++) {
    if (nums[j] != 0) {
      nums[i] = nums[j];
      i++;
    }
  }
  for (int j = i; j < total; j++) {
    nums[j] = 0;
  }
}

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroes(nums);

  return 1;
}