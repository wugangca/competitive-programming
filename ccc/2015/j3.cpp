#include <iostream>
using namespace std;

int main() {
//string original      = "abcdefghijklmnopqrstuvwxyz";
  string closeVowel    = "aaaeeeeiiiiioooooouuuuuuuu";
//string original      = "abcdefghijklmnopqrstuvwxyz";
  string nextConsonant = "acdfeghjiklmnpoqrstvuwxyzz";

  string s;
  cin>>s;
  string output = "";
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
        s[i] == 'o' || s[i] == 'u') {
          output += s[i];
    } else {
      output += s[i];
      int index = s[i] - 'a';
      output += closeVowel[index];
      output += nextConsonant[index];
    }
  }
  cout<<output;
}