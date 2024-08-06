#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, H;
int box[101][101][101] = {0};
vector<vector<int>> direction = {{0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}};
queue<vector<int>> q;

void bfs()
{
    int m, n, h;
    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        h = v[0];
        n = v[1];
        m = v[2];
        for (int i = 0; i < direction.size(); i++)
        {
            int nextM = m + direction[i][0];
            int nextN = n + direction[i][1];
            int nextH = h + direction[i][2];

            if (nextM >= M || nextN >= N || nextH >= H || nextM < 0 || nextN < 0 || nextH < 0)
            {
                continue;
            }

            if (box[nextH][nextN][nextM] != 0)
            {
                continue;
            }
            box[nextH][nextN][nextM] = box[h][n][m] + 1;
            vector<int> vec{nextH, nextN, nextM};
            q.push(vec);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    bool alreadyFinished = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 0)
                {
                    alreadyFinished = false;
                }
                else if (box[i][j][k] == 1)
                {
                    vector<int> v{i, j, k};
                    q.push(v);
                }
            }
        }
    }

    if (alreadyFinished)
    {
        cout << 0 << '\n';
        return 0;
    }

    bfs();

    int day = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (box[i][j][k] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }

                if (day < box[i][j][k])
                {
                    day = box[i][j][k];
                }
            }
        }
    }

    cout << day - 1 << '\n';
}