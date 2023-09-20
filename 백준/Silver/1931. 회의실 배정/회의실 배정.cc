#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> t;

void Solve()
{
    int ans = 1;
    int idx = 0;

    for (int i = 1; i < N; i++)
    {
        if (t[i].second >= t[idx].first)
        {
            ans++;
            idx = i;
        }
    }

    cout << ans << '\n';
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s, e;

        cin >> s >> e;
        t.push_back(pair(e, s));
    }

    sort(t.begin(), t.end());

    Solve();
}