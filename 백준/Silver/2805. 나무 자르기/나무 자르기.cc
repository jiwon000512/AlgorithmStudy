#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, high = 0, low = 0, mid;
    long long sum;
    vector<int> v;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;

        if (in > high)
        {
            high = in;
        }

        v.push_back(in);
    }

    do
    {
        sum = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < n; i++)
        {
            if (v[i] - mid > 0)
            {
                sum += v[i] - mid;
            }
        }

        if (sum >= m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    } while (mid != (high + low) / 2);

    cout << mid << '\n';
}