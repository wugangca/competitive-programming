#include <bits/stdc++.h>

using namespace std;

int main() {
   freopen("dishes.in", "r", stdin);
   freopen("dishes.out", "w", stdout);
  int n;
  cin >> n;
  
  vector<int>base;
  vector<stack<int>> stacks;
  int poped =0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
      int d;
      cin >> d;
      if (d < poped) {
          ans = i;
          break;
      }
      vector<int>::iterator lower = lower_bound(base.begin(), base.end(), d);
      
      if (lower == base.end()) {
          stack<int> s;
          s.push(d);
          stacks.push_back(s);
          base.push_back(d);
      } else {
          int index = lower - base.begin();
          while (!stacks[index].empty() && stacks[index].top() < d) {
              poped = stacks[index].top();
              stacks[index].pop();
          }
          stacks[index].push(d);
      }
  }
  cout<< ans << endl;
  return 0;
}