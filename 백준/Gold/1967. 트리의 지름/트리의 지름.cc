#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> nodes(10001);

int maxValue;
int maxNode;

void getFarthestNode(int node)
{
    queue<int> q;
    int values[n + 1];
    bool visited[n + 1];
    memset(values, 0, sizeof(values) / sizeof(int));
    memset(visited, false, sizeof(visited) / sizeof(bool));
    visited[node] = true;
    values[node] = 0;
    q.push(node);
    while (q.empty() == false)
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < nodes[current].size(); i++)
        {
            int next = nodes[current][i].first;
            int nextValue = nodes[current][i].second;
            if (visited[next] == false)
            {
                values[next] = values[current] + nextValue;
                visited[next] = true;
                q.push(next);

                if (maxValue < values[next])
                {
                    maxValue = values[next];
                    maxNode = next;
                }
            }
        }
    }
}

int main()
{
    cin >> n;

    int parent, child, value;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> parent >> child >> value;
        nodes[parent].push_back({child, value});
        nodes[child].push_back({parent, value});
    }

    getFarthestNode(1);
    getFarthestNode(maxNode);
    cout << maxValue << '\n';
}