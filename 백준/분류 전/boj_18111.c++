#include <iostream>
#include <vector>

using namespace std;

int n, m, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> b;
    vector<vector<int>> g;
    int high = -1;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int in;
            cin >> in;
            tmp.push_back(in);
            if (tmp.back() > high)
            {
                high = tmp.back();
            }
        }
        g.push_back(tmp);
    }

    int goal = high, time = 1e9+1, pretime, anstime = 0, ansb = 0 , b2 = b;

    while (goal >= 0)
    {
        b = b2;
        int needB = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                needB += goal - g[i][j];
            }
        }
        if (needB > b)
        {
            goal--;
            continue;
        }
    
        pretime = time;
        time = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] > goal)
                {
                    time += 2 * (g[i][j] - goal);
                    b += g[i][j] - goal;
                }
                else if (g[i][j] < goal)
                {
                    time += goal - g[i][j];
                    b -= goal - g[i][j];
                }
            }
        }

        if (time < pretime)
        {
            anstime = time;
            ansb = goal;
        }

        goal--;
    }

    cout << anstime << ' ' << ansb << '\n';
}