/*
Suppose the number array is a[n]
1. Each query provides a range [x, y], the gcd of the numbers in this range
(a[x], ... , a[y]) must be z
2. If a[i] is in the range [x, y], a[i] must be a multiple of z
3. For a number a[i], it can exist in multiple queries
4. a[i] must be a multiple of those z numbers. without loss of generality, a[i]
can be lcm of these z numbers
5. Therefore, for each a[i], its value should be the lcm of all gcds (z values)
it resides in. e.g. if we have gcds of 2, 3, 8. the value should be 24, which is
lcm(2,3,8)
6. If we use a traditional way to record z values for each a[i],
  e.g. for a range [x, y], add its z value to all a[x] ... a[y],
  you will get TLE as it takes too much time to loop from x to y on each query
  But it is a good start
7. Notice Z value is 1<=Z<=16



*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct Query {
  int x, y, z;
};

int lcm(int p, int q) { return p * q / __gcd(p, q); }

void checkQuery(const vector<Query> &queries, const vector<int> &ans, int n) {
  for (Query q : queries) {
    int gcd = ans[q.x];
    for (int i = q.x + 1; i <= q.y; i++) {
      gcd = __gcd(gcd, ans[i]);
    }
    if (gcd != q.z) {
      cout << "Impossible" << endl;
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}

// bool compareQuery(const Query q1, const Query q2) {
//   if (q1.y < q2.y) {
//     return true;
//   } else if (q1.y == q2.y) {
//     return q1.x > q2.x;
//   } else {
//     return false;
//   }
// }
// void check(const vector<Query>& queries, const vector<int>& ans, int n) {
//   sort(queries.begin(), queries.end(), compareQuery);
//   for (Query q : queries) {
//     int gcd = ans[q.x];
//     for (int i = q.x + 1; i <= q.y; i++) {
//       gcd = __gcd(gcd, ans[i]);
//     }
//     if (gcd != q.z) {
//       cout << "Impossible" << endl;
//       return;
//     }
//   }

//   for (int i = 1; i <= n; i++) {
//     cout << ans[i] << " ";
//   }
// }

int main() {
  int n, m;
  cin >> n >> m;

  vector<Query> queries(m);

  // gcd: 1-16
  vector<vector<int>> diff(17, vector<int>(n + 2, 0));

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    queries[i] = {x, y, z};
    diff[z][x]++;
    diff[z][y + 1]--;
  }

  vector<int> ans(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int lcm_value = 1;
    for (int j = 2; j <= 16; j++) {
      diff[j][i] += diff[j][i - 1];
      if (diff[j][i] > 0) {
        lcm_value = lcm(lcm_value, j);
      }
    }
    ans[i] = lcm_value;
  }

  checkQuery(queries, ans, n);
  return 0;
}
