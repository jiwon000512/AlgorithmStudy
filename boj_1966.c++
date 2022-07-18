#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        pair <int,int> p;
        int m, n, ans = 1;
        cin >> n >> m;

        for (int j = 0; j < n; j++)
        {
            cin >> p.first;
            p.second = j;
            q.push(p);
            pq.push(p.first);
        }

        while(!q.empty())
        {
            pair<int,int> test = q.front();
            if(test.first < pq.top())
            {
                q.pop();
                q.push(test);
            }
            else
            {
                if(test.second == m)
                {
                    break;
                }
                else
                {
                    q.pop();
                    pq.pop();
                    ans ++;
                }
            }
        }
        cout << ans << '\n';
    }
}