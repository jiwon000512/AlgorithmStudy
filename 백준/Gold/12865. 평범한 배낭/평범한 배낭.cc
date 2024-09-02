#include <iostream>
#include <vector>

using namespace std;

int n, k;
int w[101];
int v[101];
int mem[101][100001];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= w[i])
                mem[i][j] = max(mem[i - 1][j], mem[i - 1][j - w[i]] + v[i]);
            else
                mem[i][j] = mem[i - 1][j];
        }
    }

    cout << mem[n][k] << '\n';
}