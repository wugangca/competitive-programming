#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> roman;

  roman['I'] = 1;
  roman['V'] = 5;
  roman['X'] = 10;
  roman['L'] = 50;
  roman['C'] = 100;
  roman['D'] = 500;
  roman['M'] = 1000;

  int total = 0;
  int n = s.length();
  for (int i = 0; i < n; i += 2) {
    int a = s[i] - '0';
    int r = roman[s[i + 1]];
    int num = a * r;
    if (i + 3 < n && r < roman[s[i + 3]]) {
      num = -num;
    }
    total += num;
  }
  cout << total;
}