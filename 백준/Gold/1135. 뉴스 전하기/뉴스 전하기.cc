#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> memo;

int solve(int index)
{
    vector<int> values;
    for(int i=0; i<v[index].size(); i++)
        values.push_back(solve(v[index][i]));

    sort(values.begin(), values.end());
    int weight = v[index].size() - 1;
    for (int i = 0; i < values.size(); i++)
    {
        memo[index] = max(memo[index], values[i] + weight--);
    }
    return memo[index] + 1;
}

int main()
{
    cin >> n;
    v.resize(n);
    memo.resize(n);

    int boss;
    cin >> boss;

    int count = 1;
    while (count < n)
    {
        int index;
        cin >> index;

        v[index].push_back(count);
        count++;
    }

    cout << solve(0) - 1 << '\n';
}