#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  int n;
  string s;
  cin >> n >> s;

  int k = 1;
  while (k < n) {
    set<string> setS;
    bool unique = true;
    for (int i = 0; i <= n - k; i++) {
      string sub = s.substr(i, k);
      if (setS.count(sub) == 0) {
        setS.insert(sub);
      } else {
        unique = false;
        break;
      }
    }
    if (unique) {
      break;
    }
    k++;
  }
  cout << k;

  return 0;
}