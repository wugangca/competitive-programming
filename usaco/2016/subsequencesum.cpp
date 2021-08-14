#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> start(7, -1);
  vector<int> end(7, -1);

  long long prefix = 0;
  
  int id = 0;
  for (int i = 0; i < n; i++) {
    cin >> id;
    prefix += id;
    int mod = prefix % 7;

    if (start[mod] < 0) {
        start[mod] = i;
    }
    end[mod] = i;
  }

  int ans = 0;
  for (int i = 0; i < 7; i++) {
      ans = max(ans, end[i] - start[i]);
  }

  cout << ans << endl;
   
  }