#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> list;
  while (true) {
    string s;
    cin >> s;
    if (s == "SCHOOL") {
      break;
    }
    list.push_back(s);
  }

  for (int i = list.size() - 1; i >= 1; i-=2) {
    if (list[i] == "R") {
      cout << "Turn LEFT onto " << list[i - 1] << " street." << endl;
    } else {
      cout << "Turn RIGHT onto " << list[i - 1] << " street." << endl;
    }
  }

   if (list[0] == "R") {
      cout << "Turn LEFT into your HOME."<< endl;
    } else {
      cout << "Turn RIGHT into your HOME."<< endl;
    }
}