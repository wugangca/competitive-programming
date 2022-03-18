#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Node {
    bool isEnd = false;
    map<string, Node *> next;
  };

  void dfs(Node *cur, vector<string> &ans, string &word) {
    if (cur->isEnd) {
      ans.push_back(word);
    }
    int last = word.length();
    for (pair<string, Node *> p : cur->next) {
      word += "/" + p.first;
      dfs(p.second, ans, word);
      word.erase(last);
    }
  }

  void split(string &s, char delimiter, vector<string> &v) {
    string word = "";
    for (char ch : s) {
      if (ch == '/') {
        if (word != "") {
          v.push_back(word);
        }
        word = "";
      } else {
        word += ch;
      }
    }
    if (word != "") {
      v.push_back(word);
    }
  }

  vector<string> removeSubfolders(vector<string> &folder) {
    Node *root = new Node();
    for (string f : folder) {
      Node *cur = root;
      string word = "";
      vector<string> v;
      split(f, '/', v);
      for (string word : v) {
        if (cur->isEnd) {
          break;
        }
        if (cur->next.count(word) == 0) {
          Node *node = new Node();
          cur->next[word] = node;
        }
        cur = cur->next[word];
      }
      cur->isEnd = true;
      cur->next.clear();
    }
    vector<string> ans;
    string word = "";
    dfs(root, ans, word);
    return ans;
  }
};