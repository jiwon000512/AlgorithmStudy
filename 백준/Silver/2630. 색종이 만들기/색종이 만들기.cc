#include <iostream>

using namespace std;

int N, ans0, ans1;
int arr[128][128];

void Solve(int x, int y, int s)
{
    int paper = arr[x][y];
    for (int i = x; i < x + s; i++)
    {
        for (int j = y; j < y + s; j++)
        {
            if (paper != arr[i][j])
            {
                int ns = s / 2;
                Solve(x, y, ns);
                Solve(x + ns, y, ns);
                Solve(x, y + ns, ns);
                Solve(x + ns, y + ns, ns);
                return;
            }
        }
    }

    if (paper == 1)
    {
        ans1++;
    }
    else if (paper == 0)
    {
        ans0++;
    }
}

int main()
{
    cin >> N;

    int in;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solve(0, 0, N);

    cout << ans0 << '\n';
    cout << ans1 << '\n';
}