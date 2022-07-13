#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool rule(pair<int, string> a, pair<int, string> b)
{
  return a.first < b.first;
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, string>> member;

  for (int i = 0; i < n; i++)
  {
    int age;
    string name;
    cin >> age >> name;
    member.push_back(pair(age, name));
  }

  stable_sort(member.begin(), member.end(), rule);

  for (int i = 0; i < n; i++)
  {
    cout << member[i].first << ' ' << member[i].second << '\n';
  }
}
