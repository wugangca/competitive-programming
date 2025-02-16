#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> m;
  m["Bessie"] = 0;

  vector<string> years = {"Ox",      "Tiger", "Rabbit", "Dragon",
                          "Snake",   "Horse", "Goat",   "Monkey",
                          "Rooster", "Dog",   "Pig",    "Rat"};
  int current = 0;

  for (int i = 0; i < n; i++) {
    vector<string> v(8);
    for (int i = 0; i < 8; i++) {
      cin >> v[i];
    }
    string p = v[3];
    string year = v[4];
    int age = m[v[7]];

    if (p == "previous") {
      int diff = 0;
      while (years[current] != year) {
        current--;
        if (current < 0) {
          current = 11;
        }
        diff++;
      }
      age -= diff;
      m[v[0]] = age;
    } else {
      int diff = 0;
      while (years[current] != year) {
        current++;
        if (current == 12) {
          current = 0;
        }
        diff++;
      }
      age += diff;
      m[v[0]] = age;
    }
    if (v[0] == "Elsie") {
      cout << abs(age);
      break;
    }
  }
}