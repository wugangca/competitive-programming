#include <bits/stdc++.h>
using namespace std;
int sumOfUnique(vector<int>& nums) {
  map<int, int> m;
  for (int num : nums) {
    if (m.count(num) == 0) {
      m[num] = 1;
    } else {
      m[num]++;
    }
  }

  int sum = 0;
  for (int num : nums) {
    if (m[num] == 1) {
      sum += num;
    }
  }
  return sum;
}