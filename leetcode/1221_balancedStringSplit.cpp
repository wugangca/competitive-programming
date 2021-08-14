#include <bits/stdc++.h>
using namespace std;
int balancedStringSplit(string s) {
  int total = 0;

  int countL = 0;
  int countR = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'L') {
      countL++;
    } else {
      countR++;
    }
    if (countL == countR) {
      total++;
    }
  }

  return total;
}