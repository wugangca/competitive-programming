/*

|__________|__________|.........|______|
0          k          2k       ?*k    n-1    

Input:
n, k
a[0], ..., a[n-1]

Observations:
1. We must use  n/k + ((n % k) > 0)  days. This is the minimum days we can use.
2. We can divide input a into several sections, 
   The length of each section is k, with last section make up to the a[n-1] (length <= k)
3. In each day, we can only stop at some point inside each section. 
   That is, each section can have one and only one stop
   At the last day, we stop at a[n-1]
4. When we stop at a[i], its previous stop must be at or after a[i-k], since we can visit max k points each day.
5. Using i-k can pass the grader. However, this number can be improved a little bit.
   let r = n % k. In each section, we must stop at least r distance away from the section start.
   Otherwise, we cannot reach the last point in the minimum days
   Therefore, previous minimum stop is max(i-k, previous_section_start + r)

Solution:
dp[i]: our dynamic programming solution when we stop at a[i]

maxSuffixDP[i]: the maximum dp between i and the next k-station.
               e.g. max(dp[i], dp[i+1], ..., dp[2k-1])

maxSuffixDP_A[i]: the maximum (dp + a) between i and the next k-station.
               e.g. max(dp[i] + maxSuffixA[i+1], 
                        dp[i+1] + maxSuffixA[i+2],
                        ..., 
                        dp[2k-1] + maxSuffixA[2k])

maxPrefixA: the maximum a so far from the current section start (forward)
maxSuffixA: the maximum a so far from the current section end (backwards)
               

Initial case:
for day 0, i.e. a[0] -- a[k-1]
dp[i] = maxPrefixA

For day 1 to last day:
dp[i] = max of :
1. maxSuffixDP[i - k] + maxPrefixA:  The maximum dp from the previous section plus the maximum a of the current section. 
                               This is because maxPrefixA is pretty big, we use it as our best solution

2. maxSuffixDP_A[i - k]: The maximum dp+a from the previous section. 
                         This is best solution for the previous section if we don't consider maxPrefixA.

one soultion of maxSuffixDP_A is:  dp[i] + maxSuffix(i+1)
maxSuffixDP_A[i] is the maximum of all dp[j] + maxSuffixA(j+1) where j = i to the section end.

For each section, we can first compute its dp. 
Then, we compute  maxSuffixDP and maxSuffixDP_A so that they can be used by the next section.
*/

#include <bits/stdc++.h>
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
    int sectionEnd = min(sectionStart + k, n);
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