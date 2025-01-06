#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MIN -10

using namespace std;

int n, m;
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> visited;
vector<vector<char>> board;
vector<vector<int>> memo;

int dp(int x, int y)
{
    if (memo[x][y] != MIN)
    {
        return memo[x][y];
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int curValue = board[x][y] - '0';
        int nextX = x + dir[i].first * curValue;
        int nextY = y + dir[i].second * curValue;

        if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
            continue;
        if(visited[nextX][nextY] == true)
        {
            cout << -1 << '\n';
            exit(0);
        }
        if (board[nextX][nextY] == 'H')
            continue;

        memo[x][y] = max(memo[x][y], dp(nextX, nextY) + 1);
    }

    if (memo[x][y] == MIN)
        memo[x][y] = 1;

    visited[x][y] = false;
    return memo[x][y];
}

int main()
{
    cin >> n >> m;
    board.resize(n);

    memo.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++)
    {
        memo[i].resize(m);
        fill(memo[i].begin(), memo[i].end(), MIN);

        visited[i].resize(m);
    }

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            board[i].push_back(line[j]);
        }
    }

    int value = dp(0, 0);

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (memo[i][j] > answer)
                answer = memo[i][j];
        }
    }

    cout << answer << '\n';
}