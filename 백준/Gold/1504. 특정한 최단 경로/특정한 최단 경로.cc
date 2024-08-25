#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 9999999
using namespace std;

int n, e;
vector<pair<int, int>> edge[801];
int costArray[801];

void dij(int start)
{
    memset(costArray, INF, (n + 1) * sizeof(int));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    costArray[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        int target = q.top().second;
        int cost = q.top().first;
        q.pop();

        for (int i = 0; i < edge[target].size(); i++)
        {
            int next = edge[target][i].first;
            int nextCost = cost + edge[target][i].second;

            if(nextCost < costArray[next])
            {
                costArray[next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }
}

int main()
{
    cin >> n >> e;

    int x, y, cost;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> cost;

        edge[x].push_back({y, cost});
        edge[y].push_back({x, cost});
    }
    
    int v1, v2;
    cin >> v1 >> v2;


    dij(1);
    int costV1 = costArray[v1];
    int costV2 = costArray[v2]; 
    dij(v1);
    int costV1ToV2 = costArray[v2];
    int costV1ToN = costArray[n];
    dij(v2);
    int costV2ToV1 = costArray[v1];
    int costV2ToN = costArray[n];

    int answer1 = costV1 + costV1ToV2 + costV2ToN;
    int answer2 = costV2 + costV2ToV1 + costV1ToN;
    int answer = answer1 < answer2 ? answer1 : answer2;

    if(INF < answer)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
}