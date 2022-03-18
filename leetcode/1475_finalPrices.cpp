#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    // next smaller
    int len = prices.size();
    stack<int> st;
    vector<int> ans(prices);
    for (int i = len - 1; i >= 0; i--) {
      int price = prices[i];
      while (!st.empty() && st.top() > price) {
        st.pop();
      }
      if (!st.empty()) {
        ans[i] = price - st.top();
      }
      st.push(price);
    }
    return ans;
  }
};