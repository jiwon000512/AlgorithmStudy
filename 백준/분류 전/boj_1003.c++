#include <iostream>

using namespace std;

long long arr[50] = {
    0,
    1,
};
long long fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return arr[n];
    }
    else if(arr[n] == 0)
    {
        arr[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return arr[n];
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << "1 0" << '\n';
        }
        else
        {
            cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n';
        }
    }
}