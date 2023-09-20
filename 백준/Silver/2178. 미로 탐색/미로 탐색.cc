#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maze[100][100];
int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve()
{
    queue<pair<int, int>> q;
    q.push(pair(0, 0));

    while (!q.empty())
    {
        int i, j;
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int dI,dJ;
            dI = i + delta[k][0];
            dJ = j + delta[k][1];
            if(dI>=0 && dJ>=0 && dI<100 && dJ<100)
            {
                if(maze[dI][dJ]==1)
                {
                    q.push(pair(dI,dJ));
                    maze[dI][dJ] = maze[i][j] + 1;
                }
            }
        }
    }

    cout << maze[N-1][M-1] << '\n';
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = row[j] - '0';
        }
    }

    Solve();
}