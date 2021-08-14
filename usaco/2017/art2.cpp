#include <bits/stdc++.h>

using namespace std;

struct ColorBracket {
  int color;
  bool open;
};

int main() {
  freopen("art2.in", "r", stdin);
  freopen("art2.out", "w", stdout);
  int n;
  cin >> n;
  const int N = 100001;
  vector<int> start(n + 1, -1);
  vector<int> end(n + 1, -1);
  vector<int> colors(n, 0);
  stack<ColorBracket> st;

  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    colors[i] = color;
    if (start[color] < 0) {
      start[color] = i;
      end[color] = i;
    } else {
      end[color] = i;
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int color = colors[i];
    if (color == 0) {
      if (st.empty()) {
        continue;
      } else {
        ans = -1;
        break;
      }
    }
    if (i == start[color]) {
      st.push({color, true});
    }
    if (i == end[color]) {
      ColorBracket top = st.top();
      if (top.color == color && top.open) {
        ans = max(ans, (int)st.size());
        st.pop();
      } else {
        ans = -1;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}