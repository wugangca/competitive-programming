#include <bits/stdc++.h>

using namespace std;

int main() {
   freopen("clumsy.in", "r", stdin);
   freopen("clumsy.out", "w", stdout);
  string s;
  cin >> s;
  stack<char> stack;
  for (char c: s) {
      if (c == ')' && stack.size() > 0 && stack.top() == '(') {
          stack.pop();
      } else {
          stack.push(c);
      }
  }
  int ans = 0;

  while (stack.size() > 1) {
      char c1 = stack.top();
      stack.pop();
      char c2 = stack.top();
      stack.pop();
      if (c1 == c2) {
          ans+=1;
      } else {
          ans+=2;
      }
  }
  cout << ans;
  
  

  return 0;
}