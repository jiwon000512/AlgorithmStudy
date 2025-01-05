#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000

using namespace std;

// 비용, 고객
vector<pair<int, int>> v;
vector<int> memo;

int c, n;

int dp(int people)
{
    if (people <= 0)
    {
        return memo[0] = 0;
    }

    if (memo[people] != MAX)
    {
        return memo[people];
    }

    for (int i = 0; i < v.size(); i++)
    {
        int money = v[i].first;
        int addPeople = v[i].second;

        int before = dp(people - addPeople);
        if (people == c)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j].second >= addPeople)
                {
                    money = v[j].first;
                    break;
                }
            }
        }
        memo[people] = min(memo[people], before + money);
    }

    return memo[people];
}

int main()
{
    cin >> c >> n;
    memo.resize(c + 1);
    fill(memo.begin(), memo.end(), MAX);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    cout << dp(c) << '\n';
}