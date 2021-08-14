#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 1;
  int dice = 0;
  while (true) {
    cin >> dice;
    if (dice == 0) {
      cout << "You Quit!" << endl;
      break;
    }
    n += dice;
    if (n > 100) {
      n -= dice;
    } else if (n == 54) {
      n = 19;
    } else if (n == 90) {
      n = 48;
    } else if (n == 99) {
      n = 77;
    } else if (n == 9) {
      n = 34;
    } else if (n == 40) {
      n = 64;
    } else if (n == 67) {
      n = 86;
    }
    cout << "You are now on square " << n << endl;
    if (n == 100) {
      cout << "You Win!" << endl;
      break;
    }
  }
}
