/*
1. Use BFS, record the step in the BFS
2. We can preprocess the cameras. Make the camera locations are not accessible;
3. The start point (S) can also under the camera. In this case, all empty cells
are -1.
4. Conveyors can move forward (e.g. RRR.), hit dead end (e.g RW) or inifinite
loop (e.g. RL)
*/

#include <iostream>
#include <queue>
#include <vector>


using namespace std;
struct Cell {
  int i, j, step;
};
vector<string> v;
vector<vector<int>> ans;
queue<Cell> q;
int n, m;

void preprocess(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'W') {
        ans[i][j] = 0;
      } else if (v[i][j] == 'C') {
        ans[i][j] = 0;
        for (int k = j - 1; k > 0; k--) {
          if (v[i][k] == 'W')
            break;
          if (v[i][k] == '.' || v[i][k] == 'S') {
            ans[i][k] = 0;
          }
        }

        for (int k = j + 1; k < m - 1; k++) {
          if (v[i][k] == 'W')
            break;
          if (v[i][k] == '.' || v[i][k] == 'S') {
            ans[i][k] = 0;
          }
        }

        for (int k = i - 1; k > 0; k--) {
          if (v[k][j] == 'W')
            break;
          if (v[k][j] == '.' || v[k][j] == 'S') {
            ans[k][j] = 0;
          }
        }

        for (int k = i + 1; k < n - 1; k++) {
          if (v[k][j] == 'W')
            break;
          if (v[k][j] == '.' || v[k][j] == 'S') {
            ans[k][j] = 0;
          }
        }
      }
    }
  }
}

void pushStart() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'S') {
        if (ans[i][j] < 0) {
          q.push({i, j, 0});
          ans[i][j] = 0;
        }
        return;
      }
    }
  }
}

void move(int i, int j, int step) {
  while (true) {
    if (v[i][j] == '.') {
      q.push({i, j, step});
      ans[i][j] = step;
      break;
    }
    ans[i][j] = 0;
    if (v[i][j] == 'L' && ans[i][j - 1] < 0) {
      j--;
    } else if (v[i][j] == 'U' && ans[i - 1][j] < 0) {
      i--;
    } else if (v[i][j] == 'R' && ans[i][j + 1] < 0) {
      j++;
    } else if (v[i][j] == 'D' && ans[i + 1][j] < 0) {
      i++;
    } else {
      break;
    }
  }
}

int main() {
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ans.resize(n, vector<int>(m, -1));
  preprocess(n, m);
  pushStart();

  while (!q.empty()) {
    Cell cell = q.front();
    q.pop();
    int i = cell.i;
    int j = cell.j;
    int step = cell.step;

    if (ans[i][j - 1] < 0) {
      move(i, j - 1, step + 1);
    }
    if (ans[i - 1][j] < 0) {
      move(i - 1, j, step + 1);
    }
    if (ans[i][j + 1] < 0) {
      move(i, j + 1, step + 1);
    }
    if (ans[i + 1][j] < 0) {
      move(i + 1, j, step + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        if (ans[i][j] == 0) {
          cout << -1 << endl;
        } else {
          cout << ans[i][j] << endl;
        }
      }
    }
  }

  return 0;
}