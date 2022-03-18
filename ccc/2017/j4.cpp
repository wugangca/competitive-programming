#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& time) {
  if (time[0] == 0) {
    return (time[1] - time[2] == time[2] - time[3]);
  } else {
    return (time[0] - time[1] == time[1] - time[2]) &&
           (time[1] - time[2] == time[2] - time[3]);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> time(4, 0);
  time[0] = 1;
  time[1] = 2;
  time[2] = 0;
  time[3] = 0;
  int total = 0;

  int q = n / 720;
  int r = n % 720;

  for (int i = 0; i < r; i++) {
    time[3]++;
    if (time[3] == 10) {
      time[3] = 0;
      time[2]++;
      if (time[2] == 6) {
        time[2] = 0;
        time[1] += 1;
        if (time[0] == 1 && time[1] == 3) {
          time[0] = 0;
          time[1] = 1;
        } else if (time[1] == 10) {
          time[1] = 0;
          time[0]++;
        }
      }
    }
    if (check(time)) {
      total++;
    }
  }
  cout << 31 * q + total;

  return 0;
}