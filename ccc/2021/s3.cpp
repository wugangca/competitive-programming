/*
1. Each friend has a [left, right] range.
2. The optimal solution should be on the border points. 
  2.1 if the optimal solution is between two ranges: |____|   |____|,
       if left friend total weights < right friend total weights, we can move left border.
       similar to the right border
  2.2 if the optiomal solution is inside a range |______|, that friend moving time is 0, remove the friend from the list, case goes back to 2.1.
3. We have 2*n points to check
4. We use prefix sum arrays, leftSum and rightSum, for the points.
5. leftSum[i] is the total moving time for friends left to points[i]
6. rightSum[i] is the total moving time for friends right to points[i]
7. Optimal solution is the min(leftSum[i] + rightSum[i])
8. leftSum[i] = leftSum[i-1] + weights * (points[i] - points[i-1]):
   8.1 leftSum[i-1] is the total time to move to points[i-1]
   8.2 When we check points[i], all the friends left to points[i] need to move extra distance of (points[i] - points[i-1])
   We can forward scan points to construct leftSum array in O(n)
9. rightSum[i] = rightSum[i+1] + weights * (points[i+1] - points[i])
   We can backward scan points to construct rightSum array in O(n)
10. sorting takes O(nlogn). Therefore, the overall time is O(nlongn)
*/

#include <bits/stdc++.h>
using namespace std;

struct Friend {
  int left;
  int right;
  int w;
};

bool compareLeft(const Friend& f1, const Friend& f2) {
  return f1.left < f2.left;
}

bool compareRight(const Friend& f1, const Friend& f2) {
  return f1.right < f2.right;
}

int main() {
  int n;
  cin >> n;

  vector<Friend> friends(n);

  vector<int> points;

  for (int i = 0; i < n; i++) {
    int p, w, d;
    cin >> p >> w >> d;
    friends[i].left = p - d;
    friends[i].right = p + d;
    friends[i].w = w;
    points.push_back(p - d);
    points.push_back(p + d);
  }

  sort(points.begin(), points.end());

  sort(friends.begin(), friends.end(), compareRight);
  vector<long long> leftSum(2 * n, 0);
  int cur = 0;
  int weights = 0;
  int totalPoints = (int)points.size();
  for (int i = 1; i < totalPoints; i++) {
    int p = points[i];
    int distance = points[i] - points[i - 1];
    while (cur < totalPoints && p > friends[cur].right) {
      weights += friends[cur].w;
      cur++;
    }
    leftSum[i] = leftSum[i - 1] + (long long)weights * distance;
  }

  sort(friends.begin(), friends.end(), compareLeft);
  vector<long long> rightSum(2 * n, 0);
  cur = friends.size() - 1;
  weights = 0;
  for (int i = totalPoints - 2; i >= 0; i--) {
    int p = points[i];
    int distance = points[i + 1] - points[i];
    while (cur >= 0 && p < friends[cur].left) {
      weights += friends[cur].w;
      cur--;
    }
    rightSum[i] = rightSum[i + 1] + (long long)weights * distance;
  }

  long long ans = leftSum[0] + rightSum[0];
  for (int i = 0; i < totalPoints; i++) {
    ans = min(ans, leftSum[i] + rightSum[i]);
  }

  cout << ans << endl;

  return 0;
}
