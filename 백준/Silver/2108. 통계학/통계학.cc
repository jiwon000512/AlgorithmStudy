#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void avg(int *arr, int n)
{
    int sum = 0;
    int avg;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = round((float)sum /n);

    cout << avg << '\n';
}

void median(int *arr, int n)
{
    sort(arr, arr + n);
    cout << arr[n / 2] << '\n';
}

void mode(int *arr, int n)
{
    int cnt[8001] = {
        0,
    };
    bool first = false;
    int max = 0, maxcnt = -1;

    for (int i = 0; i < n; i++)
    {
        cnt[arr[i] + 4000]++;
    }

    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }
        if (cnt[i] > maxcnt)
        {
            maxcnt = cnt[i];
            max = i - 4000;
            first = true;
        }
        else if (cnt[i] == maxcnt)
        {
            if (first)
            {
                max = i - 4000;
                first = false;
            }
        }
    }

    cout << max << '\n';
}

void range(int *arr, int n)
{
    sort(arr, arr + n);
    cout << arr[n - 1] - arr[0] << '\n';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    avg(arr, n);
    median(arr, n);
    mode(arr, n);
    range(arr, n);
}
