#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, sharkSize = 2, eatCount;
pair<int, int> direction[] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
vector<vector<int>> v;

int answer = 0;

int main()
{
    cin >> n;
    v.resize(n, vector<int>(n));

    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 9)
            {
                x = i;
                y = j;
                v[i][j] = 0;
            }
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    vector<vector<int>> visited = vector<vector<int>>(n, vector<int>(n));
    q.push({0, x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        auto [distance, tempX, tempY] = q.top();
        q.pop();

        if (v[tempX][tempY] != 0 && v[tempX][tempY] < sharkSize)
        {
            v[tempX][tempY] = 0;
            answer += distance;
            eatCount++;
            if (eatCount == sharkSize)
            {
                sharkSize++;
                eatCount = 0;
            }

            while (!q.empty())
                q.pop();
            visited = vector<vector<int>>(n, vector<int>(n));
            q.push({0, tempX, tempY});
            visited[tempX][tempY] = true;

            continue;
        }

    for (int i = 0; i < 4; i++)
    {
        int nextX = tempX + direction[i].first;
        int nextY = tempY + direction[i].second;

        if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n || visited[nextX][nextY])
            continue;

        if (v[nextX][nextY] <= sharkSize)
        {
            q.push({distance + 1, nextX, nextY});
            visited[nextX][nextY] = true;
        }
    }
}

cout << answer << '\n';
}
