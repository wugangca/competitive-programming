#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int offset = n / 2;
  int count = 0;
  for (int i = 0; i < offset; i++) {
    if (v[i] == v[i + offset]) {
      count += 2;
    }
  }
  cout << count;
}