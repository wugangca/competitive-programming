#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
1 2 3
4 5 6
7 8 9
*/

int main() {
  string w;
  cin >> w;
  int r, c;
  cin >> r >> c;
  vector<vector<char>> grid(r, vector<char>(c));

  vector<vector<bool>> visited(r, vector<bool>(c, false));

  struct Location {
    int row;
    int col;
    int index;
    char direction;
    bool changedDirection;
  };
  queue<Location> q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == w[0]) {
        q.push({r, c, 0, 0, false});
      }
    }
  }

  int count = 0;
  int lastIndex = w.length() - 1;

  while (!q.empty()) {
    Location location = q.front();
    q.pop();
    int index = location.index;
    if (index == lastIndex) {
      count++;
      continue;
    }
    int row = location.row;
    int col = location.col;
    int direction = location.direction;
    bool changedDirection = location.changedDirection;
    if (row > 0 && col > 0 && !visited[row - 1][col - 1] &&
        grid[row - 1][col - 1] == w[index + 1]) {
      // up-left
      if (direction == 0 || direction == 1) {
        q.push({row - 1, col - 1, index + 1, 1, changedDirection});
        visited[row - 1][col - 1] = true;
      } else if ((direction == 3 || direction == 7) &&
                 changedDirection == false) {
        q.push({row - 1, col - 1, index + 1, 1, true});
        visited[row - 1][col - 1] = true;
      }
    } else if (row > 0 && !visited[row - 1][col] &&
               grid[row - 1][col] == w[index + 1]) {
      // up
      if (direction == 0 || direction == 2) {
        q.push({row - 1, col, index + 1, 2, changedDirection});
        visited[row - 1][col] = true;
      } else if ((direction == 4 || direction == 6) &&
                 changedDirection == false) {
        q.push({row - 1, col, index + 1, 2, true});
        visited[row - 1][col] = true;
      }
    } else if (row > 0 && col < c - 1 && !visited[row - 1][col + 1] &&
               grid[row - 1][col + 1] == w[index + 1]) {
      // up-right
      if (direction == 0 || direction == 3) {
        q.push({row - 1, col + 1, index + 1, 3, changedDirection});
        visited[row - 1][col + 1] = true;
      } else if ((direction == 1 || direction == 9) &&
                 changedDirection == false) {
        q.push({row - 1, col + 1, index + 1, 3, true});
        visited[row - 1][col + 1] = true;
      }
    } else if (col > 0 && !visited[row][col - 1] &&
               grid[row][col - 1] == w[index + 1]) {
      // left
      if (direction == 0 || direction == 4) {
        q.push({row, col - 1, index + 1, 4, changedDirection});
        visited[row][col - 1] = true;
      } else if ((direction == 2 || direction == 8) &&
                 changedDirection == false) {
        q.push({row, col - 1, index + 1, 4, true});
        visited[row][col - 1] = true;
      }
    } else if (col < c - 1 && !visited[row][col + 1] &&
               grid[row][col + 1] == w[index + 1]) {
      // right
      if (direction == 0 || direction == 6) {
        q.push({row, col + 1, index + 1, 6, changedDirection});
        visited[row][col + 1] = true;
      } else if ((direction == 2 || direction == 8) &&
                 changedDirection == false) {
        q.push({row, col + 1, index + 1, 6, true});
        visited[row][col + 1] = true;
      }
    } else if (row < r - 1 && col > 0 && !visited[row + 1][col - 1] &&
               grid[row + 1][col - 1] == w[index + 1]) {
      // down-left
      if (direction == 0 || direction == 7) {
        q.push({row + 1, col - 1, index + 1, 7, changedDirection});
        visited[row + 1][col - 1] = true;
      } else if ((direction == 1 || direction == 9) &&
                 changedDirection == false) {
        q.push({row + 1, col - 1, index + 1, 7, true});
        visited[row + 1][col - 1] = true;
      }
    } else if (row < r - 1 && !visited[row + 1][col] &&
               grid[row + 1][col] == w[index + 1]) {
      // down
      if (direction == 0 || direction == 8) {
        q.push({row + 1, col, index + 1, 8, changedDirection});
        visited[row + 1][col] = true;
      } else if ((direction == 4 || direction == 6) &&
                 changedDirection == false) {
        q.push({row + 1, col, index + 1, 8, true});
        visited[row + 1][col] = true;
      }
    } else if (row < r - 1 && col < c - 1 && !visited[row + 1][col + 1] &&
               grid[row + 1][col + 1] == w[index + 1]) {
      // down-right
      if (direction == 0 || direction == 9) {
        q.push({row + 1, col + 1, index + 1, 9, changedDirection});
        visited[row + 1][col + 1] = true;
      } else if ((direction == 3 || direction == 7) &&
                 changedDirection == false) {
        q.push({row + 1, col + 1, index + 1, 9, true});
        visited[row + 1][col + 1] = true;
      }
    }
  }
  cout << count;
}