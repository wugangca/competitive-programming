#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> sumCount;
       int sum = 0;
       int count = 0;
       sumCount[0] = 1;
       for (int i = 0; i < nums.size(); i++) {
          sum += nums[i];
          int other = sum-k;
          if (sumCount.find(other) != sumCount.end()) {
               count += sumCount[other];
          }
          if (sumCount.find(sum) != sumCount.end()) {
              sumCount[sum]++;
          } else {
              sumCount[sum] = 1;    
          }
       }
       return count;
    }

int main() {
  vector<int> nums = {1, 2, 3};
  cout << subarraySum(nums, 3) << endl;

  return 0;
}