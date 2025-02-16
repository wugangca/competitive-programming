#include <iostream>
#include <map>
#include <string>
#include <vector>

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

  map<string, string> partner;

  for (int i = 0; i < n; i++) {
    string n1 = names1[i];
    string n2 = names2[i];
    if (n1 == n2) {
      cout << "bad";
      return 0;
    } else if (partner.find(n2) != partner.end() && partner[n2] != n1) {
      cout << "bad";
      return 0;
    } else {
      partner[n1] = n2;
    }
  }
  cout << "good";
}