#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& v, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (v[i][j] >= v[i][j + 1]) {
        return false;
      }
    }
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i][j] >= v[i + 1][j]) {
        return false;
      }
    }
  }

  return true;
}

void rotate(vector<vector<int>>& v, int n) {
  vector<vector<int>> v1(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n ; j++) {
      v1[j][n - 1 - i] = v[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = v1[i][j];
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  while (!isValid(v, n)) {
    rotate(v, n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}