/*
1. Use a counting array to count characters in the needle string
2. Use a sliding window (size of needle string length m) to go through the
haystack.
3. Compare the two counting arrays to find a candidate string
4. The candidate string may already visited. Use a hash set to store previous
checked string
5. The value stored in the hash set is the hash value of the string.
6. We can use a rolling hash to calculate the hash value.
7. In order to get full mark, you have to try different numbers.
8. One rolling hash may not enough to avoid hash collision. Try to use 2 or more
with different p, q.
*/

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;
#define TOTAL_CHARACTERS 26
#define HASH_SIZE 1

bool match(const vector<int> &countN, const vector<int> &countH) {
  for (int i = 0; i < TOTAL_CHARACTERS; i++) {
    if (countN[i] != countH[i]) {
      return false;
    }
  }
  return true;
}

long long merge(const vector<long long> &hashes,
                const vector<long long> &factors) {
  long long hash = 0;
  for (int i = 0; i < HASH_SIZE; i++) {
    hash += factors[i] * hashes[i];
  }
  return hash;
}

int main() {
  string needle;
  string haystack;

  cin >> needle;
  cin >> haystack;

  vector<int> countN(TOTAL_CHARACTERS, 0);
  for (char c : needle) {
    countN[c - 'a']++;
  }

  vector<int> countH(TOTAL_CHARACTERS, 0);
  int m = needle.size();

  vector<long long> hashes(HASH_SIZE, 0);
  vector<long long> p{29};
  vector<long long> q{(long long)pow(2, 45) - 1};
  vector<long long> factors{1};
  vector<long long> bases(HASH_SIZE, 1);
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < HASH_SIZE; j++) {
      bases[j] = (bases[j] * p[j]) % q[j];
    }
  }

  for (int i = 0; i < m; i++) {
    int index = haystack[i] - 'a';
    countH[index]++;
    for (int j = 0; j < HASH_SIZE; j++) {
      hashes[j] = (hashes[j] * p[j] + index) % q[j];
    }
  }
  long long hash = merge(hashes, factors);

  int ans = 0;
  int start = 0;
  int end = m - 1;
  int n = (int)haystack.size();

  unordered_set<long long> visited;
  while (true) {
    if (match(countN, countH) && visited.find(hash) == visited.end()) {
      ans++;
      visited.insert(hash);
    }

    if (end >= n - 1) {
      break;
    }
    char remove = haystack[start] - 'a';
    countH[remove]--;
    start++;
    end++;
    char add = haystack[end] - 'a';
    countH[add]++;

    for (int i = 0; i < HASH_SIZE; i++) {
      hashes[i] = ((hashes[i] - remove * bases[i]) * p[i] + add) % q[i];
      if (hashes[i] < 0) {
        hashes[i] += q[i];
      }
    }
    hash = merge(hashes, factors);
  }

  cout << ans << endl;
  return 0;
}