#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int deltaX[4] = {0, 1, 0, -1};
int deltaY[4] = {1, 0, -1, 0};

int N;
int answer;
char color[101][101];
bool visited[101][101];

void solve(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int dX = x + deltaX[i];
        int dY = y + deltaY[i];

        if (dX < 0 || dY < 0 || dX >= N || dY >= N || visited[dX][dY])
            continue;

        if(color[dX][dY] == color[x][y])
            solve(dX, dY);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> color[i][j];
        }
    }

    int answer1 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                solve(i, j);
                answer1++;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (color[i][j] == 'R')
                color[i][j] = 'G';
        }
    }

    int answer2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                solve(i, j);
                answer2++;
            }
        }
    }

    cout << answer1 << ' ' << answer2 << '\n';
}