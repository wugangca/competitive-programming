#include <bits/stdc++.h>
using namespace std;

void pour(int& fromM, int fromC, int& ToM, int ToC) {
  if (fromM + ToM > ToC) {
    int p = (ToC - ToM);
    ToM = ToC;
    fromM -= p;
  } else {
    ToM += fromM;
    fromM = 0;
  }
}
int main() {
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
  int c1, m1, c2, m2, c3, m3;
  cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

  for (int i = 0; i < 100; i++) {
    if (i % 3 == 0) {
      pour(m1, c1, m2, c2);
    } else if (i % 3 == 1) {
      pour(m2, c2, m3, c3);
    } else {
      pour(m3, c3, m1, c1);
    }
  }
  cout << m1 << endl << m2 << endl << m3 << endl;

  return 0;
}