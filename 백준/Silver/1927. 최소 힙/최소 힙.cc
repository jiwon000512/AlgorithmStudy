#include <iostream>
#include <queue>

using namespace std;

int N, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (x == 0)
        {
            if (q.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
        {
            q.push(x);
        }
    }
}