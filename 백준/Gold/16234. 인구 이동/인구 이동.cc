#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n, l, r;
vector<vector<int>> v;
pair<int, int> direction[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    cin >> n >> l >> r;
    v = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int day = 0;
    while (true)
    {
        vector<vector<pair<int, int>>> fed;
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (visited[i][j] == false)
                    {
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        vector<pair<int, int>> temp;
                        temp.push_back({i, j});
                        fed.push_back(temp);
                        visited[i][j] = true;
                        while (q.empty() == false)
                        {
                            auto [curX, curY] = q.front();
                            q.pop();
                            for (int k = 0; k < 4; k++)
                            {
                                int searchX = curX + direction[k].first;
                                int searchY = curY + direction[k].second;

                                if (searchX < 0 || searchY < 0 || searchX >= n || searchY >= n || visited[searchX][searchY])
                                    continue;

                                int diff = fabs(v[curX][curY] - v[searchX][searchY]);
                                if (l <= diff && diff <= r)
                                {
                                    q.push({searchX, searchY});
                                    visited[searchX][searchY] = true;
                                    fed[fed.size() - 1].push_back({searchX, searchY});
                                }
                            }
                        }

                        if (fed[fed.size() - 1].size() == 1)
                        {
                            fed.pop_back();
                        }
                    }
                }
            }
        }

        if (fed.size() == 0)
        {
            break;
        }

        for (int i = 0; i < fed.size(); i++)
        {
            int people = 0;
            for (int j = 0; j < fed[i].size(); j++)
            {
                people += v[fed[i][j].first][fed[i][j].second];
            }

            people = people / fed[i].size();
            for (int j = 0; j < fed[i].size(); j++)
            {
                v[fed[i][j].first][fed[i][j].second] = people;
            }
        }

        day++;
    }

    cout << day << '\n';
}
