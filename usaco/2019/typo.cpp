#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("typo.in", "r", stdin);
  freopen("typo.out", "w", stdout);
  string s;
  cin >> s;
  stack<char> stack;
  int count = 0;
  for (char c : s) {
    if (c == ')') count++;

    if (c == ')' && stack.size() > 0 && stack.top() == '(') {
      stack.pop();
    } else {
      stack.push(c);
    }
  }

  if (!stack.empty()) {
    if (stack.top() == ')') {
      count--;
    } else {
      count = 1;
    }
  }
  cout << count;
  // cout << stack.size() /2 + matched;

  return 0;
}