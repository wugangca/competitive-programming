#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Students {
    int pass;
    int total;

    friend bool operator<(const Students& s1, const Students& s2) {
      double delta1 =
          (double)(s1.pass + 1) / (s1.total + 1) - (double)s1.pass / s1.total;
      double delta2 =
          (double)(s2.pass + 1) / (s2.total + 1) - (double)s2.pass / s2.total;
      return delta1 < delta2;
    }
  };

  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<Students> pq;
    double sum = 0;
    for (vector<int> c : classes) {
      if (c[0] < c[1]) {
        pq.push({c[0], c[1]});
      }
      sum += (double)c[0] / c[1];
    }

    if (pq.size() == 0) {
      return 1;
    }

    while (extraStudents > 0) {
      Students s = pq.top();
      pq.pop();
      sum += (double)(s.pass + 1) / (s.total + 1) - (double)s.pass / s.total;
      s.pass++;
      s.total++;
      pq.push(s);
      extraStudents--;
    }

    return sum / classes.size();
  }
};