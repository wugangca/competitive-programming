/*
A greedy algorithm is good enough to solve the problem.
For each plane, find the highest gate number that is empty to park.
A naive alogorithm takes O(P*G) time. 
We can use set to store empty gates (back-end is a balanced BST).
Use lower_bound function to find the highest empty gate number. 

Note lower_bound function returns the current number (if exists) or the next number (if not exist).
What we want is the current number or the previous number.
Therefore, we store the negative numbers in the set.
All set operations takes O(logG) time. Therefore, the overall time is O(P*logG)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int g, p;
  cin >> g >> p;

  set<int> gates;

  for (int i = 0; i <= g; i++) {
    gates.insert(-i);
  }

  int count = 0;
  for (int i = 0; i < p; i++) {
    int j;
    cin >> j;

    set<int>::iterator itr = gates.lower_bound(-j);
    if (*itr == 0) {
      break;
    } else {
      gates.erase(itr);
      count++;
    }
  }
  cout << count;
}