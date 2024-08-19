#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int V, maxValue, targetNode;
vector<pair<int, int>> tree[100001];
bool visited[100001];

void dfs(int x, int value)
{
    if (maxValue < value)
    {
        maxValue = value;
        targetNode = x;
    }

    for (int i = 0; i < tree[x].size(); i++)
    {
        int nextX = tree[x][i].first;
        int cost = tree[x][i].second;
        if (!visited[nextX])
        {
            visited[nextX] = true;
            dfs(nextX, value + cost);
            visited[nextX] = false;
        }
    }
}

int main()
{
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        int node, target, value;
        cin >> node;
        while (true)
        {
            cin >> target;
            if (target == -1)
                break;
            cin >> value;

            tree[node].push_back({target, value});
        }
    }

    visited[1] = true;
    dfs(1, 0);
    maxValue = 0;
    memset(visited, false, V);
    visited[targetNode] = true;
    dfs(targetNode, 0);

    cout << maxValue << '\n';
}