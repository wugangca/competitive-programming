#include <iostream>
#include <stack>
using namespace std;

int main() {
  int k;
  cin >> k;
  stack<int> s;

  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    if (n == 0) {
      s.pop();
    } else {
      s.push(n);
    }
  }

  int total = 0;
  while (!s.empty()) {
    total += s.top();
    s.pop();
  }
  cout << total;
  return 0;
}