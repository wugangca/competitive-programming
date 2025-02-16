#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, c;
  cin >> t >> c;
  vector<int> v(c);

  for (int i = 0; i < c; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int count = 0;
  int sum = 0;
  for (int i = 0; i < c; i++) {
    sum += v[i];
    if (sum > t) {
      break;
    }
    count++;
  }

  cout << count;
}