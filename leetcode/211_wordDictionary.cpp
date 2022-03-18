#include <bits/stdc++.h>
using namespace std;
class WordDictionary {
 public:
  struct Node {
    bool isEnd = false;
    map<char, Node*> next;
  };

  Node* root;

  WordDictionary() { root = new Node(); }

  void addWord(string word) {
    Node* cur = root;
    for (char ch : word) {
      if (cur->next.count(ch) == 0) {
        Node* node = new Node();
        cur->next[ch] = node;
      }
      cur = cur->next[ch];
    }
    cur->isEnd = true;
  }

  bool search(string& word, Node* node, int index) {
    if (index == word.length()) {
      return node->isEnd;
    }
    char ch = word[index];
    if (ch == '.') {
      bool result = false;
      for (auto pair : node->next) {
        if (search(word, pair.second, index + 1)) {
          result = true;
          break;
        }
      }
      return result;
    } else {
      if (node->next.count(ch) != 0) {
        return search(word, node->next[ch], index + 1);
      } else {
        return false;
      }
    }
  }

  bool search(string word) { return search(word, root, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
