#include <bits/stdc++.h>
using namespace std;
class Trie {
 public:
  struct Node {
    bool isEnd;
    char letter;
    Node *next[26];
  };
  Node *root;
  Trie() {
    root = new Node();
    root->isEnd = false;
    root->letter = '\0';
  }

  void insert(string word) {
    Node *cur = root;
    for (char ch : word) {
      int index = ch - 'a';
      if (cur->next[index] != NULL) {
        cur = cur->next[index];
      } else {
        Node *node = new Node();
        node->isEnd = false;
        node->letter = ch;
        cur->next[index] = node;
        cur = node;
      }
    }
    cur->isEnd = true;
  }

  bool search(string word) {
    Node *cur = root;
    for (char ch : word) {
      int index = ch - 'a';
      if (cur->next[index] != NULL) {
        cur = cur->next[index];
      } else {
        return false;
      }
    }
    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    Node *cur = root;
    for (char ch : prefix) {
      int index = ch - 'a';
      if (cur->next[index] != NULL) {
        cur = cur->next[index];
      } else {
        return false;
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie1 {
 public:
  struct Node {
    bool isEnd = false;
    map<char, Node *> next;
  };
  Node *root;
  Trie1() { root = new Node(); }

  void insert(string word) {
    Node *cur = root;
    for (char ch : word) {
      if (cur->next.count(ch) == 0) {
        cur->next[ch] = new Node();
      }
      cur = cur->next[ch];
    }
    cur->isEnd = true;
  }

  bool search(string word) {
    Node *cur = root;
    for (char ch : word) {
      if (cur->next.count(ch) == 0) {
        return false;
      }
      cur = cur->next[ch];
    }
    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    Node *cur = root;
    for (char ch : prefix) {
      if (cur->next.count(ch) == 0) {
        return false;
      }
      cur = cur->next[ch];
    }
    return true;
  }
};