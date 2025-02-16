#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> adj, noun;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    adj.push_back(s);
  }

  for (int i = 0; i < m; i++) {
    cin >> s;
    noun.push_back(s);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << adj[i] << " as " << noun[j] << endl;
    }
  }
}
