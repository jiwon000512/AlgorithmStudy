#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<vector<int>> memo;

int dp(int index, bool plus);

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    memo.resize(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp(i, true));
        ans = max(ans, dp(i, false));
    }

    cout << ans << endl;
    return 0;
}

int dp(int index, bool plus)
{
    if (index == v.size() - 1)
    {
        memo[0][index] = 1;
        return memo[1][index] = 1;
    }

    if (memo[plus][index] != 0)
    {
        return memo[plus][index];
    }

    for (int i = index + 1; i < v.size(); i++)
    {
        if (v[index] == v[i])
            continue;

        bool nextIsPlus = v[index] <= v[i];
        memo[nextIsPlus][index] = max(memo[nextIsPlus][index], dp(i, nextIsPlus) + 1);
        if (nextIsPlus)
        {
            memo[nextIsPlus][index] = max(memo[nextIsPlus][index], dp(i, false) + 1);
        }
    }

    if (memo[plus][index] == 0)
    {
        memo[plus][index] = 1;
    }

    return memo[plus][index];
}
