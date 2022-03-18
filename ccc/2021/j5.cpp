#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, k;

  cin >> m >> n >> k;

  vector< vector<int>>v (m+1, vector<int>(n+1, 0));

  for (int i = 0; i < k; i++) {
    char ch; 
    int num;
    cin >> ch >> num;
    if (ch == 'R') {
      for (int j = 1; j <=n; j++) {
        v[num][j] = (v[num][j] + 1) % 2;
      }
    } else {
      for (int j = 1; j <=m; j++) {
        v[j][num] = (v[j][num] + 1) % 2;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <=m; i++) {
    for (int j = 1; j <=n; j++) {
      ans+=v[i][j];

    }
  }

  cout << ans;

}