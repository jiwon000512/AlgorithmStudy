#include <iostream>
#include <vector>

using namespace std;

int r, c;
vector<vector<char>> v;
pair<int, int> dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[26];
int answer;

void findPath(int x, int y, int count)
{
    bool isEnd = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dir[i].first;
        int nextY = y + dir[i].second;

        if (nextX < 0 || nextY < 0 || nextX >= r || nextY >= c)
            continue;
        int index = v[nextX][nextY] - 'A';
        
        if (visited[index])
            continue;

        isEnd = false;
        visited[index] = true;
        findPath(nextX, nextY, count + 1);
        visited[index] = false;
    }

    if (isEnd)
    {
        if (answer < count)
            answer = count;
    }
}

int main()
{
    cin >> r >> c;

    v = vector<vector<char>>(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }

    visited[v[0][0] - 'A'] = true;
    findPath(0, 0, 1);

    cout << answer << '\n';
}
