#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cost = 0;
  cin >> n;

  while (n > 1) {
    for (int i = 2; i <= n; i++)
      if (n % i == 0) {
        int temp = n / i;
        n -= temp;
        cost += n / temp;
        break;
      }
  }

  cout << cost << "\n";
}