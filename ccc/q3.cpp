#include <iostream>
using namespace std;
int main() {
  string input = "", output = "";
  cin >> input;
  for (int i = 0; i < input.size(); i += 2) {
    output += input[i];
  }
  for (int i = 1; i < input.size(); i += 2) {
    output += input[i];
  }
  cout << output;
}