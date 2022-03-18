#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& diff, int end) {
  int len = end + 1;
  for (size_t i = end + 1; i < diff.size(); i++) {
    int j = i % len;
    if (diff[i] != diff[j]) {
      return false;
    }
  }

  return true;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<int> diff(n - 1);
    int pre;
    cin >> pre;
    for (int i = 0; i < n - 1; i++) {
      int cur;
      cin >> cur;
      diff[i] = cur - pre;
      pre = cur;
    }

    int len = n - 1;
    for (int i = 0; i < n - 1; i++) {
      if (check(diff, i)) {
        len = i + 1;
        break;
      }
    }
    cout << len << endl;
  }
}