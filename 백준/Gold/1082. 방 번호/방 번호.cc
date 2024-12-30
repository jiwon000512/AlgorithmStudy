#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define MAX 51

using namespace std;

int n, m;
vector<pair<int, int>> p;
string dp[MAX];

bool comparePair(pair<int, int> a, pair<int,int> b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

bool compareString(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}

string solve(int money)
{
    if (money < p[0].first)
        return "0";

    if (dp[money].empty() == false)
        return dp[money];

    if (money == p[0].first)
        return dp[money] = to_string(p[0].second);

    for (int i = 0; i < p.size(); i++)
    {
        if (money < p[i].first)
            continue;

        string x = solve(money - p[i].first);
        if (x == "0")
        {
            x = to_string(p[i].second); 
        }
        else
        {
            string tmp = x.append(to_string(p[i].second));
            x = tmp;
            sort(x.begin(), x.end(), greater<char>());
        }

        if(dp[money].empty())
        {
            dp[money] = x;
        }
        else
        {
            dp[money] = max(dp[money], x, compareString);
        }
    }
    return dp[money];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int money;
        cin >> money;
        p.push_back({money, i});
    }
    sort(p.begin(), p.end(), comparePair);
    cin >> m;
    solve(m);
    cout << dp[m] << '\n';
}