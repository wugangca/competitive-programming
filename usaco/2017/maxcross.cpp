#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>      // std::partial_sum
using namespace std;

int sol(vector<int>& s, int n, int k) {
  vector<int> prefix(n + 1);
  partial_sum(s.begin(), s.end(), prefix.begin());
  int ans = INT_MAX;
  for (int i = 0; i <= n - k; i++) {
    ans = min(ans, prefix[i + k] - prefix[i]);
  }

  return ans;
}

int main() {
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);
  int n, k, b;
  cin >> n >> k >> b;
  int id;

  vector<int> s(n + 1, 0);
  for (int i = 0; i < b; i++) {
    cin >> id;
    s[id] = 1;
  }
  cout << sol(s, n, k) << endl;

  // int total = 0;
  // for (int i = 1; i <= k; i++) {
  //   total += s[i];
  // }

  // int ans = total;
  // int start = 1;
  // int end = k;
  // while (end <= n) {
  //   total -= s[start];
  //   start++;
  //   end++;
  //   if (end <= n) {
  //     total += s[end];
  //   } else {
  //     break;
  //   }
  //   ans = min(ans, total);
  // }

  // cout << ans << endl;

  return 0;
}