#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Node {
    bool isEnd = false;
    map<char, Node *> next;
  };
  void constructTrie(vector<string> &dictionary, Node *root) {
    for (string word : dictionary) {
      Node *cur = root;
      for (char ch : word) {
        if (cur->next[ch] == nullptr) {
          Node *node = new Node();
          cur->next[ch] = node;
        }
        cur = cur->next[ch];
      }
      cur->isEnd = true;
    }
  }
  void match(Node *root, string &word, string &result) {
    result = "";
    Node *cur = root;
    bool found = false;
    for (char ch : word) {
      if (cur->isEnd) {
        found = true;
        break;
      }
      if (cur->next.count(ch) == 0) {
        break;
      }
      result += ch;
      cur = cur->next[ch];
    }
    if (!found) {
      result = word;
    }
  }
  string replaceWords(vector<string> &dictionary, string sentence) {
    Node *root = new Node();
    constructTrie(dictionary, root);

    int start = 0;
    int pos = sentence.find(' ', start);
    string ans = "";

    while (pos != string::npos) {
      string word = sentence.substr(start, pos - start);
      string result = "";
      match(root, word, result);
      if (ans.length() > 0) {
        ans += " ";
      }
      ans += result;
      start = pos + 1;
      pos = sentence.find(' ', start);
    }
    if (start < sentence.length()) {
      string word = sentence.substr(start);
      string result = "";
      match(root, word, result);
      if (ans.length() > 0) {
        ans += " ";
      }
      ans += result;
    }

    return ans;
  }
};