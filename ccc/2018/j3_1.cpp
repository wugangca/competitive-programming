#include <iostream>
using namespace std;

int distance (int c1, int c2, int a[4]) {
  if (c1 > c2) {
    swap(c1, c2);
  }
  int sum = 0;
  for (int i = c1; i < c2; i++) {
     sum += a[i];
  }
  return sum;
}
int main(){
  int a[4];
  cin>>a[0] >> a[1]>>a[2] >> a[3];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int dist = distance(i, j, a);
      cout << dist << " ";
    }
    cout << "\n";
  }
}
