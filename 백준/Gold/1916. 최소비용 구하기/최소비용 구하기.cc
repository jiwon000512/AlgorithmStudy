#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 999999

using namespace std;

vector<pair<int, int>> bus[1001];
int n, m, start, target;
int cost[1001];

void dij()
{
    memset(cost, INF, sizeof(int) * (n + 1));
    cost[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});

    while (!q.empty())
    {
        int current = q.top().second;
        int currentCost = q.top().first;

        if(current == target)
        {
            cout << cost[target] << '\n';
            return;
        }

        q.pop();

        for (int i = 0; i < bus[current].size(); i++)
        {
            int next = bus[current][i].first;
            int nextCost = bus[current][i].second + currentCost;
            if (nextCost < cost[next])
            {
                cost[next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int x, y, c;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> c;
        bus[x].push_back({y, c});
    }

    cin >> start >> target;

    dij();
}