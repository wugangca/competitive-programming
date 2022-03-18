#include <bits/stdc++.h>

using namespace std;
int uniqueMorseRepresentations(vector<string>& words) {
  vector<string> code{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};
  set<string> s;
  for (string word : words) {
    string out = "";
    for (char ch : word) {
      out += code[ch - 'a'];
    }
    s.insert(out);
  }
  return s.size();
}