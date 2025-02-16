#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  int countT = 0;
  int countS = 0;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (char ch : s) {
      if (ch == 'T' || ch == 't') {
        countT++;
      } else if (ch == 'S' || ch == 's') {
        countS++;
      }
    }
  }
  if (countT > countS) {
    cout << "English";
  } else {
    cout << "French";
  }
}