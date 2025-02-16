/*
1. Use a counting array to count how many times a row is painted
2. Use a counting array to count how many times a column is painted
3. The cell's color is decided by its counting on row and column
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  vector<int> row(m + 1);
  vector<int> col(n + 1);

  for (int i = 0; i < k; i++) {
    char c;
    int num;
    cin >> c >> num;
    if (c == 'R') {
      row[num]++;
    } else {
      col[num]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if ((row[i] + col[j]) % 2 == 1) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
