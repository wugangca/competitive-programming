/*
Since we only have 6 games and each game has only 3 possibilities (win, lose, tie),
there are at most 3^6 possibilities and we can check all of them.
Construct a games vector on the 6 games {1-2, 1-3, 1-4, 2-3, 2-4, 3-4}
Each element can be 'w', 'l', 't', or ' '
For finished games, the values are fixed 'w', 'l', or 't'
For unfinished games, the values are ' '.

Construct a possibilities vector on the above 6 games.
If the game is finished, set the value to 1.
Otherwise set the value to 3.

Use nested loops to go through all possibilities on each game.
Once we have a fully filled games vector, we can check if the favorite team wins.
*/
#include <bits/stdc++.h>
using namespace std;

void addScore(vector<int>& scores, char status, int a, int b) {
  if (status == 'w') {
    scores[a] += 3;
  } else if (status == 'l') {
    scores[b] += 3;
  } else {
    scores[a] += 1;
    scores[b] += 1;
  }
}
int checkWin(vector<char>& games, int t) {
  vector<int> scores(5, 0);
  addScore(scores, games[0], 1, 2);
  addScore(scores, games[1], 1, 3);
  addScore(scores, games[2], 1, 4);
  addScore(scores, games[3], 2, 3);
  addScore(scores, games[4], 2, 4);
  addScore(scores, games[5], 3, 4);

  for (int i = 1; i <= 4; i++) {
    if (i == t) {
      continue;
    }
    if (scores[i] >= scores[t]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int t, g;
  cin >> t >> g;

  string s = "wlt";
  vector<char> games(6, ' ');
  vector<int> possibles(6, 3);
  for (int i = 0; i < g; i++) {
    int a, b, sa, sb;
    cin >> a >> b >> sa >> sb;
    char c;
    if (sa > sb) {
      c = 'w';
    } else if (sa < sb) {
      c = 'l';
    } else {
      c = 't';
    }
    int index = a + b - 2;
    if (a == 1) {
      index--;
    }
    games[index] = c;
    possibles[index] = 1;
  }
  int total = 0;

  for (int i = 0; i < possibles[0]; i++) {
    if (possibles[0] != 1) {
      games[0] = s[i];
    }
    for (int j = 0; j < possibles[1]; j++) {
      if (possibles[1] != 1) {
        games[1] = s[j];
      }
      for (int k = 0; k < possibles[2]; k++) {
        if (possibles[2] != 1) {
          games[2] = s[k];
        }
        for (int l = 0; l < possibles[3]; l++) {
          if (possibles[3] != 1) {
            games[3] = s[l];
          }
          for (int m = 0; m < possibles[4]; m++) {
            if (possibles[4] != 1) {
              games[4] = s[m];
            }
            for (int n = 0; n < possibles[5]; n++) {
              if (possibles[5] != 1) {
                games[5] = s[n];
              }

              total += checkWin(games, t);
            }
          }
        }
      }
    }
  }

  cout << total;
}