#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> t;
  cin >> s;
  int len = s.length();
  if (t.find(s) != string::npos) {
    cout << "yes";
    return 0;
  }
  for (int i = 0; i < len; i++) {
    char ch = s[0];
    s.erase(0, 1);
    s += ch;
    if (t.find(s) != string::npos) {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";
  return 0;
}