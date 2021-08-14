/* straightforward way to simulate the process.
Calcualte the areas of rectagle and triangle on each fence.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> height(n + 1);
  vector<int> width(n);

  for (int i = 0; i <= n; i++) {
    cin >> height[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> width[i];
  }

  double area = 0;
  for (int i = 0; i < n; i++) {
    int h = min(height[i], height[i + 1]);
    int ht = abs(height[i] - height[i + 1]);
    area += width[i] * (h + ht / 2.0);
  }

  cout << fixed << area << endl;

  return 0;
}
