#include <iostream>
using namespace std;

int calPoint(const string &s)
{
  int point = 0;
  for (size_t i = 0; i < s.length(); i++)
  {
    if (s[i] == 'A')
    {
      point += 4;
    }
    else if (s[i] == 'K')
    {
      point += 3;
    }
    else if (s[i] == 'Q')
    {
      point += 2;
    }
    else if (s[i] == 'J')
    {
      point += 1;
    }
  }
  if (s.length() == 0)
  {
    point += 3;
  }
  else if (s.length() == 1)
  {
    point += 2;
  }
  else if (s.length() == 2)
  {
    point += 1;
  }
  return point;
}
int main()
{
  string cards;
  cin >> cards;

  size_t locationD = cards.find("D");
  string club = cards.substr(1, locationD - 1);

  size_t locationH = cards.find("H");
  string diamond = cards.substr(locationD + 1, locationH - locationD - 1);

  size_t locationS = cards.find("S");
  string heart = cards.substr(locationH + 1, locationS - locationH - 1);
  string spade = cards.substr(locationS + 1);

  cout << "Cards Dealt              Points" << endl;
  cout << "Clubs ";
  for (int i = 0; i < club.length(); i++)
  {
    cout << club[i] << " ";
  }
  cout << calPoint(club) << endl;

  cout << "Diamonds ";
  for (int i = 0; i < diamond.length(); i++)
  {
    cout << diamond[i] << " ";
  }
  cout << calPoint(diamond) << endl;

  cout << "Hearts ";
  for (int i = 0; i < heart.length(); i++)
  {
    cout << heart[i] << " ";
  }
  cout << calPoint(heart) << endl;

  cout << "Spades ";
  for (int i = 0; i < spade.length(); i++)
  {
    cout << spade[i] << " ";
  }
  cout << calPoint(spade) << endl;

  cout << "Total " << calPoint(club) + calPoint(diamond) + calPoint(heart) + calPoint(spade);

      
}