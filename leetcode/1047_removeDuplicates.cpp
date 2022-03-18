#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
  stack<char> st;
  for (char ch : s) {
    if (!st.empty()) {
      char top = st.top();
      if (top == ch) {
        st.pop();
        continue;
      }
    }
    st.push(ch);
  }

  string ans(st.size(), ' ');
  int i = st.size() - 1;
  while (!st.empty()) {
    ans[i] = st.top();
    i--;
    st.pop();
  }
  return ans;
}