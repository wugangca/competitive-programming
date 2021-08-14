/*
1. If only one X in a row or column, easy to solve.
   We first clear this case.
2. If there exists two Xs in a row or column (no three Xs), it could be:

   There is a 2x2 squre that contains 3 numbers, e.g.
     1 2 3    X 2 X
     4 X X    1 3 5
     7 X X    X 4 X
   In this case, we solve the 2x2 first.
   Then go to case 1 (only one X)

   All rows and columns have 2 X
     1 X X      X 1 X
     X 2 X      2 X X
     X X 3      X X 3
   In this case, we first make the middle row have the same number.
   Then go to case 1

3. If there exists 3 Xs (could be 2 Xs and 3Xs), it could be:

   There is a 2x2 squre that contains 2 numbers, e.g.
     1 2 3      1 X X     1 X X
     X X X      2 X X     X 2 X
     X X X      3 X X     X X X
   In this case, we solve the 2x2 first.
   Then go to case 1 (only one X)
   Note we cannot use this for case 2 (case 2 is more strictly, need 3 numbers
in a 2x2). This is because we can have a row/col with 3 Xs that is flexible to
fill any numbers.

  If we cannot find a 2x2 with 2 numbers, it could be:
   All X, we fill table with 0s

   only one non-X, we fill table with that number

   only two non-X, we can:
     Make the two adjacent rows/columns the same number:
      1 X X        1 1 1
      X X 2  ->    2 2 2
      X X X        X X X

      1 X X        1 2 X
      X X X  ->    1 2 X
      X 2 X        1 2 X

     or if no adjacent, move the two numbers into the same row.
      1 X X        1 X 3
      X X X   ->   X X X
      X X 3        1 X 3

*/

#include <bits/stdc++.h>
using namespace std;

#define X 1000000001
vector<vector<long long>> v(3, vector<long long>(3, X));

bool isSolved() {
  for (vector<long long> r : v) {
    for (long long d : r) {
      if (d == X) {
        return false;
      }
    }
  }
  return true;
}

void print() {
  cout << v[0][0] << " " << v[0][1] << " " << v[0][2] << endl;
  cout << v[1][0] << " " << v[1][1] << " " << v[1][2] << endl;
  cout << v[2][0] << " " << v[2][1] << " " << v[2][2] << endl;
}

void solveOne() {
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < 3; i++) {
      if (v[i][0] == X && v[i][1] != X && v[i][2] != X) {
        v[i][0] = v[i][1] - (v[i][2] - v[i][1]);
        changed = true;
      } else if (v[i][0] != X && v[i][1] == X && v[i][2] != X) {
        v[i][1] = (v[i][2] + v[i][0]) / 2;
        changed = true;
      } else if (v[i][0] != X && v[i][1] != X && v[i][2] == X) {
        v[i][2] = v[i][1] + (v[i][1] - v[i][0]);
        changed = true;
      }
    }

    for (int j = 0; j < 3; j++) {
      if (v[0][j] == X && v[1][j] != X && v[2][j] != X) {
        v[0][j] = v[1][j] - (v[2][j] - v[1][j]);
        changed = true;
      } else if (v[0][j] != X && v[1][j] == X && v[2][j] != X) {
        v[1][j] = (v[2][j] + v[0][j]) / 2;
        changed = true;
      } else if (v[0][j] != X && v[1][j] != X && v[2][j] == X) {
        v[2][j] = v[1][j] + (v[1][j] - v[0][j]);
        changed = true;
      }
    }
  }
}

