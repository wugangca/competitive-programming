#include <bits/stdc++.h>
using namespace std;
string restoreString(string s, vector<int>& indices) {
  string result = s;

  for (int i = 0; i < s.length(); i++) {
    int index = indices[i];
    result[index] = s[i];
  }
  return result;
}