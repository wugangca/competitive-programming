#include <bits/stdc++.h>
using namespace std;
string freqAlphabets(string s) {
  string ans = "";
  int i = s.length() - 1;
  while (i >= 0) {
    int index = 0;
    if (s[i] == '#') {
      index = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      i -= 3;
    } else {
      index = s[i] - '0';
      i--;
    }
    char letter = 'a' + index - 1;
    ans = letter + ans;
  }
  return ans;
}