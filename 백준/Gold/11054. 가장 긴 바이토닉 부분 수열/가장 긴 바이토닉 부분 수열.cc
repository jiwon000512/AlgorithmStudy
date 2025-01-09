#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> inc(n, 1); // 증가하는 부분 수열의 길이
    vector<int> dec(n, 1); // 감소하는 부분 수열의 길이

    // 증가하는 부분 수열 계산
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && inc[i] < inc[j] + 1)
            {
                inc[i] = inc[j] + 1;
            }
        }
    }

    // 감소하는 부분 수열 계산
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[i] > v[j] && dec[i] < dec[j] + 1)
            {
                dec[i] = dec[j] + 1;
            }
        }
    }

    // 가장 긴 바이토닉 수열의 길이 계산
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    cout << ans << endl;
    return 0;
}