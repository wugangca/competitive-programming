#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int totalL = 0;
  int totalM = 0;
  int totalS = 0;
  for (char ch : s) {
    if (ch == 'L') {
      totalL++;
    } else if (ch == 'M') {
      totalM++;
    } else {
      totalS++;
    }
  }

  int totalMinL = 0, totalSinL = 0, totalLinM = 0, totalSinM = 0, totalLinS = 0,
      totalMinS = 0;

  for (int i = 0; i < totalL; i++) {
    if (s[i] == 'M') {
      totalMinL++;
    } else if (s[i] == 'S') {
      totalSinL++;
    }
  }

  for (int i = totalL; i < totalL + totalM; i++) {
    if (s[i] == 'L') {
      totalLinM++;
    } else if (s[i] == 'S') {
      totalSinM++;
    }
  }

  for (int i = totalL + totalM; i < n; i++) {
    if (s[i] == 'L') {
      totalLinS++;
    } else if (s[i] == 'M') {
      totalMinS++;
    }
  }

  int ans = 0;

  if (totalLinM < totalMinL) {
    ans += totalLinM;
    totalMinL -= totalLinM;
    totalLinM = 0;
  } else {
    ans += totalMinL;
    totalLinM -= totalMinL;
    totalMinL = 0;
  }

  if (totalLinS < totalSinL) {
    ans += totalLinS;
    totalSinL -= totalLinS;
    totalLinS = 0;
  } else {
    ans += totalSinL;
    totalLinS -= totalSinL;
    totalSinL = 0;
  }

  if (totalMinS < totalSinM) {
    ans += totalMinS;
    totalSinM -= totalMinS;
    totalMinS = 0;
  } else {
    ans += totalSinM;
    totalMinS -= totalSinM;
    totalSinM = 0;
  }

  ans += (totalMinL + totalSinL + totalLinM + totalSinM + totalLinS + totalMinS)/3*2;
  cout << ans;
}
