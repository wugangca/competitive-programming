/*

|__________|__________|.........|______|
0          k          2k       ?*k    n-1

Input:
n, k
a[0], ..., a[n-1]

Observations:
1. We must visit all attractions, one by one, and on the last day, we reach
a[n-1]. Therefore, we must use  n/k + ((n % k) > 0)  days. This is the minimum
days we can use.
2. We can divide input a into several sections,
   The length of each section is k, with last section make up to the a[n-1]
(length <= k)
3. In each day, we can only stop at some point inside each section.
   That is, each section can have one and only one stop
   At the last day, we stop at a[n-1]
   If we stop at two points inside one section, we cannot reach the last point,
a[n-1], at the last day.
4. When we stop at a[i], its previous stop must be at or after a[i-k], since we
can visit max k points each day.
5. Using i-k can pass the grader. However, this number can be improved a little
bit. let r = n % k. In each section, we must stop at least r distance away from
the section start. Otherwise, we cannot reach the last point in the minimum days
Therefore, previous minimum stop is: max(i-k, previous_section_start + r)

Solution:
dp[i]: our dynamic programming solution when we stop at a[i]
We process dp[i] day by day, i.e. section by seciton.
On day 0, we process section [0, k)
dp[i] is the maximum array value we see so far, i.e. max(a[0], a[1], ... , a[i])

In general case,
each section we have [start, end), e.g. [0, k), [k, 2k), ...., [?k,
(?+1)k),[(?+1)k, n) for each dp[i], we need to check back from dp[i-k] until the
previous section end.

That is, its previous stop point can be anywhere between i-k and the previous
section end.

for (int j = i-k; j < start; j++) {
   dp[i] = max(dp[i],  dp[j] + max (a[j+1], ..... , a[i]))
}
Notice that  max (a[j+1], ..... , a[i]) can cross two sections:
a[j+1]...a[previousSectionEnd] and a[currsectionstart], ...., a[i]
we can pre-compute these two values.
Let maxSuffixA be: a[j+1]...a[previousSectionEnd]
Let maxPrefixA be: a[currsectionstart]...a[i]

dp[j] + max (a[j+1], ..... , a[i]) is then can be converted to

= dp[j] + max (maxSuffixA, maxPrefixA)
= max(dp[j] + maxSuffixA, dp[j] + maxPrefixA)
= max ( max(dp[j]+maxSuffixA), max(dp[j]) + maxPrefixA )

Explanation:
for dp[i], maxPrefixA is a constant value, it is the max value for the sectio start to i
Thefore, it is possible from 
1. the max(dp[i-k], dp[i-k+1], .. , dp[previousSectionEnd]) + maxPrefixA,
  where max(...) is the maximum dp value from dp[i-k] to the last section end.
2. max (dp[i-k] + max(a[i-k+1], a[i-k+2], ...a[previousSectionEnd])  )
   the maximu  dp + max(a after dp[j])


maxSuffixDP[i]: the maximum dp between i and the section end.
               e.g. max(dp[end-1], dp[end-2], ...,dp[i+1], dp[i])
               Note the value end is not inclusive

maxSuffixA: the maximum value of array a so far from the section end (backwards)
maxSuffixDP_A[i]: the maximum (dp + a) between i and the
current section end.
 e.g. max(dp[end-1],
          dp[end-2] + a[end-1],
          dp[end-3] +max(a[end-1], a[end-2]),
          .....
          dp[i+1] + maxSuffixA[i+2],
          dp[i] + maxSuffixA[i+1]
        )

maxPrefixA: the maximum a so far from the current section start (forward)



Initial case:
for day 0, i.e. a[0] -- a[k-1]
dp[i] = maxPrefixA

For day 1 to last day:
dp[i] = max of :
1. maxSuffixDP[i - k] + maxPrefixA:  The maximum dp from the previous section
plus the maximum a of the current section. This is because maxPrefixA is pretty
big, we use it as our best solution

2. maxSuffixDP_A[i - k]: The maximum dp+a from the previous section.
                         This is best solution for the previous section if we
don't consider maxPrefixA.

one soultion of maxSuffixDP_A is:  dp[i] + maxSuffix(i+1)
maxSuffixDP_A[i] is the maximum of all dp[j] + maxSuffixA(j+1) where j = i to
the section end.

For each section, we can first compute its dp.
Then, we compute  maxSuffixDP and maxSuffixDP_A so that they can be used by the
next section.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int days = n / k + ((n % k) > 0);

  vector<long long> dp(n, 0);
  vector<long long> maxSuffixDP(n, 0);
  vector<long long> maxSuffixDP_A(n, 0);

  for (int day = 0; day < days; day++) {
    long long maxPrefixA = 0;
    int sectionStart = day * k;
    int sectionEnd = min(sectionStart + k, n); // not include the right end
    for (int i = sectionStart; i < sectionEnd; i++) {
      maxPrefixA = max(maxPrefixA, a[i]);
      if (day == 0) {
        dp[i] = maxPrefixA;
      } else {
        dp[i] = max(maxSuffixDP[i - k] + maxPrefixA, maxSuffixDP_A[i - k]);
      }
    }
    if (sectionEnd == n) {
      break;
    }

    long long maxSuffixA = 0;
    for (int i = sectionEnd - 1; i >= sectionStart; i--) {
      maxSuffixDP_A[i] = max(maxSuffixDP_A[i + 1], dp[i] + maxSuffixA);
      maxSuffixA = max(maxSuffixA, a[i]);
      maxSuffixDP[i] = max(maxSuffixDP[i + 1], dp[i]);
    }
  }

  cout << dp[n - 1];
  return 0;
}