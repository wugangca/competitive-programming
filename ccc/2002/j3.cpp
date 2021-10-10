#include <bits/stdc++.h>
using namespace std;

int main() {
  int pink, green, red, orange, total;
  cin >> pink >> green >> red >> orange >> total;
  INT_MAX
  int count = 0;
  int minTicket = total;
  for (int i = 0; i <= total; i++) {
    for (int j = 0; j <= total; j++) {
      for (int k = 0; k <= total; k++) {
        for (int l = 0; l <= total; l++) {
          if (pink * i + green * j + red * k + orange * l == total) {
            cout << "# of PINK is " << i << " # of GREEN is " << j
                 << " # of RED is " << k << " # of ORANGE is " << l << endl;
            count++;
            minTicket = min(minTicket, i + j + k + l);
          }
        }
      }
    }
  }
  cout << "Total combinations is " << count << "." << endl;
  cout << "Minimum number of tickets to print is " << minTicket << "." << endl;
}
