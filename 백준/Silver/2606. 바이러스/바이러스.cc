#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, ans;
bool visited[101];
vector<int> v[101];

void dfs(int x)
{
    visited[x] = true;
    ans++;
    for (int i = 0; i < static_cast<int>(v[x].size()); i++)
    {
        if (!visited[v[x][i]])
        {
            dfs(v[x][i]);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout << ans - 1 << '\n';
}