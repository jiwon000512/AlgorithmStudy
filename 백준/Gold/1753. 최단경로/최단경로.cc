#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 9999999
using namespace std;

int v, e, k;
vector<pair<int, int>> edge[20001];
int cost[20001];

void dij(int target)
{
    memset(cost, INF, sizeof(cost));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    cost[target] = 0;
    q.push({0, target});

    while (!q.empty())
    {
        int current = q.top().second;
        int c = q.top().first;
        q.pop();
        for (int i = 0; i < edge[current].size(); i++)
        {
            int next = edge[current][i].first;
            int nextC = c + edge[current][i].second;

            if(nextC < cost[next])
            {
                cost[next] = nextC;
                q.push({nextC, next});
            }
        }
    }
}

int main()
{
    cin >> v >> e >> k;

    int x, y, c;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> c;
        edge[x].push_back({y, c});
    }

    dij(k);

    for (int i = 1; i <= v; i++)
    {
        if (cost[i] >= INF)
            cout << "INF";
        else
            cout << cost[i];
        cout << '\n';
    }
}