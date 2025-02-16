/*
Use the DFS to traverse all possible rooms starting from the exit.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;

struct RoomLocation {
  int row;
  int col;
};

unordered_map<int, vector<RoomLocation>> roomMap;
vector<vector<bool>> visited;

bool check(int m, int n) {
  queue<RoomLocation> q;
  RoomLocation exit;
  exit.row = m;
  exit.col = n;
  q.push(exit);

  visited[m - 1][n - 1] = true;

  while (!q.empty()) {
    RoomLocation room = q.front();
    q.pop();
    if (room.row == 1 && room.col == 1) {
      return true;
    }
    int val = room.row * room.col;

    if (roomMap.find(val) != roomMap.end()) {
      vector<RoomLocation> rooms = roomMap[val];
      for (int i = 0; i < (int)rooms.size(); i++) {
        int r = rooms[i].row - 1;
        int c = rooms[i].col - 1;
        if (!visited[r][c]) {
          visited[r][c] = true;
          q.push(rooms[i]);
        }
      }
    }
  }

  return false;
}

int main() {
  int m, n;
  cin >> m >> n;
  visited = vector<vector<bool>>(m, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int value;
      cin >> value;
      RoomLocation room;
      room.row = i + 1;
      room.col = j + 1;
      roomMap[value].push_back(room);
    }
  }

  if (check(m, n))
    printf("yes");
  else
    printf("no");
  return 0;
}