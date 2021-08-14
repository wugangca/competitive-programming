#include <bits/stdc++.h>

using namespace std;

bool f(vector<int>& d, int k, int max_t) {
    priority_queue<int, vector<int>, greater<int> > q;
    for (int n:d) {
        if (q.size() != k) {
            q.push(n);
        } else {
            int t = q.top();
            if (t>max_t) {
                return false;
            }
            q.pop();
            q.push(t+n);
        }
    }
    while (!q.empty()) {
        int t = q.top();
        if (t > max_t) {
            return false;
        }
        q.pop();
    }
    return true;
}

int main() {
   freopen("cowdance.in", "r", stdin);
   freopen("cowdance.out", "w", stdout);
   int n, max_t;
   cin >> n >> max_t;

   vector<int> d (n);
   for (int i = 0; i< n; i++) {
       cin >> d[i];
   }

   int low = 1;
   int high = n;

   while (low < high) {
       int mid = (low + high) / 2;
       if (f(d, mid, max_t)) {
           high = mid;
       } else {
           low = mid+1;
       }
   }
   cout << low << endl;

   
  
  
  return 0;
}