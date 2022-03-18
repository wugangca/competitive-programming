#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
 public:
  stack<pair<int, int> > st;
  StockSpanner() {}

  int next(int price) {
    int count = 0;
    // previous greater
    while (!st.empty()) {
      pair<int, int> p = st.top();
      if (p.first <= price) {
        count += p.second;
        st.pop();
      } else {
        break;
      }
    }
    count++;
    st.push({price, count});
    return count;

    // 75 4
    //  --60 1
    //  -- 70  2
    //   ---- 60 1
    ///  80, 1
    /// 100, 1
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */