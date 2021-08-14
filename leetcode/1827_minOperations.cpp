#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
  int num = nums[0];
  int total = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] <= num) {
      num++;
      total += num - nums[i];
    } else {
      num = nums[i];
    }
  }
  return total;
}