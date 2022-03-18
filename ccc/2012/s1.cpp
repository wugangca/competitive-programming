#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << 0;
  } else {
    //from (n-1) numbers, choose 3 numbers
    n--;
    cout << n * (n - 1) * (n - 2) / 6 << "\n";
  }
}