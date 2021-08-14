#include <bits/stdc++.h>
using namespace std;

int main() {
  string flips;
  cin >> flips;

  vector<vector<int> > v{{1, 2}, {3, 4}};
  for (char flip:flips) {
    if (flip == 'H') {
      swap(v[0][0], v[1][0]);
      swap(v[0][1], v[1][1]);
    } else {
      swap(v[0][0], v[0][1]);
      swap(v[1][0], v[1][1]);
    }
  }

  cout << v[0][0] << " " << v[0][1] << endl;
  cout << v[1][0] << " " << v[1][1] << endl;

  return 0;
}