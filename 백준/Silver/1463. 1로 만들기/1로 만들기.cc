#include <iostream>

using namespace std;

int N;
int dp[1000001];

void Solve()
{
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1] + 1;

        if(i%2 ==0)
        {
            dp[i] = dp[i] < dp[i/2] + 1 ? dp[i] : dp[i/2] + 1;
        }

        if(i%3 == 0)
        {
            dp[i] = dp[i] < dp[i/3] + 1 ? dp[i] : dp[i/3] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    Solve();

    cout << dp[N] << '\n';
}