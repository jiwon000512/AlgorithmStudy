#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visited[10000];
string answer;
int A;
int B;

int D(int target)
{
    return target * 2 % 10000;
}

int S(int target)
{
    if (target == 0)
        return 9999;
    else
        return target - 1;
}

int L(int target)
{
    return (target % 1000) * 10 + (target / 1000);
}

int R(int target)
{
    return target / 10 + (target % 10) * 1000;
}

void bfs()
{
    queue<pair<int, string>> q;
    q.push({A, ""});
    while (!q.empty())
    {
        int current = q.front().first;
        string command = q.front().second;
        q.pop();

        if (current == B)
        {
            answer = command;
            break;
        }

        int d = D(current);
        int s = S(current);
        int l = L(current);
        int r = R(current);
        
        if(!visited[d])
        {
            visited[d] = true;
            q.push({d, command + "D"});
        }
        if(!visited[s])
        {
            visited[s] = true;
            q.push({s, command + "S"});
        }
        if(!visited[l])
        {
            visited[l] = true;
            q.push({l, command + "L"});
        }
        if(!visited[r])
        {
            visited[r] = true;
            q.push({r, command + "R"});
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(visited, false, sizeof(visited));
        cin >> A >> B;
        bfs();
        cout << answer << '\n';
    }
}