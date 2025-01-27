#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int memo[201][201];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        memo[i][1] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        memo[1][i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 1000000000;
        }
    }

    cout << memo[n][k] << endl;
}