#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool digitBefore = false;

  for (char ch : s) {
    if (ch >= 'A' && ch <= 'Z') {
      if (digitBefore) {
        cout << "\n";
      }
      cout << ch;
      digitBefore = false;
    } else if (ch == '+') {
      cout << " tighten ";
    } else if (ch == '-') {
      cout << " loosen ";
    } else {
      digitBefore = true;
      cout << ch;
    }
  }
}