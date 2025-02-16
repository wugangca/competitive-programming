#include <iostream>
#include <set>

using namespace std;

int main() {
  set<pair<int, int>> well;
  well.insert({0, -1});
  well.insert({0, -2});
  well.insert({0, -3});
  well.insert({1, -3});
  well.insert({2, -3});
  well.insert({3, -3});
  well.insert({3, -4});
  well.insert({3, -5});
  well.insert({4, -5});
  well.insert({5, -5});
  well.insert({5, -4});
  well.insert({5, -3});
  well.insert({6, -3});
  well.insert({7, -3});
  well.insert({7, -4});
  well.insert({7, -5});
  well.insert({7, -6});
  well.insert({7, -7});
  well.insert({6, -7});
  well.insert({5, -7});
  well.insert({4, -7});
  well.insert({3, -7});
  well.insert({2, -7});
  well.insert({1, -7});
  well.insert({0, -7});
  well.insert({-1, -7});
  well.insert({-1, -6});
  well.insert({-1, -5});

  int x = -1;
  int y = -5;
  while (true) {
    char dir;
    int len;
    cin >> dir >> len;
    if (dir == 'q') {
      break;
    }
    bool safe = true;
    if (dir == 'l') {
      while (len > 0) {
        x--;
        if (well.count({x, y}) == 1) {
          safe = false;

        } else {
          well.insert({x, y});
        }
        len--;
      }
    } else if (dir == 'r') {
      while (len > 0) {
        x++;
        if (well.count({x, y}) == 1) {
          safe = false;
        } else {
          well.insert({x, y});
        }
        len--;
      }

    } else if (dir == 'u') {
      while (len > 0) {
        y++;
        if (well.count({x, y}) == 1) {
          safe = false;
        } else {
          well.insert({x, y});
        }
        len--;
      }

    } else if (dir == 'd') {
      while (len > 0) {
        y--;
        if (well.count({x, y}) == 1) {
          safe = false;
        } else {
          well.insert({x, y});
        }
        len--;
      }
    }
    if (safe) {
      cout << x << " " << y << " safe\n";
    } else {
      cout << x << " " << y << " DANGER\n";
      break;
    }
  }
}