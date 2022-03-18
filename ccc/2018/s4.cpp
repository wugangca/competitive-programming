/*
For a root node with weight n, it can have 2, 3, 4, ..., n subtrees:
f(1) = 1
f(n) = f(n/2) + f(n/3) + f(n/4) +....+ f(n/n)

That is:
f(n) = sum( f(n/k) ), where k = 2, 3, 4, ..., n

There are repeated computations in the above recursion.
e.g.
    k =   2      3      4      5      6      7     8     ....   15
f(15) = f(7) + f(5) + f(3) + f(3) + f(2) + f(2) + f(1) + ......+f(1)
      = f(7) + f(5) + 2*f(3) + 2*f(2) + 8*f(1)

We only need to compute f(7), f(5), f(3), f(2), f(1);

To compute the count of each f:
1. Calculate the remainder: r = n % k (e.g. 15 % 4 = 3).
   This is the spaces we can allocate for d (d = n / k)
2. Divide r by d: extra = r / d;
   This is the extra count we can assign
3. Since we have at least one originally (n/k), count = extra + 1;

We can also record previously calculated numbers with a hashtable,
so that we don't calculate them again.
For example, when we compute f(7), the recursion will eventually calculate f(2).
We can store f(2) during the calculation of f(7).
Then later when we calculate f(2) in the f(15)'s loop (k=6,7),  we can use
previously computed f(2) directly.
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, long long> hashMap;

long long f(int n) {
  if (hashMap.find(n) != hashMap.end()) {
    return hashMap[n];
  }

  long long ans = 0;
  int k = 2;
  while (k <= n) {
    int d = n / k;
    int r = n % k;
    int count = r / d + 1;
    ans += count * f(d);
    k += count;
  }
  hashMap[n] = ans;
  return ans;
}

long long f1(int n) {
  if (hashMap.find(n) != hashMap.end()) {
    return hashMap[n];
  }

  long long ans = 0;
  for (int i = 2; i <=n; i++) {
    ans+=f1(n/i);
  }
  hashMap[n] = ans;
  return ans;
}
int main() {
  int n;
  cin >> n;
  hashMap[1] = 1;
  hashMap[2] = 1;
  hashMap[3] = 2;

  cout << f1(n);
  return 0;
}