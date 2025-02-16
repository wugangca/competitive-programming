#include <iostream>
#include <string>

using namespace std;

int countSubstring(const string &s, const string &sub) {
  int count = 0;

  size_t found = s.find(sub);

  while (found != string::npos) {
    count++;
    found = s.find(sub, found + sub.length());
  }
  return count;
}

int main() {
  string s;
  getline(cin, s);
  int happyCount = countSubstring(s, ":-)");
  int sadCount = countSubstring(s, ":-(");

  if (happyCount == 0 && sadCount == 0) {
    cout << "none";
  } else if (happyCount > sadCount) {
    cout << "happy";
  } else if (happyCount < sadCount) {
    cout << "sad";
  } else {
    cout << "unsure";
  }

  return 0;
}
