#include <bits/stdc++.h>
using namespace std;

int main() {
  int J, A;
  cin >> J >> A;

  vector<char> jerseys(J + 1, ' ');

  for (int i = 1; i <= J; i++) {
    cin >> jerseys[i];
  }

  int total = 0;

  // S, M, L
  for (int i = 0; i < A; i++) {
    char size;
    int j;
    cin >> size >> j;
    if (jerseys[j] == ' ') {
      continue;
    } else if (jerseys[j] <= size) {
      total++;
      jerseys[j] = ' ';
    }
  }
  cout << total;
  return 0;
}