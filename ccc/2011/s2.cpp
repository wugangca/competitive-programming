#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string ans(n, ' ');
  for (int i = 0; i < n; i++) {
    cin >> ans[i];
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    char correct;
    cin >> correct;
    if (ans[i] == correct) {
      total++;
    }
  }

  cout << total;
}