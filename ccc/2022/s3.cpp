#include <iostream>
#include <vector>
using namespace std;
/*
Each single number is a good sample. k >= n
for 2, we can have another max n-1 good samples: 1 2 1 2 1 2....1 2
for 3, we can have another max n-2 good samples: 1 2 3 1 2 3....1 2 3
for 4, we can have anotehr max n-3 good samples: 1 2 3 4 1 2 3 4...... 1 2 3 4

To cover k good samples, first find the max number we will use.

maxNum = 1: we have n good examples
maxNum = 2: we another have n-1 good examples
.....abort

we add n + (n-1) + (n-2)+... until we can cover k good examples.

Suppose maxNum is 6

we have [ n + (n-1) + (n-2) + (n-3) + (n-4) ] + g = k
          1     2       3       4       5

where g is > 0 and g <= n-5
if g==0, we can use exactly 5 numbers. 1 2 3 4 5 1 2 3 4 5......
if g == n-5, we use exactly 6 numbers. 1 2 3 4 5 6 1 2 3 4 5 6....

first we construct the array with the maxNum using the above pattern

 1 2 3 4 5 6 1 2 3 4 5 6 1 2 3 4 5 6.....
 Note this will create  [ n + (n-1) + (n-2) + (n-3) + (n-4) ] + (n-5) g
examples. However, we only need extra g examples. Therefore, we make the first g
examples that has the pattern 1 2 3 4 5 6

index   0 1 2 3 4 5 6 7 8 9 10 11
number  1 2 3 4 5 6 1 2 3 4 5  6 ...
g                 1 2 3 4 5 6  7....

the ending index will be maxNum + g - 2
e.g. if we want 3 extra good examples, the ending index is 6 + 3 - 2 = 7
We will keep the numbers <= ending index
For numbers after ending index, we need to make them pattern with (maxNum-1)
distinct numbers

we can use the numbers start from the ending index, backward calculate
(maxNum-1) numbers i.e. (ending index) - (maxNum - 1) + 1 = maxNum + g -2 -
maxNum + 1+ 1 = g

that is start from index g and end at index (maxNum + g -  2)
There are maxNum -1 distinct numbers.
We repeate this pattern from the index after (maxNum + g -  2) until the end

Note k can be as big as 10^18. Therfore, k must be long long

*/
void print(const vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << v[i];
  }
  cout << endl;
}
int main() {
  int n, m;
  long long k;
  cin >> n >> m >> k;

  if (k < n) {
    cout << -1;
    return 0;
  }
  vector<int> v(n, 1);
  if (k == n) {
    print(v);
    return 0;
  }

  long long good = k;
  int total = n;

  int maxNum = 1;
  while (maxNum <= m) {
    if (good - total <= 0) {
      break;
    }
    good -= total;
    total--;
    maxNum++;
  }

  if (maxNum > m) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    v[i] = i % maxNum + 1;
  }

  int last = good + maxNum - 2;

  for (int i = last + 1; i < n; i++) {
    v[i] = v[good];
    good++;
  }
  print(v);
}