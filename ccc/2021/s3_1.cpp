/*
1. For each friend, the moving time is a convex function across the x:

\          /
 \        /
  \______/

The bottom is the range [left, right]

2. Add all friends, the total moving time is till a convex function.
3. For each point, we can calculate its moving time in O(n)
4. We can use binary search on the [left-most point, right-most point] to find
the bottom point
5. the overall time is O(nlog(PointsRange))
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Friend {
  int left;
  int right;
  int w;
};

long long calCost(vector<Friend> &friends, int point) {
  long long cost = 0;
  for (Friend f : friends) {
    if (f.left > point) {
      cost += (f.left - point) * (long long)f.w;
    } else if (f.right < point) {
      cost += (point - f.right) * (long long)f.w;
    }
  }
  return cost;
}

int main() {
  int n;
  cin >> n;

  vector<Friend> friends(n);
  int minP = INT_MAX;
  int maxP = INT_MIN;
  for (int i = 0; i < n; i++) {
    int p, w, d;
    cin >> p >> w >> d;
    friends[i].left = p - d;
    friends[i].right = p + d;
    friends[i].w = w;
    minP = min(minP, p);
    maxP = max(maxP, p);
  }

  int start = minP;
  int end = maxP;
  while (start < end) {
    int mid = (start + end) / 2;
    long long cost = calCost(friends, mid);
    long long cost1 = calCost(friends, mid + 1);
    if (cost > cost1) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  cout << calCost(friends, start) << '\n';
}
