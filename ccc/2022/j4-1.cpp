#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, g;
  int total = 0;
  unordered_map<string, int> students;

  cin >> x;
  vector<pair<int, int>> same;
  string name1, name2;
  for (int i = 0; i < x; i++) {
    cin >> name1 >> name2;
    int index1, index2;
    if (students.count(name1) == 0) {
      students[name1] = total;
      index1 = total;
      total++;
    } else {
      index1 = students[name1];
    }
    if (students.count(name2) == 0) {
      students[name2] = total;
      index2 = total;
      total++;
    } else {
      index2 = students[name2];
    }
    same.push_back({index1, index2});
  }

  cin >> y;
  vector<pair<int, int>> diff;
  for (int i = 0; i < y; i++) {
    cin >> name1 >> name2;
    int index1, index2;
    if (students.count(name1) == 0) {
      students[name1] = total;
      index1 = total;
      total++;
    } else {
      index1 = students[name1];
    }
    if (students.count(name2) == 0) {
      students[name2] = total;
      index2 = total;
      total++;
    } else {
      index2 = students[name2];
    }
    diff.push_back({index1, index2});
  }

  vector<int> group(total, -1);
  cin >> g;

  for (int i = 0; i < g; i++) {
    string name1, name2, name3;
    cin >> name1 >> name2 >> name3;
    int index1 = -1, index2 = -1, index3 = -1;
    if (students.count(name1) == 1) {
      index1 = students[name1];
      group[index1] = i;
    }
    if (students.count(name2) == 1) {
      index2 = students[name2];
      group[index2] = i;
    }
    if (students.count(name3) == 1) {
      index3 = students[name3];
      group[index3] = i;
    }

    int ans = 0;
    for (pair<int, int> p : same) {
      int index1 = p.first;
      int index2 = p.second;
      if (group[index1] != group[index2]) ans++;
    }
    for (pair<int, int> p : diff) {
      int index1 = p.first;
      int index2 = p.second;
      if (group[index1] == group[index2]) ans++;
    }

    cout << ans;
  }