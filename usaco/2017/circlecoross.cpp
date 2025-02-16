#include <bits/stdc++.h>
using namespace std;

bool cross(pair<int, int>& p1, pair<int, int>& p2) {
  if (p1.first < p2.first) {
    if (p1.second < p2.first) {
      return false;
    }
    if (p2.second < p1.second) {
      return false;
    }
  } else {
    if (p2.second < p1.first) {
      return false;
    }
    if (p1.second < p2.second) {
      return false;
    }
  }
  return true;
}
int main() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
  string s;
  cin >> s;
  vector<pair<int, int>> v(26, {-1, -1});

  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'A';
    if (v[index].first == -1) {
      v[index].first = i;
    } else {
      v[index].second = i;
    }
  }

  int count = 0;
  for (int i = 0; i < 25; i++) {
    for (int j = i + 1; j < 26; j++) {
      if (cross(v[i], v[j])) {
        count++;
      }
    }
  }

  cout << count << endl;
}
