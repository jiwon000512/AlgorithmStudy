#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

#define MAX 101
void checkSpace(int x, int y);


int field[MAX][MAX];
pair<int, int> moveDelta[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<pair<int, int>> cheese;
set<pair<int, int>> removeCheese;
set<pair<int, int>> innerSpace;
int n, m;

void solution(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + moveDelta[i].first;
        int nextY = y + moveDelta[i].second;

        if (nextX >= n || nextX < 0 || nextY >= m || nextY < 0)
            continue;

        if (field[nextX][nextY] == 0 && innerSpace.find({nextX, nextY}) == innerSpace.end())
            count++;
        if (count == 2)
            break;
    }

    if (count >= 2)
    {
        removeCheese.insert({x, y});
    }
}

bool visited[MAX][MAX];
void findInnerSpaces()
{
    innerSpace.clear();
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && field[i][j] == 0)
            {
                checkSpace(i, j);
            }
        }
    }
}

void checkSpace(int x, int y)
{
    bool isInnerSpace = true;
    set<pair<int, int>> tempSet;
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    tempSet.insert({x,y});
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;

        if (curX == 0 || curY == 0 || curX == n - 1 || curY == m - 1)
        {
            isInnerSpace = false;
        }
            
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + moveDelta[i].first;
            int nextY = curY + moveDelta[i].second;
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;
            if (visited[nextX][nextY])
                continue;
            if (field[nextX][nextY] == 1)
                continue;

            q.push({nextX, nextY});
            tempSet.insert({nextX, nextY});
            visited[nextX][nextY] = true;
        }
    }

    if (isInnerSpace)
    {
        for (auto temp : tempSet)
        {
            innerSpace.insert(temp);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 1)
                cheese.insert({i, j});
        }
    }

    int count = 0;
    while (!cheese.empty())
    {
        findInnerSpaces();
        for (auto p : cheese)
        {
            solution(p.first, p.second);
        }

        for (auto remove : removeCheese)
        {
            cheese.erase(remove);
            field[remove.first][remove.second] = 0;
        }
        removeCheese.clear();
        count++;
    }

    cout << count << '\n';
}