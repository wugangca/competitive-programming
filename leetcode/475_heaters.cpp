#include <bits/stdc++.h>
using namespace std;

bool f(vector<int>& houses, vector<int>& heaters, int radius) {
  int i = 0;
  int j = 0;

  while (i < houses.size() && j < heaters.size()) {
    if (heaters[j] - radius <= houses[i] && houses[i] <= heaters[j] + radius) {
      i++;
    } else {
      j++;
    }
  }
  if (i < houses.size()) {
    return false;
  } else {
    return true;
  }
}
int findRadius(vector<int>& houses, vector<int>& heaters) {
  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());

  int low = 0;

  int min_house = houses[0];
  int max_house = houses[houses.size() - 1];
  int max_heater = heaters[heaters.size() - 1];

  int high = max(abs(max_heater - min_house), abs(max_heater - max_house));

  while (low < high) {
    int mid = (low + high) / 2;
    if (f(houses, heaters, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}