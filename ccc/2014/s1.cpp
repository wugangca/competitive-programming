#include <iostream>
#include <list>

using namespace std;

int main() {
  int k, m;
  cin >> k >> m;

  list<int> friends;

  for (int i = 1; i <= k; i++) {
    friends.push_back(i);
  }

  for (int i = 0; i < m; i++) {
    int r;
    cin >> r;
    int num = 1;
    auto itr = friends.begin();
    while (itr != friends.end()) {
      if (num % r == 0) {
        itr = friends.erase(itr);
      } else {
        itr++;
      }
      num++;
    }
  }

  for (int f : friends) {
    cout << f << endl;
  }
}