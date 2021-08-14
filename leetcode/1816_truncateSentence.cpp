#include <bits/stdc++.h>
using namespace std;
string truncateSentence(string s, int k) {
  string result = "";
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      count++;
    }
    if (count == k) {
      return result;
    } else {
      result += s[i];
    }
  }
  return s;
}