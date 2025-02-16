/*
1. Generate all prime numbers on the input data range
2. 2-sum problem on a sorted array
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

bool isPrime(int n, const vector<int> &primes) {
  for (size_t i = 0; i < primes.size(); i++) {
    if (n % primes[i] == 0)
      return false;
    if (primes[i] > sqrt(n))
      return true;
  }
  return true;
}

vector<int> getPrimeNumbers(int maxNum) {
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i <= maxNum; i++) {
    if (isPrime(i, primes)) {
      primes.push_back(i);
    }
  }
  return primes;
}

void findPrimes(int n, const vector<int> &primes, int &a, int &b) {
  int start = 0;
  int end = primes.size() - 1;

  while (start < end) {
    int sum = primes[start] + primes[end];
    if (sum == n) {
      a = primes[start];
      b = primes[end];
      return;
    } else if (sum < n) {
      start++;
    } else {
      end--;
    }
  }
}

int main() {
  int total;
  cin >> total;

  vector<int> v;

  for (int i = 0; i < total; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  int maxNum = *max_element(v.begin(), v.end());

  vector<int> primes = getPrimeNumbers(maxNum * 2);

  for (size_t i = 0; i < v.size(); i++) {
    int a = 0;
    int b = 0;
    findPrimes(v[i] * 2, primes, a, b);
    cout << a << " " << b << endl;
  }
  return 1;
}
