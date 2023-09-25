#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, ans;
int field[1001][1001];
queue<pair<int, int>> q;

int xDelta[4] = {-1, 0, 1, 0};
int yDelta[4] = {0, 1, 0, -1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + xDelta[i];
            int ny = y + yDelta[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (field[nx][ny] == 0)
                {
                    field[nx][ny] = field[x][y] + 1;
                    q.push(pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];

            if (field[i][j] == 1)
            {
                q.push(pair(i, j));
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(field[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
            if(field[i][j] > ans)
            {
                ans = field[i][j];
            }
        }
    }

    cout << ans-1 << '\n';
}