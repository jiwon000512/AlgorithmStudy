#include <iostream>

using namespace std;

int w, h;
int caseX[4] = {0, 0, 1, -1};
int caseY[4] = {1, -1, 0, 0};

int field[50][50];
bool visited[50][50];

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + caseX[i];
        int nextX = x + caseY[i];

        if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
        {
            continue;
        }

        if (field[nextX][nextY] == 1 && !visited[nextX][nextY])
        {
            dfs(nextX, nextY);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int poscnt;

        cin >> w >> h >> poscnt;

        fill(&field[0][0], &field[w - 1][h - 1], 0);
        fill(&visited[0][0], &visited[w - 1][h - 1], false);

        for (int j = 0; j < poscnt; j++)
        {
            pair<int, int> tmp;
            cin >> tmp.first >> tmp.second;
            field[tmp.first][tmp.second] = 1;
        }

        int ans = 0;

        for (int m = 0; m < w; m++)
        {
            for (int n = 0; n < h; n++)
            {
                if (field[m][n] == 1 && !visited[m][n])
                {
                    ans++;
                    dfs(m, n);
                }
            }
        }

        cout << ans << '\n';
    }
}