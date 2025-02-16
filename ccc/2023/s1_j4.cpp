#include <iostream>
#include <vector>
using namespace std;

int main() {
  int c;
  cin >> c;
  vector<int> row1(c, 0);
  vector<int> row2(c, 0);

  for (int i = 0; i < c; i++) {
    cin >> row1[i];
  }
  for (int i = 0; i < c; i++) {
    cin >> row2[i];
  }

  int count = 0;
  for (int i = 0; i < c; i++) {
    if (row1[i] == 1) {
      if (i % 2 == 1) {
        count++; // top row, top edge of the every second triangle
      }
      if (i == 0 || row1[i - 1] == 0) {
        count++; // top row, left edge
      }
      if (i == c - 1 || row1[i + 1] == 0) {
        count++; // top row, right edge
      }
    }
  }
  for (int i = 0; i < c; i++) {
    if (row2[i] == 1) {
      if (i % 2 == 1) {
        count++; // second row, bottom edge of the every second triangle
      }
      if (i == 0 || row2[i - 1] == 0) {
        count++; // second row, left edge
      }
      if (i == c - 1 || row2[i + 1] == 0) {
        count++; // second row, right edge
      }
    }
  }
  for (int i = 0; i < c; i += 2) {
    if (row1[i] != row2[i]) {
      count++; // the common edge between row1 and row2
    }
  }
  cout << count;
}