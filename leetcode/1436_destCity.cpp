#include <bits/stdc++.h>
using namespace std;
string destCity(vector<vector<string>>& paths) {
  map<string, string> m;
  for (vector<string> path : paths) {
    m[path[0]] = path[1];
  }
  for (vector<string> path : paths) {
    if (m.count(path[1]) == 0) {
      return path[1];
    }
  }
  return "";
}