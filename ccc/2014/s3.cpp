/*
Use two stacks to simulate the process
In each iteration, we either pop from the top or branch if the number is good
or pop from top and push to the branch if the number is not good
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    stack<int> top;
    for (int j = 0; j < n; j++) {
      int car;
      cin >> car;
      top.push(car);
    }

    stack<int> branch;
    int current = 1;
    while (true) {
      if (!top.empty() && top.top() == current) {
        top.pop();
        current++;
      } else if (!branch.empty() && branch.top() == current) {
        branch.pop();
        current++;
      } else if (!top.empty()) {
        int num = top.top();
        top.pop();
        branch.push(num);
      } else {
        break;
      }
    }

    if (branch.empty()) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }
}