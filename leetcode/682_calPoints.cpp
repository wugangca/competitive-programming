#include <bits/stdc++.h>
using namespace std;
int calPoints(vector<string>& ops) {
  stack<int> st;
  for (string op : ops) {
    if (op == "+") {
      int score1 = st.top();
      st.pop();
      int score2 = st.top();
      st.push(score1);
      st.push(score1 + score2);
    } else if (op == "D") {
      int score = st.top();
      st.push(2 * score);
    } else if (op == "C") {
      st.pop();
    } else {
      st.push(stoi(op));
    }
  }
  int sum = 0;
  while (!st.empty()) {
    sum += st.top();
    st.pop();
  }
  return sum;
}