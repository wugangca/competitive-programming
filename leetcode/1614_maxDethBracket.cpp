#include <bits/stdc++.h>

using namespace std;
int maxDepth(string s) {
  stack<char> st;
  int ans = 0;
  for (char c : s) {
    if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      if (st.size() > ans) {
        ans = st.size();
      }
      st.pop();
    }
  }
  return ans;
}

int main() {
  string s = "(()(()))";

  cout << maxDepth(s);
}
