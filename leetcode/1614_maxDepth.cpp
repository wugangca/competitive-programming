#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
  stack<char> st;
  int maxNest = 0;
  int currentNest = 0;
  for (char ch : s) {
    if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      maxNest = max(maxNest, (int)st.size());
      st.pop();
    }
  }
  return maxNest;
}