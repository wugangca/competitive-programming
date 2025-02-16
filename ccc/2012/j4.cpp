#include <iostream>
#include <string>
using namespace std;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  string ans = "";

  for (int i = 0; i < s.length(); i++) {
    int shift = (i + 1) * 3 + k;
    int index = s[i] - 'A';
    if (index >= shift) {
      ans += s[i] - shift;
    } else {
      ans += 'Z' - (shift - index - 1);
    }
  }
  cout << ans;
}