/*
1. use a counting array to count the frequencies
2. Go through each possible rating (1 ..... 1000)
3. Find the bigest 2 frequencies
4. For each of the biggest 2 freq, find the corresponding largest and smallest
ratings
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> f(1001, 0);

  int maxFrequency = 0;
  int secondMaxFrequency = 0;

  int maxFrequencyReading1 = 0;
  int maxFrequencyReading2 = 10001;

  int secondMaxFrequencyReading1 = 0;
  int secondMaxFrequencyReading2 = 10001;

  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    f[r]++;
  }

  for (int r = 1; r <= 1000; r++) {
    if (f[r] == 0)
      continue;
    if (f[r] > maxFrequency) {
      secondMaxFrequency = maxFrequency;
      secondMaxFrequencyReading1 = maxFrequencyReading1;
      secondMaxFrequencyReading2 = maxFrequencyReading2;

      maxFrequency = f[r];
      maxFrequencyReading1 = r;
      maxFrequencyReading2 = 0;

    } else if (f[r] == maxFrequency) {
      if (r > maxFrequencyReading1) {
        if (maxFrequencyReading2 == 0) {
          maxFrequencyReading2 = maxFrequencyReading1;
        }
        maxFrequencyReading1 = r;
      }
      if (r < maxFrequencyReading2) {
        maxFrequencyReading2 = r;
      }
    } else if (f[r] > secondMaxFrequency) {
      secondMaxFrequency = f[r];
      secondMaxFrequencyReading1 = r;
      secondMaxFrequencyReading2 = 0;
    } else if (f[r] == secondMaxFrequency) {
      if (r > secondMaxFrequencyReading1) {
        if (secondMaxFrequencyReading2 == 0) {
          secondMaxFrequencyReading2 = secondMaxFrequencyReading1;
        }

        secondMaxFrequencyReading1 = r;
      }
      if (r < secondMaxFrequencyReading2) {
        secondMaxFrequencyReading2 = r;
      }
    }
  }

  if (maxFrequencyReading1 > 0 && maxFrequencyReading2 > 0) {
    cout << maxFrequencyReading1 - maxFrequencyReading2;
  } else if (secondMaxFrequencyReading1 > 0 && secondMaxFrequencyReading2 > 0) {
    cout << max(abs(maxFrequencyReading1 - secondMaxFrequencyReading1),
                abs(maxFrequencyReading1 - secondMaxFrequencyReading2));
  } else {
    cout << abs(maxFrequencyReading1 - secondMaxFrequencyReading1);
  }
}