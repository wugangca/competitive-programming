#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n = 1;

  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    int k = sqrt(n);
    // while (n % k != 0) {
    //   k--;
    // }
    int minP = INT_MAX;
    int minL = 0;
    int minW = 0;
    for (int i = 1; i <= k; i++) {
      if (n % i == 0) {
        int p = 2 * (i + n / i);
        if (p < minP) {
          minP = p;
          minL = i;
          minW = n / i;
        }
      }
    }
    cout << "Minimum perimeter is " << minP << " with dimensions " << minL
         << " x " << minW << endl;

    // cout << "Minimum perimeter is " << 2 * (k + n / k) << " with dimensions "
    //      << k << " x " << n / k << endl;
  }
}