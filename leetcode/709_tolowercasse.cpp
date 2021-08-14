#include <bits/stdc++.h>

using namespace std;
string toLowerCase(string s) {
  string output = "";
  for (char c : s) {
    output += tolower(c);
  }
  return output;
}