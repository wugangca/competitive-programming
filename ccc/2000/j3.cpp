#include <iostream>
using namespace std;

int main() {
  int total = 0;
  cin >> total;
  int slot1, slot2, slot3;
  cin >> slot1 >> slot2 >> slot3;

  int round = 0;
  int slot = 1;
  while (total > 0) {
    total--;
    round++;
    if (slot == 1) {
      slot1++;
      if (slot1 == 35) {
        total += 30;
        slot1 = 0;
      }
      slot = 2;
    } else if (slot == 2) {
      slot2++;
      if (slot2 == 100) {
        total += 60;
        slot2 = 0;
      }
      slot = 3;
    } else {
      slot3++;
      if (slot3 == 10) {
        total += 9;
        slot3 = 0;
      }
      slot = 1;
    }
  }
  cout << "Martha plays " << round << " times before going broke." << endl;
}