bool solve2x2_3() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int count = (v[i][j] != X) + (v[i][j + 1] != X) + (v[i + 1][j] != X) +
                  (v[i + 1][j + 1] != X);
      if (count == 3) {
        if (v[i][j] == X) {
          v[i][j] = v[i + 1][j] - (v[i + 1][j + 1] - v[i][j + 1]);
        } else if (v[i][j + 1] == X) {
          v[i][j + 1] = v[i + 1][j + 1] - (v[i + 1][j] - v[i][j]);
        } else if (v[i + 1][j] == X) {
          v[i + 1][j] = v[i][j] + (v[i + 1][j + 1] - v[i][j + 1]);
        } else {
          v[i + 1][j + 1] = v[i][j + 1] + (v[i + 1][j] - v[i][j]);
        }
        return true;
      }
    }
  }
  return false;
}

void solveTwo() {
  if (solve2x2_3()) {
    solveOne();
    return;
  }
  for (int i = 0; i < 3; i++) {
    int count = (v[i][0] == X) + (v[i][1] == X) + (v[i][2] == X);
    if (count != 2) return;
  }

  for (int j = 0; j < 3; j++) {
    int count = (v[0][j] == X) + (v[1][j] == X) + (v[2][j] == X);
    if (count != 2) return;
  }

  if (v[1][0] != X) {
    v[1][1] = v[1][2] = v[1][0];
  } else if (v[1][1] != X) {
    v[1][0] = v[1][2] = v[1][1];
  } else {
    v[1][1] = v[1][0] = v[1][2];
  }
  solveOne();
}

void solve2x2_2() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int count = (v[i][j] != X) + (v[i][j + 1] != X) + (v[i + 1][j] != X) +
                  (v[i + 1][j + 1] != X);
      if (count == 2) {
        if (v[i][j] == X) {
          if (v[i + 1][j] != X) {
            v[i][j] = v[i + 1][j];
          } else {
            v[i][j] = v[i][j + 1];
          }
        }

        if (v[i][j + 1] == X) {
          if (v[i + 1][j + 1] != X) {
            v[i][j + 1] = v[i + 1][j + 1];
          } else {
            v[i][j + 1] = v[i][j];
          }
        }

        if (v[i + 1][j] == X) {
          if (v[i][j] != X) {
            v[i + 1][j] = v[i][j];
          } else {
            v[i + 1][j] = v[i + 1][j + 1];
          }
        }

        if (v[i + 1][j + 1] == X) {
          if (v[i][j + 1] != X) {
            v[i + 1][j + 1] = v[i][j + 1];
          } else {
            v[i + 1][j + 1] = v[i + 1][j];
          }
        }
        return;
      }
    }
  }
}

void solveThree() {
  solve2x2_2();
  solveOne();
  if (isSolved()) {
    return;
  }
  vector<pair<int, int>> nonX;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (v[i][j] != X) {
        nonX.push_back({i, j});
      }
    }
  }
  if (nonX.size() == 0) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        v[i][j] = 0;
      }
    }
  } else if (nonX.size() == 1) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        v[i][j] = v[nonX[0].first][nonX[0].second];
      }
    }
  } else if (nonX.size() == 2) {
    int i1 = nonX[0].first;
    int j1 = nonX[0].second;
    int i2 = nonX[1].first;
    int j2 = nonX[1].second;
    if (i1 + 1 == i2) {
      for (int j = 0; j < 3; j++) {
        v[i1][j] = v[i1][j1];
        v[i2][j] = v[i2][j2];
      }
    } else if (abs(j1 - j2) == 1) {
      for (int i = 0; i < 3; i++) {
        v[i][j1] = v[i1][j1];
        v[i][j2] = v[i2][j2];
      }
    } else {
      // move the two numbers into the same row.
      v[i1][j2] = v[i2][j2];
      v[i2][j1] = v[i1][j1];
    }
    solveOne();
  }
}

int main() {
  string s;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> s;
      if (s == "X") {
        v[i][j] = X;
      } else {
        v[i][j] = stoi(s);
      }
    }
  }

  solveOne();
  if (isSolved()) {
    print();
    return 0;
  }

  solveTwo();
  if (isSolved()) {
    print();
    return 0;
  }

  solveThree();
  print();

  return 0;
}