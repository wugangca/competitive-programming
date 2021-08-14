#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> names;
  vector<int> bids;

  for (int i = 0; i < n; i++) {
    string name;
    int bid;
    cin >> name >> bid;
    names.push_back(name);
    bids.push_back(bid);
  }

  int maxBid = 0;
  int maxIdx = 0;

  for (int i = 0; i < n; i++) {
    if (bids[i] > maxBid) {
      maxBid = bids[i];
      maxIdx = i;
    }
  }

  cout << names[maxIdx] << endl;
}