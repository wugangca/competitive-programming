#include <iostream>
#include <string>
using namespace std;

bool checksilly(const string &s1, const string &s2, char silly, char correct,
                char &quiet) {
  string s = s1;
  for (size_t i = 0; i < s1.length(); i++) {
    if (s[i] == silly) {
      s[i] = correct;
    }
  }
  quiet = '-';
  size_t j = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (j >= s2.length()) {
      if (quiet == '-') {
        quiet = s[i];
        continue;
      } else if (quiet != s[i]) {
        return false;
      }
      continue;
    }
    if (s[i] != s2[j]) {
      if (quiet == '-') {
        quiet = s[i];
        continue;
      } else if (quiet != s[i]) {
        return false;
      } else {
        continue;
      }
    }
    j++;
  }
  return true;
}

bool checkQuiet(const string &s1, const string &s2, char &silly, char &correct,
                char quiet) {
  string s = "";
  for (size_t i = 0; i < s1.length(); i++) {
    if (s1[i] != quiet) {
      s += s1[i];
    }
  }
  if (s.length() != s2.length()) {
    return false;
  }
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] != s2[i]) {
      silly = s[i];
      correct = s2[i];
      return true;
    }
  }
  return false;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  char quiet = '-';
  char silly = ' ';
  char correct = ' ';
  for (size_t i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      if (checksilly(s1, s2, s1[i], s2[i], quiet)) {
        cout << s1[i] << " " << s2[i] << endl << quiet << endl;
      } else {
        checkQuiet(s1, s2, silly, correct, s1[i]);
        cout << silly << " " << correct << endl << s1[i] << endl;
      }
      break;
    }
  }
}