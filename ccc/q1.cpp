#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sign = 1;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    if (num == 0) {
      sign = 0;
      break;
    } else if (num < 0) {
      sign = -sign;
    }
  }
  if (sign == 0) {
    cout << 0 << endl;
  } else if (sign == 1) {
    cout << 1 << endl;
  } else {
    cout << -1 << endl;
  }
}