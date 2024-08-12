#include <iostream>

using namespace std;

int N, M;
int arr[501][501] = {0};
bool visited[501][501] = {false};
int deltaX[4] = {0, 1, 0, -1};
int deltaY[4] = {1, 0, -1, 0};

int answer = 0;
int answer2 = 0;

void dfs(int x, int y, int depth, int sum)
{
    if (depth == 4)
    {
        if (answer < sum)
            answer = sum;
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + deltaX[i];
        int nextY = y + deltaY[i];

        if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M || visited[nextX][nextY] == true)
            continue;

        dfs(nextX, nextY, depth + 1, sum + arr[nextX][nextY]);
    }

    visited[x][y] = false;
}

void other(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int sum = arr[x][y];
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;
            int nextX = x + deltaX[j];
            int nextY = y + deltaY[j];
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
                continue;
            sum += arr[nextX][nextY];
        }
        if (answer2 < sum)
            answer2 = sum;   
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            answer = 0;
            dfs(i, j, 1, arr[i][j]);
            if (max < answer)
                max = answer;

            answer2 = 0;
            other(i, j);
            if (max < answer2)
                max = answer2;
        }
    }

    cout << max << '\n';
}