#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string S) {
  stack<int> st;

  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '(') {
      st.push(0);
    } else {
      int top = st.top();
      int sum = 0;
      while (top > 0) {
          sum += top;
          st.pop();
          top = st.top();
      }
      st.pop();
      st.push( max(sum * 2, 1));
    }
  }

  int ans = 0;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main() {
  string s = "(()(()))";

  cout << scoreOfParentheses(s);
}
