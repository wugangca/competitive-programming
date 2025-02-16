#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Sequence {
  int ruleNum;
  int pos;
  string newString;
};

vector<vector<string>> rule(4, vector<string>(2, ""));
vector<unordered_set<string>> visited(16, unordered_set<string>());
int steps;
string source, dest;

void getPossibleReplaces(const string &current, int i,
                         vector<Sequence> &possibles) {
  string r0 = rule[i][0];
  string r1 = rule[i][1];
  int len = r0.length();
  int loc = 0;
  loc = current.find(r0, loc);
  while (loc != string::npos) {
    string newString = current.substr(0, loc) + r1 + current.substr(loc + len);
    possibles.push_back({i, loc + 1, newString});
    loc = current.find(r0, loc + 1);
  }
}
void find(const string &current, int step, vector<Sequence> &seq) {
  if (step > steps) {
    return;
  }
  if (step == steps) {
    if (current == dest) {
      for (Sequence s : seq) {
        cout << s.ruleNum << " " << s.pos << " " << s.newString << endl;
      }
      exit(0);
    } else {
      return;
    }
  }
  for (int i = 1; i <= 3; i++) {
    vector<Sequence> possibles;
    getPossibleReplaces(current, i, possibles);
    for (Sequence possible : possibles) {
      string s = possible.newString;
      if (visited[step + 1].count(s) == 0) {
        seq.push_back(possible);
        visited[step + 1].insert(s);
        find(possible.newString, step + 1, seq);
        seq.pop_back();
      }
    }
  }
}

int main() {
  for (int i = 1; i <= 3; i++) {
    cin >> rule[i][0] >> rule[i][1];
  }
  cin >> steps;
  cin >> source >> dest;
  vector<Sequence> seq;
  find(source, 0, seq);
}
