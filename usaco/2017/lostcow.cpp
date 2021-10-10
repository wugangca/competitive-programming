#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  int x, y;
  cin >> x >> y;

  int position = 1;
  int total = 0;
  while (true) {
    if (y >= x && position > 0 && y <= x + position) {
      total += y - x;
      break;
    } else if (y < x && position < 0 && y >= x + position) {
      total += x - y;
      break;
    } else {
      total += 2 * abs(position);
      position *= -2;
    }
  }
  cout << total;

  return 0;
}