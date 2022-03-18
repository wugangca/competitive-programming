#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  for (char ch : s) {
    if (st.empty()) {
      st.push(ch);
    } else {
      char top = st.top();
      if (top == '(' && ch == ')' || top == '[' && ch == ']' ||
          top == '{' && ch == '}') {
        st.pop();
      } else {
        st.push(ch);
      }
    }
  }
  return st.empty();
}