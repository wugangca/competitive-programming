#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main() {
  while (true) {
    string prefix;
    getline(cin, prefix);
    if (prefix == "0") {
      break;
    }
    stack<string> st;
    string num = "";
    for (size_t i = 0; i < prefix.length(); i += 2) {
      num = string(1, prefix[i]);
      if (st.empty() || num == "+" || num == "-") {
        st.push(num);
        continue;
      }

      while (!st.empty()) {
        string top = st.top();
        if (top == "+" || top == "-") {
          st.push(num);
          break;
        }
        st.pop();
        string op = st.top();
        st.pop();
        num = top + " " + num + " " + op;
      }
    }
    cout << num << endl;
  }
}