#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> count(26, 0);

  for (char c : s1) {
    count[c - 'a']++;
  }
  int countStar = 0;
  for (char c : s2) {
    if (c == '*') {
      countStar++;
    } else {
      count[c - 'a']--;
    }
  }
  bool isAnagram = true;
  for (int i = 0; i < 26; i++) {
    if (count[i] < 0) {
      isAnagram = false;
      break;
    } else if (count[i] > 0) {
      countStar -= count[i];
      if (countStar < 0) {
        isAnagram = false;
        break;
      }
    }
  }

  if (isAnagram) {
    cout << "A" << endl;
  } else {
    cout << "N" << endl;
  }

  return 0;
}