#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> ansV;

int N, ans, cnt;
int arr[26][26];
bool visited[26][26];

int xDelta[4] = {-1, 0, 1, 0};
int yDelta[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    ans++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + xDelta[i];
        int nextY = y + yDelta[i];

        if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < N)
        {
            if (!visited[nextX][nextY] && arr[nextX][nextY] == 1)
            {
                dfs(nextX, nextY);
            }
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j);
                ansV.push_back(ans);
                ans = 0;
                cnt++;
            }
        }
    }

    sort(ansV.begin(), ansV.end());

    cout << cnt << '\n';
    for (int i = 0; i < static_cast<int>(ansV.size()); i++)
    {
        cout << ansV[i] << '\n';
    }
}