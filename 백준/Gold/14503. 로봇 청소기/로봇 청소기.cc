#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
pair<int, int> direction[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int answer = 0;

bool isStop(int x, int y, int dir)
{
    int backX = x - direction[dir].first;
    int backY = y - direction[dir].second;
    return (backX < 0 || backY < 0 || backX >= n || backY >= m || v[backX][backY] == 1);
}

void clean(int x, int y, int dir)
{
    if (v[x][y] == 0)
    {
        v[x][y] = 2;
        answer++;
    }

    int tempDir = dir;
    for (int i = 0; i < 4; i++)
    {
        tempDir = (tempDir + 3) % 4;
        int nextX = x + direction[tempDir].first;
        int nextY = y + direction[tempDir].second;

        if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && v[nextX][nextY] == 0)
        {
            clean(nextX, nextY, tempDir);
            return;
        }
    }

    if (!isStop(x, y, dir))
    {
        clean(x - direction[dir].first, y - direction[dir].second, dir);
    }
}

int main()
{
    cin >> n >> m;

    int currentX, currentY, currentDir;
    cin >> currentX >> currentY >> currentDir;

    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    clean(currentX, currentY, currentDir);

    cout << answer << '\n';
}
