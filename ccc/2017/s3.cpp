/*
1. length range is [1, 2000].
2. The sum of two lengths is in a range of [2, 4000]
3. Have a counting array to count each length
4. Have a counting array to count each sum
5. Go through each sum, find the sum that has the maximum count
   and how many sums that have this maximum count.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(2001, 0);
  vector<int> sum(4001, 0);
  int maxL = 0;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    l[j]++;
    maxL = max(maxL, j);
  }

  for (int i = 1; i <= maxL; i++) {
    sum[2 * i] += l[i] / 2;
    for (int j = i + 1; j <= maxL; j++) {
      sum[i + j] += min(l[i], l[j]);
    }
  }

  int maxSum = 0;
  int maxCount = 0;
  for (int i = 2; i <= 4000; i++) {
    if (sum[i] > maxSum) {
      maxSum = sum[i];
      maxCount = 1;
    } else if (sum[i] == maxSum) {
      maxCount++;
    }
  }

  cout << maxSum << " " << maxCount;

  return 0;
}