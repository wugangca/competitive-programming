#include <bits/stdc++.h>
using namespace std;
string generateTheString(int n) {
  string s(n, 'a');
  if (n % 2 == 0) {
    s[n - 1] = 'b';
  }
  return s;
}