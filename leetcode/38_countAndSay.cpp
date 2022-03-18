#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string countAndSay(int n) {
    if (n < 1) {
      return "";
    }
    if (n == 1) {
      return "1";
    }
    string s = countAndSay(n - 1);
    char cur = ' ';
    int count = 0;
    string output = "";
    for (char c : s) {
      if (cur == ' ') {
        cur = c;
        count = 1;
      } else if (c == cur) {
        count++;
      } else {
        output += to_string(count) + cur;
        cur = c;
        count = 1;
      }
    }
    output += to_string(count) + cur;
    return output;
  }
};