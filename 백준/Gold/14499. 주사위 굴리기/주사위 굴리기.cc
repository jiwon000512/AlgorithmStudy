#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> map;
vector<int> commands;

vector<int> dice(6);

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void rollDice(int dir)
{
    int temp;
    if (dir == 1)
    {
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    else if (dir == 2)
    {
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
    else if (dir == 3)
    {
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }
    else if (dir == 4)
    {
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
}

int main()
{
    cin >> n >> m >> x >> y >> k;

    map.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    commands.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> commands[i];
    }

    for (int i = 0; i < k; i++)
    {
        int dir = commands[i];
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        x = nx;
        y = ny;

        rollDice(dir);

        if (map[x][y] == 0)
        {
            map[x][y] = dice[1];
        }
        else
        {
            dice[1] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }
}
