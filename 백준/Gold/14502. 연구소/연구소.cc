#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int maxCount = 0;

void findSafeArea(vector<vector<int>> temp)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                count++;
            }
        }
    }

    if(maxCount < count)
    {
        maxCount = count;
    }
}

void spread(vector<vector<int>> &temp)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];

            if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
                continue;
            if(temp[nextX][nextY] == 0)
            {
                temp[nextX][nextY] = 2;
                q.push({nextX, nextY});
            }
        }
    }
}

void dfs(int wallCount)
{
    if (wallCount == 3)
    {
        vector<vector<int>> temp = v;
        spread(temp);
        findSafeArea(temp);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 0)
                {
                    v[i][j] = 1;
                    dfs(wallCount + 1);
                    v[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    dfs(0);

    cout << maxCount << '\n';
}