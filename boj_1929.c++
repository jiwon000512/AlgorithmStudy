#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    bool* ans = new bool[n+1];

    for(int i=2; i<=n; i++)
    {
        ans[i] = true;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (ans[i])
        {
            for (int j = 2; i * j <= n; j++)
            {
                ans[i * j] = false;
            }
        }
    }
    
    for (int i = m; i <= n; i++)
    {
        if (ans[i])
        {
            cout << i << '\n';
        }
    }
}