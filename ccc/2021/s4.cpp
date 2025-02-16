/*
1. The optimal solution is:
    We take train first on a number of stations (0 if we have direct walk way
1->n, n if no walking route to n). Then, we walk from there to station n.
2. If there is a solution that we walk first from station 1 -> some middle point
i, and then take the train from i, although that takes less time, we have to
wait there for train comes. The solution is no less than taking the train.
3. The walkway routes are fixed.
   We can use dijkstra to calculate the shortest walk time from each station to
station n. (if no route, time is n+2)
4. For each station sequence, the shortest time is: min(train_time(i) +
walk_time(i)) We take train to station i, then walk to station n from i (if no
walking route, the time is >= n+2 ).
5. For each station sequece, we can scan all stations and find the min time.
This takes O(n) time
6. However, in each sequence, we only swap two stations, and we only want the
min time. Therefore, we can use multiset to update the swapped stations only for
each query. That only takes O(logn) time.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Node {
  int num;
  long long dist;
  friend bool operator<(const Node &l, const Node &r) {
    return l.dist > r.dist;
  }
};

void dijkstra(const vector<vector<Node>> &adj, int start,
              vector<long long> &dist) {
  dist[start] = 0;
  priority_queue<Node> pq;
  // Only push the start node
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();
    int u = current.num;
    long long curDist = current.dist;

    if (curDist > dist[u]) {
      // Don’t check neighbors if the popped node distance is already bigger
      continue;
    }
    for (Node next : adj[u]) {
      int v = next.num;
      long long nextDist = dist[u] + next.dist;
      if (nextDist < dist[v]) {
        dist[v] = nextDist;
        pq.push({v, nextDist});
      }
    }
  }
}

int main() {
  int n, w, d;
  cin >> n >> w >> d;

  vector<vector<Node>> walkways(n + 1, vector<Node>());
  for (int i = 0; i < w; i++) {
    int a, b;
    cin >> a >> b;
    walkways[b].push_back({a, 1});
  }

  const int MAX_TIME = n + 2;
  vector<long long> walk(n + 1, MAX_TIME);
  walk[n] = 0;
  dijkstra(walkways, n, walk);

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

  return 0;
}
