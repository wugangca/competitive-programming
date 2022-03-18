#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
  int i = 0;
  int j = height.size() - 1;
  int ans = 0;

  while (i < j && height[i] <= height[i + 1]) {
    i++;
  }
  while (j > i && height[j] <= height[j - 1]) {
    j--;
  }
  int leftMax = height[i];
  int rightMax = height[j];
  while (i < j) {
    if (height[i] < height[j]) {
      if (height[i] < leftMax) {
        ans += leftMax - height[i];
      } else {
        leftMax = height[i];
      }
      i++;
    } else {
      if (height[j] < rightMax) {
        ans += rightMax - height[j];
      } else {
        rightMax = height[j];
      }
      j--;
    }
  }
  return ans;
}