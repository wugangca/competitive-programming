#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<string>& logs) {
  stack<char> st;
  for (string log : logs) {
    if (log == "../") {
      if (st.size() > 0) {
        st.pop();
      }
    } else if (log != "./") {
      st.push(' ');
    }
  }
  return st.size();
}