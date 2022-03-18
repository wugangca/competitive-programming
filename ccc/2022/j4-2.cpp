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
  map<string, int> group;
  for (int i = 0; i < g; i++) {
    string name1, name2, name3;
    cin >> name1 >> name2 >> name3;
    group[name1] = i;
    group[name2] = i;
    group[name3] = i;
  }  

  int ans = 0;
  for (int i = 0; i < x; i++) {
    string name1 = same[i][0];
    string name2 = same[i][1];
    if (group[name1] != group[name2]) ans++;
  }

  for (int i = 0; i < y; i++) {
    string name1 = diff[i][0];
    string name2 = diff[i][1];
    if (group[name1] == group[name2]) ans++;
  }

  cout << ans;
}