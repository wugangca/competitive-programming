#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

/*
Use ranged dp
For a ranged dp[i, j] of length len, its asymetric value is

dp[i+1, j-1] + |h[i] - h[j]|

where  dp[i+1, j-1] is the ranged dp of len-2

len = 0: dp[i, i] = 0
len = 1: dp[i, i+1] =  |h[i] - h[i+1]|
....
len = k: dp[i, i+k] =  dp[i+1, i+k-1] + |h[i] - h[i+k]|

*/
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> ans(n, INT_MAX);
  ans[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    dp[i][i + 1] = abs(h[i] - h[i + 1]);
    ans[1] = min(ans[1], dp[i][i + 1]);
  }

  for (int len = 2; len < n; len++) {
    for (int i = 0; i < n - len; i++) {
      int j = i + len;
      dp[i][j] = dp[i + 1][j - 1] + abs(h[i] - h[j]);
      ans[len] = min(ans[len], dp[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}