#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Log {
    string id;
    string words;
    int index;
  };

  static bool comp(Log &log1, Log &log2) {
    if (!isdigit(log1.words[0]) && !isdigit(log2.words[0])) {
      if (log1.words == log2.words) {
        return log1.id <= log2.id;
      } else {
        return log1.words <= log2.words;
      }
    } else if (!isdigit(log1.words[0]) && isdigit(log2.words[0])) {
      return true;
    } else if (isdigit(log1.words[0]) && !isdigit(log2.words[0])) {
      return false;
    } else {
      return log1.index < log2.index;
    }
  }

  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<Log> v;
    for (int i = 0; i < logs.size(); i++) {
      string log = logs[i];
      int index = log.find(' ');
      string id = log.substr(0, index);
      string words = log.substr(index + 1);
      v.push_back({id, words, i});
    }
    sort(v.begin(), v.end(), comp);
    vector<string> ans;
    for (Log l : v) {
      ans.push_back(l.id + " " + l.words);
    }
    return ans;
  }
};