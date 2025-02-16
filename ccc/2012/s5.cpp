
/*classic grid DP
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, c, k;
  cin >> r >> c >> k;
  vector<vector<int>> grid(r + 1, vector<int>(c + 1, 0));

  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = -1;
  }

  grid[1][1] = 1;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (i == 1 && j == 1) {
        continue;
      }
      if (grid[i][j] < 0) {
        grid[i][j] = 0;
      } else {
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
      }
    }
  }

  cout << grid[r][c];
}