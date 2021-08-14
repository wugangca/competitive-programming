#include <iostream>

using namespace std;

int main() {
  string input;
  string turn = "";
  while (true) {
    cin >> input;
    if (input == "99999") {
      break;
    }
    int direction = (input[0] - '0') + (input[1] - '0');
    if (direction % 2 == 1) {
      turn = "left";
    } else if (direction != 0) {
      turn = "right";
    }

    cout << turn << " " << input.substr(2) << endl;
  }
}