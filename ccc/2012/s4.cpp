/*
Bit operation
1. at most 7 numbers: 1- 7
2. Use long long (8 bytes) to represent all states
 1 ->      10    2
 2 ->     100    4
 3 ->    1000    8
 4 ->   10000   16
 5 ->  100000   32
 6 -> 1000000   64
 7 -> 1000000   128

 If two numbers are stack together, set the bit in the corresponding group
In an extreme case, all 7 numbers stack into one byte:
 0 0 0 0 0 0 11111110

 Use BFS to record all possible moves

*/

#include <unordered_set>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
  long long coins;
  int step;
};

void setBit(long long *coins, int index, int num) {
  ((unsigned char *)coins)[index] |= (1 << num);
}

void resetBit(long long *coins, int index, int num) {
  ((unsigned char *)coins)[index] &= ~(1 << num);
}

int getLowBit(long long *coins, int index) {
  unsigned char coin = ((unsigned char *)coins)[index];
  unsigned char n = 2;
  int pos = 1;
  while ((coin & n) == 0 && pos < 8) {
    n <<= 1;
    pos++;
  }
  return pos;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }

    long long coins = 0;
    long long sorted = 0;

    for (int i = 0; i < n; i++) {
      int coin;
      cin >> coin;
      setBit(&coins, i, coin);
      setBit(&sorted, i, i + 1);
    }

    queue<Node> q;
    q.push({coins, 0});

    unordered_set<long long> visited;
    string result = "IMPOSSIBLE";

    while (!q.empty()) {
      Node node = q.front();
      q.pop();

      long long coins = node.coins;
      if (coins == sorted) {
        result = to_string(node.step);
        break;
      }

      visited.insert(coins);
      int step = node.step;

      for (int i = 0; i < n; i++) {
        if (((unsigned char *)(&coins))[i] == 0) {
          continue;
        }
        int currentTop = getLowBit(&coins, i);
        if (i > 0) {
          int prevTop = getLowBit(&coins, i - 1);
          if (((unsigned char *)(&coins))[i - 1] == 0 || prevTop > currentTop) {
            long long newCoins = coins;
            resetBit(&newCoins, i, currentTop);
            setBit(&newCoins, i - 1, currentTop);

            if (visited.find(newCoins) == visited.end()) {
              q.push({newCoins, step + 1});
              visited.insert(newCoins);
            }
          }
        }
        if (i < n - 1) {
          int nextTop = getLowBit(&coins, i + 1);
          if (((unsigned char *)(&coins))[i + 1] == 0 || nextTop > currentTop) {
            long long newCoins = coins;
            resetBit(&newCoins, i, currentTop);
            setBit(&newCoins, i + 1, currentTop);

            if (visited.find(newCoins) == visited.end()) {
              q.push({newCoins, step + 1});
              visited.insert(newCoins);
            }
          }
        }
      }
    }
    cout << result << endl;
  }
}