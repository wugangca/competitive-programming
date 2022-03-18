#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  struct Node {
    bool isEnd = false;
    Node* next[26];
  };

  void findSuggest(Node* cur, vector<string>& suggest, string& word) {
    if (suggest.size() == 3) {
      return;
    }
    if (cur->isEnd) {
      suggest.push_back(word);
    }
    for (int i = 0; i < 26; i++) {
      if (cur->next[i] != nullptr) {
        word.push_back('a' + i);
        findSuggest(cur->next[i], suggest, word);
        word.pop_back();
      }
    }
  }
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    Node* root = new Node();
    for (string product : products) {
      Node* cur = root;
      for (char ch : product) {
        int index = ch - 'a';
        if (cur->next[index] == nullptr) {
          Node* node = new Node();
          cur->next[index] = node;
        }
        cur = cur->next[index];
      }
      cur->isEnd = true;
    }

    Node* cur = root;
    vector<vector<string>> result;
    string word = "";
    for (char ch : searchWord) {
      int index = ch - 'a';
      vector<string> suggest;
      if (cur->next[index] != nullptr) {
        cur = cur->next[index];
        word += ch;
        findSuggest(cur, suggest, word);
        result.push_back(suggest);
      } else {
        break;
      }
    }
    while (result.size() != searchWord.size()) {
      result.push_back(vector<string>());
    }
    return result;
  }
};