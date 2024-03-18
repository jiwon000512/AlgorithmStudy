#include <iostream>

using namespace std;

int arr[13];

int Solve(int x)
{
    if (x > 3)
    {
        return Solve(x - 3) + Solve(x - 2) + Solve(x - 1);
    }
    else
    {
        return arr[x];
    }
}

int main()
{
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int x;
        cin >> x;
        cout << Solve(x) << '\n';
    }
}