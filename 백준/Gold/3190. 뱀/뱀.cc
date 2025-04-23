#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> direction[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> v;
char command[10001];
int n, k;

queue<pair<int, int>> body;
int answer;

void dummy(int x, int y, int dir)
{
    while (true)
    {
        if (x < 1 || y < 1 || x > n || y > n || v[x][y] == 2)
            return;
        answer++;
        if (v[x][y] != 1 && !body.empty())
        {
            v[body.front().first][body.front().second] = 0;
            body.pop();
        }
        v[x][y] = 2;
        body.push({x, y});

        int nextDir;
        nextDir = dir;
        x = x + direction[nextDir].first;
        y = y + direction[nextDir].second;
        if (command[answer] == 'L')
        {
            nextDir = (dir + 3) % 4;
        }
        else if (command[answer] == 'D')
        {
            nextDir = (dir + 1) % 4;
        }
        
        dir = nextDir;
    }
}

int main()
{
    cin >> n >> k;
    v.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }

    int l;
    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int tmp;
        char dir;
        cin >> tmp >> dir;
        command[tmp] = dir;
    }
    
    dummy(1, 1, 1);
    cout << answer << '\n';
}
