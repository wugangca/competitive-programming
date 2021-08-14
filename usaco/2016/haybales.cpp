#include <bits/stdc++.h>

using namespace std;

int main() {
   freopen("haybales.in", "r", stdin);
   freopen("haybales.out", "w", stdout);
   int n, q;
   cin >> n >> q;

   vector<int> v (n);
   for (int i = 0; i< n; i++) {
       cin >> v[i];
   }

   sort(v.begin(), v.end());

   for (int i = 0; i < q; i++) {
       int low, high;
       cin>>low >> high;
       cout <<
       upper_bound(v.begin(), v.end(), high)-
       lower_bound(v.begin(), v.end(), low) << endl;
   }
  
  return 0;
}