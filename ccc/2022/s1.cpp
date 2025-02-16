#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int i = 0;
  int total = 0;

  while (i <= n) {
    if ((n - i) % 5 == 0) {
      total++;
    }
    i += 4;
  }

  cout << total;
}