
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
  int left = 0, right = 0;
  map<char, int> targetCount;
  int targetTotal = t.length();
  for (int i = 0; i < targetTotal; i++) {
    char ch = t[i];
    if (targetCount.find(ch) != targetCount.end()) {
      targetCount[ch]++;
    } else {
      targetCount[ch] = 0;
    }
  }

  map<char, int> count;
  int currentTotal = 0;
  int sourceTotal = s.length();
  int min = sourceTotal + 1;
  string result;
  int num = 0;

  while (right < sourceTotal) {
    while (right < sourceTotal) {
      char ch = s[right];
      if (targetCount.find(ch) == targetCount.end()) {
        right++;
        continue;
      }
      
      if (count.find(ch) != count.end()) {
        if (count[ch] == 0) {
          count[ch]++;
          num++;
          if (num == targetTotal) {
            int size = right - left + 1;
            if (size < min) {
              min = size;
              result = s.substr(left, size);
            }
            break;
          }
        } else {
          count[ch]++;
        }
      }
      right++;
    }

    while (left < right) {
      char ch = s[left];
      if (count.find(ch) != count.end()) {
        if (count[ch] == 1) {
          num--;
          count[ch] = 0;
          left++;
          break;
        } else {
          count[ch]--;
        }
      }
      left++;
    }

    int size = right - left + 2;
    if (size < min) {
      min = size;
      result = s.substr(left - 1, size);
    }

    right++;
  }

  return result;
}



int main() {
  string s = "ab", t = "b";

  cout << minWindow(s, t);
}
