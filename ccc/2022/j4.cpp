#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, g;

  cin >> x;
  vector<vector<string>> same(x, vector<string>(2, ""));
  for (int i = 0; i < x; i++) {
    cin >> same[i][0] >> same[i][1];
  }

  cin >> y;
  vector<vector<string>> diff(y, vector<string>(2, ""));
  for (int i = 0; i < y; i++) {
    cin >> diff[i][0] >> diff[i][1];
  }

  cin >> g;
  vector<unordered_set<string>> group(g);
  for (int i = 0; i < g; i++) {
    string name1, name2, name3;
    cin >> name1 >> name2 >> name3;
    group[i].insert(name1);
    group[i].insert(name2);
    group[i].insert(name3);
  }

  int ans = 0;
  for (int i = 0; i < x; i++) {
    string name1 = same[i][0];
    string name2 = same[i][1];
    for (int j = 0; j < g; j++) {
      if ((group[j].count(name1) == 1 && group[j].count(name2) == 0) ||
          (group[j].count(name2) == 1 && group[j].count(name1) == 0)) {
        ans++;
        break;
      }
    }
  }

  for (int i = 0; i < y; i++) {
    string name1 = diff[i][0];
    string name2 = diff[i][1];
    for (int j = 0; j < g; j++) {
      if ((group[j].count(name1) == 1 && group[j].count(name2) == 1)) {
        ans++;
        break;
      }
    }
  }

  cout << ans;
}