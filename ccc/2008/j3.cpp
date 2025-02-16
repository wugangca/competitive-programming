#include <iostream>
#include <string>

using namespace std;

int main() {
  string text;
  getline(cin, text);

  int curX = 0;
  int curY = 0;
  int total = 0;
  for (int i = 0; i < text.length(); i++) {
    char ch = text[i];
    int x = 0;
    int y = 0;

    if (ch >= 'A' && ch <= 'Z') {
      int index = ch - 'A';
      x = index / 6;
      y = index % 6;
    } else if (ch == ' ') {
      x = 4;
      y = 2;
    } else if (ch == '-') {
      x = 4;
      y = 3;
    } else if (ch == '.') {
      x = 4;
      y = 4;
    }
    total += abs(x - curX) + abs(y - curY);
    curX = x;
    curY = y;
  }

  total += abs(4 - curX) + abs(5 - curY);
  cout << total;
}