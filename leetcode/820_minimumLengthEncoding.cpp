#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Node {
    // bool isEnd = false;
    map<char, Node *> next;
  };

  int minimumLengthEncoding(vector<string> &words) {
    Node *root = new Node();
    map<Node *, int> endNodes;
    for (string word : words) {
      Node *cur = root;
      for (int i = word.length() - 1; i >= 0; i--) {
        char ch = word[i];
        if (cur->next[ch] == nullptr) {
          Node *node = new Node();
          cur->next[ch] = node;
        }
        cur = cur->next[ch];
      }
      // cur->isEnd = true;
      endNodes[cur] = word.length();
    }
    int count = 0;
    for (auto p : endNodes) {
      if (p.first->next.size() == 0) {
        count += p.second + 1;
      }
    }
    return count;
  }
};