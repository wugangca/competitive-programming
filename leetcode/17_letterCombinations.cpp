#include <bits/stdc++.h>
using namespace std;
void letterCombinationsRec(vector<string>& v, const string& digits, int index,
                           const string& prev, const vector<string>& letters) {
  if (digits.length() == 0) {
    return;
  }
  int i = digits[index] - '0';
  if (digits.length() - 1 == index) {
    for (char ch : letters[i]) {
      v.push_back(prev + ch);
    }
    return;
  }

  for (char ch : letters[i]) {
    letterCombinationsRec(v, digits, index + 1, prev + ch, letters);
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> letters{"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> v;
  string prev = "";
  letterCombinationsRec(v, digits, 0, prev, letters);
  return v;
}