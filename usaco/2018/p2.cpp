#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Store {
  int capacity;
  int price;
};

bool storeSort(const Store &lhs, const Store &rhs) {
  return lhs.price > rhs.price;
}

int main() {
  int n, m, r;

  ifstream myfile;
  myfile.open("rental.in");
  myfile >> n >> m >> r;

  vector<int> cows;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cows.push_back(num);
  }

  vector<Store> stores;
  for (int i = 0; i < m; i++) {
    Store s;
    cin >> s.capacity >> s.price;
    stores.push_back(s);
  }

  vector<int> rents;
  for (int i = 0; i < r; i++) {
    int num;
    cin >> num;
    rents.push_back(num);
  }

  sort(cows.begin(), cows.end(), greater<int>());
  sort(rents.begin(), rents.end(), greater<int>());
  sort(stores.begin(), stores.end(), storeSort);

  int milkCowIndex = 0;
  int rentCowIndex = cows.size() - 1;
  int rentIndex = 0;
  int storeIndex = 0;

  long long totalMoney = 0;

  while (milkCowIndex <= rentCowIndex) {
    long long rentMoney = 0;
    long long milkMoney = 0;
    if (rentIndex < rents.size()) {
      rentMoney = rents[rentIndex];
    }
    int k = storeIndex;
    int milk = cows[milkCowIndex];

    while (k < stores.size() && milk >= stores[k].capacity) {
      milkMoney += stores[k].capacity * stores[k].price;
      milk -= stores[k].capacity;
      k++;
    }
    if (k < stores.size() && milk > 0) {
      milkMoney += milk * stores[k].price;
    }

    if (rentMoney == 0 && milkMoney == 0) {
      break;
    } else if (rentMoney > milkMoney) {
      // rent cow j (current least milk cow)
      totalMoney += rentMoney;
      rentIndex++;
      rentCowIndex--;
    } else {
      // sell cow i's milk
      for (int i = storeIndex; i < k; i++) {
        stores[i].capacity = 0;
      }
      stores[k].capacity -= milk;
      totalMoney += milkMoney;
      storeIndex = k;
      milkCowIndex++;
    }
  }

  ofstream outf;
  outf.open("rental.out");
  outf << totalMoney;
  outf.close();

  return 0;
}