#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("proximity.in", "r", stdin);
  freopen("proximity.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector <int> positions (10000001, -1);
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
      int breed;
      cin >> breed;
      if (positions[breed] >= 0 && i - positions[breed] <=k ) {
          ans = max(ans, breed);
      }  
      positions[breed] = i;
  }
  cout << ans << endl;

  return 0;
}