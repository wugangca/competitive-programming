#include <iostream>
#include <vector>
using namespace std;
/*
N points,
C slots [0, C-1]

Total possibilities = N \choose 3 = N*(N-1)*(N-2)/(1*2*3) =
We minus "bad" ones from this possibilities.

For each slot, find the farthest slot that less than C/2
For slot i, the other side is i + C/2 if C is odd or i + (C/2) - 1 if C is even.
If C is even, i + C/2 is the opposite across the diameter. We handle the
diameter case later

In the given example, if C  = 10, C/2-1=4
This makes
0 -> 4
1 -> 5
2 -> 6
3 -> 7
4 -> 8
5 -> 9
6 -> 0
7 -> 1
8 -> 2
9 -> 3
The formula is j = (i + k)%C, where k = C/2 or C/2 - 1

1. three points in the slot i:
  if count[i] >= 3, then count[i] \choose 3 =
count[i]*(counti]-1)*(count[i]-2)/(1*2*3)

2. two points in the slot i, count[i] \choose 2, multiply the number of points
   from i+1 to j
   Use prefix sum to calculate the number of points from i+1 to j
   Consider the wrap around 0 case.

3. one point in slot i, any two points in other slots: i+1 to j

For diameter case when C is even

for each i, opposite is j = (i + C/2)

slot i choose 2 points, slot j choose 1 point
slot i choose 1 point, slot j choose 2 points
slot i choose 1 point, slot j choose 1 point, any point from the rest

count[i] \choose 2 * count[j] +
count[j] \choose 2 * count[i] +
count[i] * count[j] * (C - count[i] - count[j])

Go through the example:
8 10
0 2 5 5 6 9 0 0
total = 8 \choose 3 = 8*7*6/6 = 56
k = 10 / 2 - 1 = 4

0 -> 4:  1+3=4
1 -> 5:
2 -> 6:  3
3 -> 7:
4 -> 8:
5 -> 9: 2 + 2 = 4
6 -> 0: 4 choose 2 = 6
7 -> 1:
8 -> 2:
9 -> 3: 6
23

diameter: 2*3*3 + 3 + 3*2 = 18+3+6=27
*/

int main() {
  long long n, c;
  cin >> n >> c;

  vector<long long> count(c, 0);

  for (long long i = 0; i < n; i++) {
    long long p;
    cin >> p;
    count[p]++;
  }

  vector<long long> prefix(c, 0);

  prefix[0] = count[0];

  for (long long i = 1; i < c; i++) {
    prefix[i] = prefix[i - 1] + count[i];
  }

  long long total = n * (n - 1) / 2 * (n - 2) / 3;

  long long bad = 0;
  long long k = c / 2;
  if (c % 2 == 0) {
    k--;
  }

  for (long long i = 0; i < c; i++) {
    if (count[i] == 0)
      continue;
    long long j = (i + k) % c;
    if (count[i] >= 3) {
      bad += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
    }
    long long points = 0;
    if (j > i) {
      points = prefix[j] - prefix[i]; // points between i+1 to j
    } else {
      // i > j
      // e.g. i =6 j =0
      // i = 7 j= 1
      points += prefix[c - 1] - prefix[i]; // i + 1 to last c-1
      points += prefix[j];                 // 0 to j
    }
    if (count[i] >= 2) {
      bad += count[i] * (count[i] - 1) / 2 * points;
    }
    if (points >= 2) {
      bad += points * (points - 1) / 2 * count[i];
    }
  }

  if (c % 2 == 0) {
    k = c / 2;
    for (long long i = 0; i < k; i++) {
      long long j = i + k;
      if (count[i] == 0 || count[j] == 0) {
        continue;
      }

      long long points = n - count[i] - count[j];
      bad += count[i] * count[j] * points +
             count[i] * (count[i] - 1) / 2 * count[j] +
             count[j] * (count[j] - 1) / 2 * count[i];
    }
  }

  cout << total - bad;
}