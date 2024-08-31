#include <iostream>

using namespace std;

#define MAX_SIZE 1001

int memo[MAX_SIZE][MAX_SIZE];

char a[MAX_SIZE];
char b[MAX_SIZE];

int max(int a, int b)
{
    return a > b ? a : b;
}

int lcsM(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    else if (a[m - 1] == b[n - 1])
    {
        return memo[m][n] = lcsM(m - 1, n - 1) + 1;
    }
    else
    {
        return memo[m][n] = max(lcsM(m - 1, n), lcsM(m, n - 1));
    }
}

int main()
{
    cin >> a;
    cin >> b;

    int asize = 0;
    int bsize = 0;

    while (a[asize])
        asize++;
    while (b[bsize])
        bsize++;
    for (int m = 0; m <= asize; m++)
    {
        for (int n = 0; n <= bsize; n++)
        {
            if (m == 0 || n == 0)
            {
                memo[m][n] = 0;
            }
            else
            {
                memo[m][n] = -1;
            }
        }
    }

    cout << lcsM(asize, bsize) << '\n';
}