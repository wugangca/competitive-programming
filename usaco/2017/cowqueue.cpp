#include <bits/stdc++.h>

using namespace std;

struct Cow {
  int arrive;
  int duration;
};

bool sortByArrive(Cow &cow1, Cow &cow2) { return cow1.arrive < cow2.arrive; }

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int n;
  cin >> n;

  vector<Cow> cows(n);

  for (int i = 0; i < n; i++) {
    cin >> cows[i].arrive >> cows[i].duration;
  }

  sort(cows.begin(), cows.end(), sortByArrive);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cows[i].arrive > ans) {
      ans = cows[i].arrive;
    }
    ans += cows[i].duration;
  }

  cout << ans;

  return 0;
}