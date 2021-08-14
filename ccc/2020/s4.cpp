/*
*/

#include <bits/stdc++.h>
using namespace std;

int minSwap(const string &s, int n, int a, int b) {
  int prev = 0;
  for (int i = 0; i < a; i++) {
    if (s[i] == 'A') {
      prev++;
    }
  }
  int maxA = prev;
  int startIndex = 0;
  for (int i = a; i < n; i++) {
    int offset = 0;
    if (s[startIndex] == 'A') {
      offset--;
    }
    if (s[i] == 'A') {
      offset++;
    }

    int current = prev + offset;
    if (current > maxA) {
      maxA = current;
    }
    prev = current;
    startIndex++;
  }

  for (int i = 0; i < a - 1; i++) {
    int offset = 0;
    if (s[startIndex] == 'A') {
      offset--;
    }
    if (s[i] == 'A') {
      offset++;
    }

    int current = prev + offset;
    if (current > maxA) {
      maxA = current;
    }
    prev = current;
    startIndex++;
  }

  return a - maxA;
}

int countInRegion(const vector<int> &prefix, int start, int end, int n) {
  if (start == 0) {
    return prefix[end];
  } else if (start < end) {
    return prefix[end] - prefix[start - 1];
  } else {
    return prefix[n - 1] - prefix[start - 1] + prefix[end];
  }
}
int minSwapABC(const vector<int> &prefixA, const vector<int> &prefixB,
               const vector<int> &prefixC, int n, int countA, int countB,
               int countC) {
  int ans = n;
  for (int startA = 0; startA < n; startA++) {
    int endA = (startA + countA - 1) % n;
    int startB = (endA + 1) % n;
    int endB = (startB + countB - 1) % n;
    int startC = (endB + 1) % n;
    int endC = (startC + countC - 1) % n;

    int countAInB = countInRegion(prefixA, startB, endB, n);
    int countAInC = countInRegion(prefixA, startC, endC, n);
    int countBInA = countInRegion(prefixB, startA, endA, n);
    int countBInC = countInRegion(prefixB, startC, endC, n);
    int countCInA = countInRegion(prefixC, startA, endA, n);
    int countCInB = countInRegion(prefixC, startB, endB, n);

    //(B,C in A) + (A,C in B) - min ( B in A, A in B)
    int switchAB = countBInA + countCInA + countAInB + countCInB -
                   min(countBInA, countAInB);
    int switchAC = countBInA + countCInA + countAInC + countBInC -
                   min(countCInA, countAInC);
    int switchBC = countAInB + countCInB + countAInC + countBInC -
                   min(countCInB, countBInC);
    ans = min(ans, min(switchAB, min(switchAC, switchBC)));
  }
  return ans;
}

int minSwapACB(const vector<int> &prefixA, const vector<int> &prefixB,
               const vector<int> &prefixC, int n, int countA, int countB,
               int countC) {
  int ans = n;
  for (int startA = 0; startA < n; startA++) {
    int endA = (startA + countA - 1) % n;
    int startC = (endA + 1) % n;
    int endC = (startC + countC - 1) % n;
    int startB = (endC + 1) % n;
    int endB = (startB + countB - 1) % n;

    int countAInB = countInRegion(prefixA, startB, endB, n);
    int countAInC = countInRegion(prefixA, startC, endC, n);
    int countBInA = countInRegion(prefixB, startA, endA, n);
    int countBInC = countInRegion(prefixB, startC, endC, n);
    int countCInA = countInRegion(prefixC, startA, endA, n);
    int countCInB = countInRegion(prefixC, startB, endB, n);

    //(B,C in A) + (A,C in B) - min ( B in A, A in B)
    int switchAB = countBInA + countCInA + countAInB + countCInB -
                   min(countBInA, countAInB);
    int switchAC = countBInA + countCInA + countAInC + countBInC -
                   min(countCInA, countAInC);
    int switchBC = countAInB + countCInB + countAInC + countBInC -
                   min(countCInB, countBInC);
    ans = min(ans, min(switchAB, min(switchAC, switchBC)));
  }
  return ans;
}

int main() {
  string s;
  cin >> s;

  vector<int> count(3, 0);
  int n = s.length();
  for (int i = 0; i < n; i++) {
    count[s[i] - 'A']++;
  }

  vector<int> prefixA(n, 0);
  vector<int> prefixB(n, 0);
  vector<int> prefixC(n, 0);

  if (s[0] == 'A') {
    prefixA[0]++;
  } else if (s[0] == 'B') {
    prefixB[0]++;
  } else {
    prefixC[0]++;
  }
  for (int i = 1; i < n; i++) {
    prefixA[i] = prefixA[i - 1];
    prefixB[i] = prefixB[i - 1];
    prefixC[i] = prefixC[i - 1];

    if (s[i] == 'A') {
      prefixA[i]++;
    } else if (s[i] == 'B') {
      prefixB[i]++;
    } else {
      prefixC[i]++;
    }
  }

  cout << min(minSwapABC(prefixA, prefixB, prefixC, n, count[0], count[1],
                         count[2]),
              minSwapACB(prefixA, prefixB, prefixC, n, count[0], count[1],
                         count[2]))
       << endl;
 
  return 0;
}
