#include <bits/stdc++.h>
using namespace std;

class MapSum {
 public:
  struct Node {
    int val = 0;
    map<char, Node*> next;
  };

  Node* root;

  MapSum() { root = new Node(); }

  void insert(string key, int val) {
    Node* cur = root;
    for (char ch : key) {
      if (cur->next[ch] == nullptr) {
        Node* node = new Node();
        cur->next[ch] = node;
      }
      cur = cur->next[ch];
    }
    cur->val = val;
  }

  void dfs(Node* root, int& total) {
    total += root->val;
    for (pair<char, Node*> p : root->next) {
      dfs(p.second, total);
    }
  }

  int sum(string prefix) {
    Node* cur = root;
    for (char ch : prefix) {
      if (cur->next.count(ch) == 0) {
        return 0;
      }
      cur = cur->next[ch];
    }
    int ans = 0;
    dfs(cur, ans);
    return ans;
  }
};