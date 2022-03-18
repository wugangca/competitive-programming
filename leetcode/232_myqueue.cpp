#include <bits/stdc++.h>

using namespace std;
class MyQueue {
 private:
  stack<int> st;

 public:
  MyQueue() {}

  void push(int x) {
    stack<int> st1;
    while (!st.empty()) {
      st1.push(st.top());
      st.pop();
    }
    st1.push(x);
    while (!st1.empty()) {
      st.push(st1.top());
      st1.pop();
    }
  }

  int pop() {
    int top = st.top();
    st.pop();
    return top;
  }

  int peek() { return st.top(); }

  bool empty() { return st.empty(); }
};