#include <bits/stdc++.h>
using namespace std;

int main() {
  string input, output = "";
  char remove;
  cin >> input;
  cin >> remove;
  for (char c : input) {
    if (c != remove) {
      output += c;
    }
  }
  cout << output;
}