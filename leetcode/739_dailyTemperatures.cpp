#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
  stack<int> st;
  st.push(0);
  int n = temperatures.size();
  vector<int> ans(n, 0);
  for (int i = 1; i < n; i++) {
    int index = st.top();
    while (temperatures[i] > temperatures[index]) {
      ans[index] = i - index;
      st.pop();
      if (st.empty()) {
        break;
      }
      index = st.top();
    }
    st.push(i);
  }

  class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int len = temperatures.size();
      vector<int> ans(len, 0);
      stack<int> st;
      for (int i = len - 1; i >= 0; i--) {
        int temp = temperatures[i];
        while (!st.empty() && temperatures[st.top()] <= temp) {
          st.pop();
        }
        if (!st.empty()) {
          ans[i] = st.top() - i;
        }
        st.push(i);
      }
      return ans;
    }
  };
  return ans;
}