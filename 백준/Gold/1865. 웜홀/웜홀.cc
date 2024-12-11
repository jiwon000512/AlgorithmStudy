#include <iostream>
#include <vector>

using namespace std;

#define MAX 999999999

int tc, n, m, w;

struct path
{
    int s;
    int e;
    int t;
};

int main()
{
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> n >> m >> w;
        vector<path> paths;
        vector<int> dist = vector<int>(n + 1, MAX);

        int s, e, t;
        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            paths.push_back({s, e, t});
            paths.push_back({e, s, t});
        }

        for (int k = 0; k < w; k++)
        {
            cin >> s >> e >> t;
            paths.push_back({s, e, -t});
        }

        dist[1] = 0;
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < paths.size(); k++)
            {
                int start = paths[k].s;
                int end = paths[k].e;
                int time = paths[k].t;

                if (dist[start] + time < dist[end])
                    dist[end] = dist[start] + time;
            }
        }

        bool yes = false;
        for (int j = 0; j < paths.size(); j++)
        {
            int start = paths[j].s;
            int end = paths[j].e;
            int time = paths[j].t;

            if (dist[start] + time < dist[end])
            {
                yes = true;
                break;
            }
        }

        if (yes)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}