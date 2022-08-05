#include <iostream>
#include <queue>

using namespace std;

#define SIZE 1001

bool link[SIZE][SIZE] = {
    false,
};
bool visited[SIZE] = {
    false,
};

int n, m, v;

void dfs(int v)
{
    visited[v] = true;
    cout << v << ' ';
    for (int i = 0; i < n + 1; i++)
    {
        if (link[v][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);
    
    while(!q.empty())
    {
        int x = q.front();
        cout << q.front() << ' ';
        q.pop();

        for(int i=0; i<n+1; i++)
        {
            if(link[x][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }


    }
}

int main()
{
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        link[start][end] = true;
        link[end][start] = true;
    }

    dfs(v);
    for (int i = 0; i < n + 1; i++)
        visited[i] = false;

    cout << '\n';

    bfs(v);
}