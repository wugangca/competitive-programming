#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;
  vector<int> time(101, -1);
  vector<int> total(101, 0);

  int current = 0;
  for (int i = 0; i < m; i++) {
    char op;
    int x;
    cin >> op >> x;
    if (op == 'R') {
      time[x] = current;
      current++;
    } else if (op == 'W') {
      current += x - 1;
    } else {
      total[x] += current - time[x];
      time[x] = -1;
      current++;
    }
  }
  for (int i = 1; i <= 100; i++) {
    if (time[i] >= 0) {
      cout << i << " -1" << endl;
    } else if (total[i] > 0) {
      cout << i << " " << total[i] << endl;
    }
  }
}