#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX 1001

int n, m;
int map[MAX][MAX];
int moveDeltaX[4] = {1, 0, -1, 0};
int moveDeltaY[4] = {0, 1, 0, -1};
bool visited[MAX][MAX][2];
int answer = -1;

struct info
{
    int curX;
    int curY;
    bool breakWall;
    int value;
};

void go()
{
    queue<info> q;

    visited[1][1][0] = true;
    visited[1][1][1] = true;
    q.push({1, 1, false, 1});

    while (!q.empty())
    {
        info info = q.front();

        if (info.curX == n && info.curY == m)
        {
            answer = info.value;
            return;
        }

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = info.curX + moveDeltaX[i];
            int nextY = info.curY + moveDeltaY[i];

            if (visited[nextX][nextY][info.breakWall] == true)
                continue;
            if (nextX < 1 || nextY < 1 || nextX > n || nextY > m)
                continue;
            if (map[nextX][nextY] == 1 && info.breakWall == true)
                continue;

            q.push({nextX, nextY, map[nextX][nextY] == 1 || info.breakWall, info.value + 1});
            visited[nextX][nextY][map[nextX][nextY] == 1 || info.breakWall] = true;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        int j = 1;
        for (char ch : line)
        {
            int num = ch - '0';
            map[i][j] = num;
            j++;
        }
    }

    go();

    cout << answer << '\n';
}