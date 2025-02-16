#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    const int MOD = 1e9 + 7;
    sort(inventory.begin(), inventory.end(), greater());
    inventory.push_back(0);
    int count = 1;
    long long ans = 0;
    for (int i = 0; i < inventory.size() - 1; i++) {
      long long cur = inventory[i];
      long long next = inventory[i + 1];
      // 10, 6-> 10, 9, 8, 7
      // suppose we have count = 3 colors of 10
      // then we can fill 3* 4 = 12 orders.
      // and put all the balls to 6 for the next round calculation
      // However, if the rest order is 8
      // then we can fill 3 of 10, 3 of 9, and 2 of 8
      long long diff = cur - next;
      long long totalFillable = diff * count;
      if (totalFillable > orders) {
        long long whole = orders / count;
        long long remainder = orders % count;
        ans = (ans + (cur + cur - whole + 1) * whole * count / 2) % MOD;
        ans = (ans + (cur - whole) * remainder) % MOD;
        break;
      } else {
        ans = (ans + (cur + cur - diff + 1) * totalFillable / 2) % MOD;
      }

      orders -= totalFillable;
      count++;
    }
    return ans;
  }
};