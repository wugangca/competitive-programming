#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
  string ans = "";
  stack<char> st;
  for (char ch : s) {
    if (st.empty()) {
      st.push(ch);
    } else if (ch == ')') {
      st.pop();
      if (st.size() > 0) {
        ans += ")";
      }
    } else {
      st.push(ch);
      ans += ch;
    }
  }
  return ans;
}