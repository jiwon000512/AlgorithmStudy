#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;
vector<int> memo;

int main()
{
    cin >> n >> k;
    v.resize(n);
    memo.resize(k + 1);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    memo[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= k; j++)
        {
            memo[j] = memo[j] + memo[j - v[i]];
        }
    }

    cout << memo[k] << '\n';
}