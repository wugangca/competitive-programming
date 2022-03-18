#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches) {
  queue<int> q;
  for (int student : students) {
    q.push(student);
  }
  int curSand = 0;
  int noeat = 0;
  while (!q.empty()) {
    int student = q.front();
    if (student == sandwiches[curSand]) {
      q.pop();
      curSand++;
      noeat = 0;
    } else {
      noeat++;
      if (noeat == q.size()) {
        break;
      }
      q.pop();
      q.push(student);
    }
  }
  return q.size();
}