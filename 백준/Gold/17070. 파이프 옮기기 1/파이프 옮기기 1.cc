#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, answer;
vector<vector<int>> v;
map<int, pair<int, int>> dir = {{0, {0, 1}}, {1, {1, 1}}, {2, {1, 0}}};

bool canGo(int x, int y, int curDir)
{
    int searchX = x + dir[curDir].first;
    int searchY = y + dir[curDir].second;

    if (searchX >= n || searchY >= n)
        return false;

    if (v[searchX][searchY] == 1)
        return false;

    if (curDir == 1)
    {
        if (!canGo(x, y, 0) || !canGo(x, y, 2))
            return false;
    }
    return true;
}

void find(int x, int y, int curDir)
{
    int endX = x + dir[curDir].first;
    int endY = y + dir[curDir].second;

    if (endX == n - 1 && endY == n - 1)
    {
        answer++;
        return;
    }

    if (v[endX][endY] == 1)
    {
        return;
    }

    switch (curDir)
    {
    case 0:
    {
        if (canGo(endX, endY, 0))
        {
            find(endX, endY, 0);
        }
        if (canGo(endX, endY, 1))
        {
            find(endX, endY, 1);
        }
        break;
    }
    case 1:
    {
        if (canGo(endX, endY, 0))
        {
            find(endX, endY, 0);
        }
        if (canGo(endX, endY, 1))
        {
            find(endX, endY, 1);
        }
        if (canGo(endX, endY, 2))
        {
            find(endX, endY, 2);
        }
        break;
    }
    case 2:
    {
        if (canGo(endX, endY, 1))
        {
            find(endX, endY, 1);
        }
        if (canGo(endX, endY, 2))
        {
            find(endX, endY, 2);
        }
        break;
    }
    }
}

int main()
{
    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    find(0, 0, 0);
    cout << answer << '\n';
}
