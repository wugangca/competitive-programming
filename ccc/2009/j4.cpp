#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  int w;
  cin >> w;
  vector<string> message{"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
  int cur = 7;
  int count = 0;
  int start = 0;
  for (int i = 1; i < message.size(); i++) {
    if (cur + message[i].length() + 1 > w) {
      int extra = w - cur;
      int extraspace = extra / count + extra % count;
      string s;
      string extraDots = string(extraspace, '.');
      for (int j = start; j < i; j++) {
        if (j > start) {
          s += ".";
        }
      }

      count = 0;
      cur = 0;
    }
    count++;
    cur = cur + message[i].length() + 1;
  }
}