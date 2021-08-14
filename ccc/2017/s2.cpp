#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int middle = n / 2 - (n % 2 == 0);

  int i = middle;
  int j = i + 1;

  while (i >= 0) {
    cout << v[i];
    i--;
    if (j < n) {
      cout << " " << v[j] << " ";
      j++;
    }
  }

  return 0;
}
