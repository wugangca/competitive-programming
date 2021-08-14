#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0;
  int B = 0;

  while (true) {
    int i;
    char X, Y;
    int n;
    cin >> i;

    if (i == 1) {
      cin >> X >> n;
      if (X == 'A') {
        A = n;
      } else {
        B = n;
      }
    } else if (i == 2) {
      cin >> X;
      if (X == 'A') {
        cout << A << endl;
      } else {
        cout << B << endl;
      }
    } else if (i == 3) {
      cin >> X >> Y;
      if (X == 'A') {
        A += B;
      } else {
        B += A;
      }
    }  else if (i == 4) {
      cin >> X >> Y;
      if (X == 'A') {
        A *= B;
      } else {
        B *= A;
      }
    }  else if (i == 5) {
      cin >> X >> Y;
      if (X == 'A') {
        A -= B;
      } else {
        B -= A;
      }
    }  else if (i == 6) {
      cin >> X >> Y;
      if (X == 'A') {
        A /= B;
      } else {
        B /= A;
      }
    } else {
      break;
    }
  }
}