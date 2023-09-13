#include <iostream>
#include <queue>

using namespace std;

int N, K;
int t[100001];

void Solve()
{
    queue<int> q;

    q.push(N);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == K)
        {
            cout << t[x] << '\n';
            break;
        }

        if (x - 1 >= 0 && t[x - 1] == 0)
        {
            t[x - 1] = t[x] + 1;
            q.push(x - 1);
        }
        if (x + 1 < 100001 && t[x + 1] == 0)
        {
            t[x + 1] = t[x] + 1;
            q.push(x + 1);
        }
        if (2 * x < 100001 && t[2 * x] == 0)
        {
            t[2 * x] = t[x] + 1;
            q.push(2 * x);
        }
    }
}

int main()
{
    cin >> N >> K;
    Solve();
}