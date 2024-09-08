#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int n, m, answer = -1;
int dist[101][14];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int closed[13];
set<int> s;

int getMinDist(int houseNum)
{
    int minDist = -1;
    for (int i = 0; i < chicken.size(); i++)
    {
        if (s.find(i) == s.end())
            continue;

        if (dist[houseNum][i] < minDist || minDist == -1)
            minDist = dist[houseNum][i];
    }

    return minDist;
}

void solve()
{
    s.clear();
    for (int i = 0; i < m; i++)
    {
        s.insert(closed[i]);
    }

    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        sum += getMinDist(i);
    }

    if (sum < answer || answer == -1)
        answer = sum;
}

void combination(int depth, int next)
{
    if (depth == m)
    {
        solve();
        return;
    }

    for (int i = next; i < chicken.size(); i++)
    {
        closed[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 2)
                chicken.push_back({i, j});
            else if (x == 1)
                house.push_back({i, j});
        }
    }

    for (int i = 0; i < house.size(); i++)
    {
        int x = house[i].first;
        int y = house[i].second;
        for (int j = 0; j < chicken.size(); j++)
        {
            int cX = chicken[j].first;
            int cY = chicken[j].second;
            dist[i][j] = abs(x - cX) + abs(y - cY);
        }
    }

    combination(0, 0);
    cout << answer << '\n';
}