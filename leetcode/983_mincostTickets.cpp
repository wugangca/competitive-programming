#include <bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
  int n = days.size();
  int first = days[0];
  int lastDay = days[n - 1];

  vector<int> dp(lastDay + 1, -1);
  for (int i = 0; i < first; i++) {
    dp[i] = 0;
  }
  for (int day : days) {
    dp[day] = 0;
  }

  for (int i = days[0]; i <= lastDay; i++) {
    if (dp[i] < 0) {
      dp[i] = dp[i - 1];
      continue;
    }
    int cost = dp[i - 1] + costs[0];
    if (i >= 7) {
      cost = min(cost, dp[i - 7] + costs[1]);
    } else {
      cost = min(cost, costs[1]);
    }
    if (i >= 30) {
      cost = min(cost, dp[i - 30] + costs[2]);
    } else {
      cost = min(cost, costs[2]);
    }
    dp[i] = cost;
  }
  return dp[lastDay];
}

int main() {
  vector<int> days = {6, 8, 9, 18, 20, 21, 23, 25};
  vector<int> costs = {2, 10, 41};

  cout << mincostTickets(days, costs);
}