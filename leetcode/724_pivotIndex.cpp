
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
  int total = nums.size();
  vector<int> prefix(total + 1, 0);

  for (int i = 0; i < total; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  int sum = prefix[total];

  for (int i = 0; i < total; i++) {
    if (prefix[i] == sum - prefix[i + 1]) {
      return i;
    }
  }
  return -1;
}
int main() {
  vector<int> nums = {1,7,3,6,5,6};
  cout << pivotIndex(nums) << endl;

  return 0;
}