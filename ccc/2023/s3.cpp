#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> &grid, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;

  vector<vector<char>> ans(n, vector<char>(m, 'b'));

  if (r == n && c == m) {
    print(ans, n, m);
    return (0);
  }

  if (n == 1) {
    // Only one row, all columns must be panlindrome
    // if r == 1, then fill all 'b' are good
    // if r == 0, then change the first character to 'a'
    if (c != m) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (r == 1) {
      print(ans, n, m);
      return (0);
    } else {
      ans[0][0] = 'a';
      print(ans, n, m);
      return (0);
    }
  }

  if (m == 1) {
    // Only one column, all rows must be panlindrome
    // if c == 1, then fill all 'b' are good
    // if c == 0, then change the first character to 'a'
    if (r != n) {
      // one colmn, all rows are panlindrome
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (c == 1) {
      print(ans, n, m);
      return (0);
    } else {
      ans[0][0] = 'a';
      print(ans, n, m);
      return (0);
    }
  }

  for (int row = 0; row < r; row++) {
    for (int col = 0; col < m; col++) {
      // first r rows are all 'a'
      ans[row][col] = 'a';
    }
  }

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < c; col++) {
      // first c columns are all 'a'
      ans[row][col] = 'a';
    }
  }

  if (r == 0) {
    for (int col = c; col < m; col++) {
      ans[n - 1][col] = 'c';
    }
    // no row has palindrome, we have first c columns with 'a'
    // need to make the rest columns not panlindrome
    // put the bottom char to be 'c'
    //  a a b b b
    //  a a b b b
    //  a a c c c
  }

  if (c == 0) {
    for (int row = r; row < n; row++) {
      ans[row][m - 1] = 'd';
    }
    // no col has palindrome, we have first r rows with 'a'
    // need to make the rest rows not panlindrome
    // put the rightmost char to be 'd'
    //   a a a a a
    //   a a a a a
    //   b b b b d
    //   b b b b d
  }

  // if r==0 and c==0 we will have
  //   b b b b b
  //   b b b b b    =>
  //   b b b b b

  //  b b b b b
  //  b b b b b  =>
  //  c c c c c

  //  b b b b d
  //  b b b b d  =>
  //  c c c c d

  //  b b b b d
  //  b b b b d
  //  c c c c e

  if (r == 0 && c == 0) {
    // flip the last character to make sure no panlindromes
    ans[n - 1][m - 1] = 'e';
  }

  if (r == n) {
    // all rows are palindrome, we put all 'a' into the grid
    // need to make only c columns panlindrome
    // modify the first row, still make it palindrome, but only c columns are
    // 'a', rest are 'b'

    for (int col = 0; col < m; col++) {
      // first row are all 'b'. later fill c number of 'a' in pairs
      ans[0][col] = 'b';
    }

    if (c % 2 == 1 && m % 2 == 0) {
      // we need to fill odd columns of 'a', this makes the use the middle
      // column but the total number of columns is even.
      cout << "IMPOSSIBLE\n";
      return (0);
    }

    if (c % 2 == 1) {
      ans[0][m / 2] = 'a';
      c--;
    }
    int i = 0;
    int j = m - 1;
    while (c > 0) {
      ans[0][i] = 'a';
      ans[0][j] = 'a';
      i++;
      j--;
      c -= 2;
    }
  }

  if (c == m) {
    // all columns are palindrome, we put all 'a' into the grid
    // need to make only r rows panlindrome
    // modify the first column, still make it palindrome,
    // but only rows are 'a', rest are 'b'

    for (int row = 0; row < n; row++) {
      // first column are all 'b'. later fill r number of 'a' in pairs
      ans[row][0] = 'b';
    }

    if (r % 2 == 1 && n % 2 == 0) {
      // we need to fill odd rows of 'a', this makes the use the middle
      // row but the total number of rows is even.
      cout << "IMPOSSIBLE\n";
      return (0);
    }

    if (r % 2 == 1) {
      ans[n / 2][0] = 'a';
      r--;
    }
    int i = 0;
    int j = n - 1;
    while (r > 0) {
      ans[i][0] = 'a';
      ans[j][0] = 'a';
      i++;
      j--;
      r -= 2;
    }
  }

  print(ans, n, m);
}