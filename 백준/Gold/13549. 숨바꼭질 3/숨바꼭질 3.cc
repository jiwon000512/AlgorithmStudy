#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
int n, k;

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, n});
    visited[n] = true;
    while (!q.empty())
    {
        int x = q.top().second;
        int xTime = q.top().first;
        q.pop();

        if (x == k)
        {
            cout << xTime << '\n';
            return;
        }

        if (x * 2 < 100001 && !visited[x * 2])
        {
            q.push({xTime, x * 2});
            visited[x * 2] = true;
        }

        if (x - 1 >= 0 && !visited[x - 1])
        {
            q.push({xTime + 1, x - 1});
            visited[x - 1] = true;
        }

        if (x + 1 < 100001 && !visited[x + 1])
        {
            q.push({xTime + 1, x + 1});
            visited[x + 1] = true;
        }
    }
}

int main()
{
    cin >> n >> k;
    solve();
}