#include <bits/stdc++.h>
using namespace std;

bool isDistinctYear(int year) {
  int counter[10];
  for (int i = 0; i < 10; i++) {
    counter[i] = 0;
  }
  string s = to_string(year);
  for (size_t i = 0; i < s.length(); i++) {
    int index = s[i] - '0';
    if (counter[index] > 0)
      return false;
    else
      counter[index]++;
  }
  return true;
}

int main() {
  int year;
  cin >> year;
  year++;
  while (!isDistinctYear(year)) {
    year++;
  }
  cout << year;
}