#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  vector<vector<char>> v(3, vector<char>(3, ' '));

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> v[i][j];

  int singleWin = 0;
  int teamWin = 0;

  set<string> winners;

  for (int row = 0; row < 3; row++) {
    if (v[row][0] == v[row][1] && v[row][1] == v[row][2]) {
      string winner = string(v[row][0], 1);
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        singleWin++;
      }
    } else if (v[row][0] == v[row][1]) {
      string winner = string(v[row][0], 1) + string(v[row][2], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    } else if (v[row][0] == v[row][2]) {
      string winner = string(v[row][0], 1) + string(v[row][1], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    } else if (v[row][1] == v[row][2]) {
      string winner = string(v[row][1], 1) + string(v[row][0], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    }
  }

  for (int col = 0; col < 3; col++) {
    if (v[0][col] == v[1][col] && v[1][col] == v[2][col]) {
      string winner = string(v[0][col], 1);
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        singleWin++;
      }
    } else if (v[0][col] == v[1][col]) {
      string winner = string(v[0][col], 1) + string(v[2][col], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    } else if (v[0][col] == v[2][col]) {
      string winner = string(v[0][col], 1) + string(v[1][col], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    } else if (v[1][col] == v[2][col]) {
      string winner = string(v[1][col], 1) + string(v[0][col], 1);
      sort(winner.begin(), winner.end());
      if (winners.count(winner) == 0) {
        winners.insert(winner);
        teamWin++;
      }
    }
  }

  if (v[0][0] == v[1][1] && v[1][1] == v[2][2]) {
    string winner = string(v[0][0], 1);
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      singleWin++;
    }
  } else if (v[0][0] == v[1][1]) {
    string winner = string(v[0][0], 1) + string(v[2][2], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }

  } else if (v[1][1] == v[2][2]) {
    string winner = string(v[1][1], 1) + string(v[0][0], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }
  } else if (v[0][0] == v[2][2]) {
    string winner = string(v[0][0], 1) + string(v[1][1], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }
  }

  if (v[0][2] == v[1][1] && v[1][1] == v[2][0]) {
    string winner = string(v[0][2], 1);
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      singleWin++;
    }
  } else if (v[0][2] == v[1][1]) {
    string winner = string(v[0][2], 1) + string(v[2][0], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }
  } else if (v[1][1] == v[2][0]) {
    string winner = string(v[1][1], 1) + string(v[0][2], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }
  } else if (v[0][2] == v[2][0]) {
    string winner = string(v[0][2], 1) + string(v[1][1], 1);
    sort(winner.begin(), winner.end());
    if (winners.count(winner) == 0) {
      winners.insert(winner);
      teamWin++;
    }
  }

  cout << singleWin << endl << teamWin;

  return 0;
}