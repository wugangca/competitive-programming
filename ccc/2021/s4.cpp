/* 
1. The optimal solution is: 
    We take train first on a number of stations (0 if we have direct walk way 1->n, n if no walking route to n).
    Then, we walk from there to station n.
2. If there is a solution that we walk first from station 1 -> some middle point i, and then take the train from i,
   although that takes less time, we have to wait there for train comes. The solution is no less than taking the train.
3. The walkway routes are fixed. 
   We can use dijkstra to calculate the shortest walk time from each station to station n. (if no route, time is n+2)
4. For each station sequence, the shortest time is: min(train_time(i) + walk_time(i))
   We take train to station i, then walk to station n from i (if no walking route, the time is >= n+2 ).
5. For each station sequece, we can scan all stations and find the min time. This takes O(n) time
6. However, in each sequence, we only swap two stations, and we only want the min time. 
   Therefore, we can use multiset to update the swapped stations only for each query. That only takes O(logn) time.
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int num, distance;
  friend bool operator<(const Node& l, const Node& r) {
    return l.distance > r.distance;
  }
};

void dijkstra(const vector<vector<int>>& adj, vector<int>& dist, int n) {
  priority_queue<Node> q;
  q.push({n, 0});
  dist[n] = 0;
  vector<bool> visited(n + 1, false);

  while (!q.empty()) {
    Node node = q.top();
    q.pop();
    int num = node.num;
    if (visited[num]) {
      continue;
    }
    visited[num] = true;
    for (int v : adj[num]) {
      if (visited[v]) continue;
      dist[v] = min(dist[v], dist[node.num] + 1);
      q.push({v, dist[v]});
    }
  }
}

int main() {
  int n, w, d;
  cin >> n >> w >> d;

  vector<vector<int>> walkways(n + 1, vector<int>());
  for (int i = 0; i < w; i++) {
    int a, b;
    cin >> a >> b;
    walkways[b].push_back(a);
  }

  const int MAX_TIME = n + 2;
  vector<int> walk(n + 1, MAX_TIME);
  walk[n] = 0;
  dijkstra(walkways, walk, n);

  vector<int> stations(n + 1);

  multiset<int> times;
  for (int i = 1; i <= n; i++) {
    cin >> stations[i];
    times.insert(i - 1 + walk[stations[i]]);
  }

  for (int i = 0; i < d; i++) {
    int x, y;
    cin >> x >> y;

    times.erase(times.find(x - 1 + walk[stations[x]]));
    times.erase(times.find(y - 1 + walk[stations[y]]));

    times.insert(y - 1 + walk[stations[x]]);
    times.insert(x - 1 + walk[stations[y]]);

    swap(stations[x], stations[y]);

    cout << *(times.begin()) << endl;
  }

  // The following code takes O(n) time to scan
  // for (int i = 0; i < d; i++) {
  //   int x, y;
  //   cin >> x >> y;
  //   swap(stations[x], stations[y]);
  //   int ans = INT_MAX;
  //   int time = 0;
  //   for (size_t i = 1; i < stations.size(); i++) {
  //     int station = stations[i];
  //     ans = min(ans, time + walk[station]);
  //     if (station == n) {
  //       break;
  //     }
  //     time++;
  //   }
  //   cout << ans << endl;
  // }

  return 0;
}
