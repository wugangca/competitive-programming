#include <bits/stdc++.h>

using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> stack;
  for (int a : asteroids) {
    if (stack.empty()) {
      stack.push(a);
    } else {
      int top = stack.top();
      bool push = true;
      while (top > 0 && a < 0 && !stack.empty()) {
        if (abs(top) > abs(a)) {
          push = false;
          break;
        } else if (abs(top) == abs(a)) {
          stack.pop();
          push = false;
          break;
        } else {
          stack.pop();
          if (!stack.empty()) top = stack.top();
        }
      }
      if (push) {
        stack.push(a);
      }
    }
  }

  int size = stack.size();
  vector<int> result(size);
  for (int i = size - 1; i >= 0; i--) {
    result[i] = stack.top();
    stack.pop();
  }
  return result;
}

int main() {
  vector<int> v{5,10,-5};

  asteroidCollision(v);
}