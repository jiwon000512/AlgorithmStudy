#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1001

int t, n, k, w;

int buildTime[MAX];
vector<vector<int>> startToEnd;
vector<int> needCount;
vector<int> timeArray;

int getTime(int target)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (needCount[i] == 0)
        {
            q.push(i);
            timeArray[i] = buildTime[i];
        }
    }

    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        for (int i = 0; i < startToEnd[target].size(); i++)
        {
            int next = startToEnd[target][i];
            needCount[next]--;
            timeArray[next] = max(timeArray[next], timeArray[target] + buildTime[next]);

            if (needCount[next] == 0)
                q.push(next);
        }
    }

    return timeArray[w];
}

int main()
{
    cin >> t;

    while (t-- > 0)
    {
        cin >> n >> k;
        startToEnd.clear();
        startToEnd.resize(n + 1);
        needCount.clear();
        needCount.resize(n + 1);
        timeArray.clear();
        timeArray.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> buildTime[i];

        int start, end;
        for (int i = 0; i < k; i++)
        {
            cin >> start >> end;
            startToEnd[start].push_back(end);
            needCount[end]++;
        }

        cin >> w;
        cout << getTime(w) << '\n';
    }
}