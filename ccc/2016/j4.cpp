#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int hour = (s[0] - '0') * 10 + (s[1] - '0');
  int minute = (s[3] - '0') * 10 + (s[4] - '0');

  int time = hour * 60 + minute;
  double total = 120;
  // int slow1 = 420;
  // int slow2 = 600;
  // int slow3 = 15*60 = 900;
  // int slow4 = 19*60= 1140;

  while (total > 0) {
    if ((time >= 420 && time < 600) || (time >= 900 && time < 1140)) {
      total -= 0.5;
    } else {
      total--;
    }
    time++;
  }

  time %= 1440;
  hour = time / 60;
  minute = time % 60;
  if (hour < 10) {
    cout << 0 << hour;
  } else {
    cout << hour;
  }
  cout << ":";
  if (minute < 10) {
    cout << 0 << minute;
  } else {
    cout << minute;
  }
}