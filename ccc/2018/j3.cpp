#include <iostream>
using namespace std;

int main() {
  int dist[5][5];
  cin >> dist[0][1] >> dist[1][2] >> dist[2][3] >> dist[3][4];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) dist[i][j] = 0;
      else if (i > j) dist [i][j] = dist[j][i];
      else dist[i][j] = dist[i][j-1] + dist[j-1][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j > 0) cout << " ";
      cout << dist[i][j];
    }
    cout << "\n";
  }
  return 0;
}


