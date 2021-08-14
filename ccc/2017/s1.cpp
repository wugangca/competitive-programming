#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> v2[i];
  }

  int sum1 = 0, sum2 = 0;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum1 += v1[i];
    sum2 += v2[i];
    if (sum1 == sum2) {
      ans = i + 1;
    }
  }
  cout << ans;

  return 0;
}