#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("stacking.in", "r", stdin);
  freopen("stacking.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> diff (n+2, 0);
  for (int i = 0; i < k; i++) {
    int low, high;
    cin >> low >> high;
    diff[low]++;
    diff[high+1]--;
  }

  vector<int> stack(n+1, 0);

  for (int i = 1; i <= n; i++) {
      stack[i] = stack[i-1] + diff[i];
  }

  sort(stack.begin(), stack.end());
  
  cout << stack[(n + 1)/2] << endl;

  return 0;
}