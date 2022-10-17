#include <iostream>

using namespace std;

#define MaxSize 30
int dp[MaxSize + 1][MaxSize + 1];

int bridge(int n, int m);

int main()
{
    int numCases;
    cin >> numCases;

    for(int i=1; i<31; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 0; i < numCases; i++)
    {
        int n, m;

        cin >> n >> m;

        cout << bridge(n,m) << '\n';
    }
}

int bridge(int n, int m)
{
    if(dp[n][m] != 0)
    {
        return dp[n][m];
    }
    
    if(n == 1)
    {
        return m;
    }
    
    int tmpM = m;

    while(tmpM-- > n-1)
    {
        dp[n][m] += bridge(n-1, tmpM);
    }

    return dp[n][m];
}