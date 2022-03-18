#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> nextGreater;
  vector<int> ans(nums1.size(), -1);
  stack<int> st;
  st.push(0);
  for (int i = 1; i < nums2.size(); i++) {
    int top = st.top();
    int num2 = nums2[top];
    int cur = nums2[i];
    while (!st.empty()) {
      top = st.top();
      num2 = nums2[top];
      if (cur > num2) {
        nextGreater[num2] = cur;
        st.pop();
      } else {
        break;
      }
    }
    st.push(i);
  }

  for (int i = 0; i < nums1.size(); i++) {
    int num1 = nums1[i];
    if (nextGreater.find(num1) != nextGreater.end()) {
      ans[i] = nextGreater[num1];
    }
  }
  return ans;
}

vector<int> findNextGreat(const vector<int>& v) {
  int len = v.size();
  vector<int> ans(len, -1);
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (v[j] > v[i]) {
        ans[i] = j;
        break;
      }
    }
  }
  return ans;
}

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> nextG;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--) {
      int num2 = nums2[i];
      while (!st.empty() && st.top() <= num2) {
        st.pop();
      }
      if (st.empty()) {
        nextG[num2] = -1;
      } else {
        nextG[num2] = st.top();
      }
      st.push(num2);
    }

    vector<int> ans(nums1.size(), 0);
    for (int i = 0; i < nums1.size(); i++) {
      ans[i] = nextG[nums1[i]];
    }
    return ans;
  }
};