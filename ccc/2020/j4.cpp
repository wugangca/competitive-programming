#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> t;
  cin >> s;
  unordered_set<string> cycles;
  cycles.insert(s);
  int len = s.length();

  for (int i = 0; i < len; i++) {
    char ch = s[0];
    s.erase(0, 1);
    s += ch;
    cycles.insert(s);
  }

  for (int i = 0; i <= (int)t.length() - len; i++) {
    string cycle = t.substr(i, len);
    if (cycles.find(cycle) != cycles.end()) {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";

  return 0;
}