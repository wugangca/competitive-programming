#include <bits/stdc++.h>

using namespace std;

struct Cow {
  string name;
  int production;
};

bool sortByArrive(Cow &cow1, Cow &cow2) {
  return cow1.production < cow2.production;
}

int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  int n;
  cin >> n;

  map<string, int> milk;

  milk["Bessie"] = 0;
  milk["Elsie"] = 0;
  milk["Daisy"] = 0;
  milk["Gertie"] = 0;
  milk["Annabelle"] = 0;
  milk["Maggie"] = 0;
  milk["Henrietta"] = 0;

  for (int i = 0; i < n; i++) {
    string name;
    int p;
    cin >> name >> p;
    milk[name] += p;
  }

  vector<Cow> cows;

  for (auto cow : milk) {
    cows.push_back({cow.first, cow.second});
  }
  sort(cows.begin(), cows.end(), sortByArrive);

  int m = cows[0].production;
  int i = 1;
  while (i < 7) {
    if (cows[i].production > m) {
      break;
    }
    i++;
  }
  if (i == 7) {
    cout << "Tie\n";
  } else if (i == 6) {
    cout << cows[i].name << endl;
  } else if (cows[i].production == cows[i + 1].production) {
    cout << "Tie\n";
  } else {
    cout << cows[i].name << endl;
  }

  return 0;
}