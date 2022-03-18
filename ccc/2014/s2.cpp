#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> names1(n), names2(n);

  for (int i = 0; i < n; i++) {
    cin >> names1[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> names2[i];
  }

  unordered_map<string, string> partner;

  for (int i = 0; i < n; i++) {
    string n1 = names1[i];
    string n2 = names2[i];
    auto itr = partner.find(n1);
    if (itr == partner.end()) {
      partner[n2] = n1;
    } else {
      if (partner[n1] != n2) {
        cout << "bad";
        return 0;
      } else {
        partner.erase(itr);
      }
    }
  }
  if (partner.size() == 0) {
    cout << "good";
  } else {
    cout << "bad";
  }
}