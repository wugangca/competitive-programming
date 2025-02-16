#include <iostream>

using namespace std;

int main() {
  int money[11] = {0,     100,   500,    1000,   5000,   10000,
                   25000, 50000, 100000, 500000, 1000000};

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int index;
    cin >> index;
    money[index] = 0;
  }
  int total = 0;
  for (int i = 1; i <= 10; i++) {
    total += money[i];
  }
  double average = total * 1.0 / (10 - n);
  int offer;
  cin >> offer;

  if (offer > average) {
    cout << "deal";
  } else {
    cout << "no deal";
  }
}
