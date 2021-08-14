#include <bits/stdc++.h>

using namespace std;

int main() {
  
 // freopen("milktemp.in", "r", stdin);
 // freopen("milktemp.out", "w", stdout);
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  
  const int MAX_TEMP = 1000000001;


  int delta1 = y-x;
  int delta2 = z-y;

  int maxTemp = 0;
  vector<pair<int, int>> ranges(n);
  vector<int> temps;
  
  for (int i = 0; i < n; i++) {
    int low, high;
    cin >> low >> high;
    ranges[i].first = low;
    ranges[i].second = high;
    temps.push_back(low);
    temps.push_back(high);
  }
  
  sort(temps.begin(), temps.end());

  map<int, int> indexes;
  for (int i = 0; i < temps.size(); i++) {
      indexes[temps[i]] = i + 1;
  }
  
  vector<int> milk(2*n + 2, 0);
  for (pair<int, int> range: ranges) {
    milk[0] += x;
    milk[indexes[range.first]] += delta1;
    milk[indexes[range.second] +1] += delta2;
  }

  int maxMilk = milk[0];
  int m = milk[0];
  for (int i = 1; i < milk.size(); i++) {
      m += milk[i];
      if (m > maxMilk) {
          maxMilk = m;
      }
  }

  cout << maxMilk << endl;
  return 0;
}