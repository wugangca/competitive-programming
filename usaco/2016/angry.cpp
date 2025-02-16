#include <bits/stdc++.h>

using namespace std;

bool f(vector<int>& x, int k, int r) {
  int count = 1;
  int first = x[0];
  int d = 2 * r;
  for (int i = 1; i < x.size(); i++) {
    int b = x[i];
    if (b - first > d) {
      k--;
      if (k == 0) {
        return false;
      }
      first = b;
    }
  }

  return true;
}
int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  sort(x.begin(), x.end());

  int low = 0;
  int high = (x[n - 1] - x[0]) / k + 1;

  while (low < high) {
    int mid = (low + high) / 2;
    if (f(x, k, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;
  return 0;
}

void bfs(vector<vector<int>>& adj, int n, int source, vector<bool>& visited) {
  queue<int> q;
  q.push(source);
  visited[source] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u;
    for (int v : adj[u]) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}
void bfsAll(vector<vector<int>>& adj, int n) {
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bfs(adj, n, i, visited);
    }
  }
}
