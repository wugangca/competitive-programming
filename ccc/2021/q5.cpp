#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<>());
    ans = max(ans, stoi(s));
  }
  cout << ans;
}