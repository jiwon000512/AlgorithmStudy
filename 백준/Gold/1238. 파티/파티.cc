#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 9999999
using namespace std;

int N, M, X, result;
vector<pair<int,int>> map[1002];
int cost[1002];

void solve(int start, int target)
{
    memset(cost, INF, sizeof(cost));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    cost[start] = 0;
    while (!q.empty())
    {
        int currentTarget = q.top().second;
        int currentCost = q.top().first;
        q.pop();
        if (currentTarget == target)
        {
            result = cost[target];
            break;
        }
        for (int i = 0; i < map[currentTarget].size(); i++)
        {
            int nextTarget = map[currentTarget][i].first;
            int nextCost = map[currentTarget][i].second + currentCost;
            
            if (cost[nextTarget] > nextCost)
            {
                cost[nextTarget] = nextCost;
                q.push({nextCost, nextTarget});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        map[x].push_back({y, cost});
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        int temp = 0;
        solve(i, X);
        temp += result;
        solve(X, i);
        temp += result;

        if(temp > max)
            max = temp;
    }

    cout << max << '\n';
}