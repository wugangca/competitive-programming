#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n;
  cin >> n;

  vector<char> g(n);
  for (int i = 0; i < n; i++) {
   cin >>g[i];
  }

  vector<int> h(n+1, 0);
  vector<int> p(n+1, 0);
  vector<int> s(n+1, 0);

  for (int i = 1; i <= n; i ++) {
    if (g[i - 1] == 'H') {
        p[i] = p[i-1] + 1;
        s[i] = s[i-1] ;
        h[i] = h[i-1] ;
    } else if (g[i-1] == 'P') {
        s[i] = s[i-1] + 1;
        p[i] = p[i-1] ;
        h[i] = h[i-1] ;
    }
    else {
      h[i] = h[i-1] + 1;
      p[i] = p[i-1] ;
      s[i] = s[i-1] ;
    }
  }

  int maxWin = max(p[n], max(s[n], h[n]));
  for (int i = 2; i <=n; i++) {
      int s2h= s[i-1] + (h[n]- h[i-1]);
      int h2s= h[i-1] + (s[n]- s[i-1]);
      int s2p= s[i-1] + (p[n]- p[i-1]);
      int p2s= p[i-1] + (s[n]- s[i-1]);
      int p2h= p[i-1] + (h[n]- h[i-1]);
      int h2p= h[i-1] + (p[n]- p[i-1]);

      maxWin = max(maxWin, max(s2h, max(h2s, max(s2p, max(p2s, max(p2h, h2p))))));
  }

  cout << maxWin;
 


  return 0;
}