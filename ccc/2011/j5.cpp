#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<vector<int>> &adj) {
  int total = 1;
  for (int x : adj[n]) {
    total *= 1 + f(x, adj);
  }
  return total;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);

  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }
  cout << f(n, adj);
}